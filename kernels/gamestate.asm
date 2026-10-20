# gamestate.asm — Phase-7 closure: INPUT-DRIVEN game state on the Ember core.
#
# The per-frame game loop runs as a KERNEL (not TB Python): read the input
# stream from VRAM, integrate Q16 physics, convert the camera position to
# fp32 bit form, and store it back — the TB copies those exact words into
# the GSX MVP (row0[3] and row3[3]) and renders. Camera position -> pixels
# is RTL end-to-end; the TB only feeds per-frame INPUTS.
#
# Q16 physics (per frame, thread 0 owns the state; 4-way SPMD would race):
#   vel += in*ACC                          (accel toward the input)
#   vel -= sign(vel)*floor(|vel| / 16)     (6.25%/frame decay; terminal 0.4*in)
#   vel = clamp(vel, -VMAX, VMAX)
#   pos += vel
#   pos_x = clamp(pos_x, -PX, PX)          (|cam_x| <= 2.0: no new culls)
#   pos_z = clamp(pos_z, 0, PZ)            (cam_z in [0,1]: no new culls)
# Constants (Q16: 65536 = 1.0): ACC=1638 (0.025/frame^2), decay shift 4
#   (= 6.25%/frame, terminal speed in*0.4 units/frame), VMAX=20.0, PX=2.0,
#   PZ=1.0.  LI spans 20 bits; >=2^16 constants are built as li + shl 16;
#   negatives via SUB from the zero register.
#   WHY magnitude-decay: SHR is LOGICAL, so shifting the SIGNED product
#   (vel*FRC >> 16) is garbage for vel < 0 (it adds ~2^16 of "friction").
#   Instead |v| = maxc(v, -v) is NON-NEGATIVE (logical == arithmetic there),
#   and the sign is re-applied with one branch per axis. Exact mirror in
#   tools/golden/gamestate.py: f = |v| >> 4; v += f if v < 0 else v -= f.
#
# Kernel calling convention (CMDBUF param words):
#   [0]=GS word addr (state)  [1]=GI word addr (inputs)  [2]=cookie
# State block (byte addrs from GS*4):
#   +0 pos_x_q16 +4 pos_z_q16 +8 vel_x_q16 +12 vel_z_q16
#   +16 fp32 cam_x bits +20 fp32 cam_z bits
#   +24 echo word (cookie<<8 | free-running frame counter, low byte)
#   +28 fp32 (3.0 + cam_z) bits   (= MVP row3[3], precomputed on-core)
# Input block (byte addrs from GI*4): +0 ax_in +4 az_in (integer units,
#   sign = direction; 0 = idle; consumed = in * ACC).
#
# RTL facts used (verified against ember_core.sv case table):
#   * SHR is LOGICAL (rav >> rbv[5:0]) — negative-velocity friction is
#     handled by the magnitude form (see the physics block above).
#   * MIN (0x0B) / MAXC (0x0C) are SIGNED compares on raw operands.
#   * LI is zero-extended {16'h0, ra, imm} -> bit31 constants need shl 16.
#   * LD/ST take byte addresses (VRAM_BASE added by HW); params hold WORD
#     addrs -> doubled twice before use.
#   * ONLY CMP sets nzp (cmp does NOT write rd); branches are next-relative;
#     JAL links the CURRENT fpc into rd (r15); JR jumps to rd[7:0]; fpc is
#     8-bit (256-word space; this program is ~120 words).
#
# f2q: r6 = pos_q16 in -> r10 = fp32 bits of (r6 / 65536.0), round-half-up;
#   generic for any |r6| < 2^31 (normalize until bit30 set, s = shifts,
#   exponent field = 141 - s, mantissa = ((N + 64) >> 7) & 0x7FFFFF where
#   N = normalized |r6| in [2^30, 2^31)). Clobbers ONLY r6, r7, r10, r12,
#   r13, r14 (caller state lives in r1..r5, r8, r9, r11). Zero -> 0x0.
#
# Regs: r0=1 r1=GSb r2=GIb r3=cookie r4=pos_x r5=pos_z r6=vel_x->f2q arg
#       r7=vel_z->scratch r8=ZERO r9=prev echo word r10=consts/f2q result
#       r11=az*ACC (persists across the vel_x friction block) r12=param base
#       then scratch r13/r14=work r15=tid->link
    li  %r0, 1
    ld  %r1, [%r12 + 0]         # GS word addr
    ld  %r2, [%r12 + 4]         # GI word addr
    ld  %r3, [%r12 + 8]         # cookie (TB handshake value)
    add %r1, %r1, %r1
    add %r1, %r1, %r1           # GS byte addr
    add %r2, %r2, %r2
    add %r2, %r2, %r2           # GI byte addr
    cmp %r7, %r15, %r0          # nzp = tid - 1: tid=0 -> N, tid>0 -> Z/P
    brnzp zp, done              # threads 1..3 exit; thread 0 owns the state
    sub %r8, %r8, %r8           # r8 = 0
    ld  %r4, [%r1 + 0]          # pos_x
    ld  %r5, [%r1 + 4]          # pos_z
    ld  %r6, [%r1 + 8]          # vel_x
    ld  %r7, [%r1 + 12]         # vel_z
    ld  %r9, [%r1 + 24]         # prev echo word
    ld  %r13, [%r2 + 0]         # ax_in
    ld  %r14, [%r2 + 4]         # az_in
    li  %r10, 1638              # ACC (0.025 in Q16)
    mul %r13, %r13, %r10        # ax*ACC
    mul %r11, %r14, %r10        # az*ACC -> r11 (survives the vel_x block)
    # -- vel_x += ax*ACC, then decay: v -= sign(v)*floor(|v|/16) -----------
    add %r6, %r6, %r13          # vel_x += ax*ACC
    sub %r13, %r8, %r6          # -vel_x
    maxc %r14, %r6, %r13        # |vel_x| (signed max of v, -v)
    li  %r10, 4
    shr %r12, %r14, %r10        # f = |vel_x| >> 4 (logical == arith, |v|>=0)
    cmp %r7, %r6, %r8           # sign of vel_x (r7 scratch here)
    brnzp p, fxp
    add %r6, %r6, %r12          # v < 0: v + f
    brnzp nzp, fxd
fxp:
    sub %r6, %r6, %r12          # v >= 0: v - f
fxd:
    # -- vel_z: same -------------------------------------------------------
    add %r7, %r7, %r11          # vel_z += az*ACC
    sub %r13, %r8, %r7          # -vel_z
    maxc %r14, %r7, %r13        # |vel_z|
    li  %r10, 4
    shr %r12, %r14, %r10        # f = |vel_z| >> 4
    cmp %r7, %r7, %r8           # sign of vel_z
    brnzp p, fzp
    add %r7, %r7, %r12          # v < 0: v + f
    brnzp nzp, fzd
fzp:
    sub %r7, %r7, %r12          # v >= 0: v - f
fzd:
    li  %r12, 20                # VMAX = 20 << 16 (LI tops out at 0xFFFF)
    li  %r10, 16
    shl %r12, %r12, %r10        # +VMAX (0x140000)
    min %r6, %r6, %r12          # vel_x <= +VMAX
    sub %r14, %r8, %r12         # -VMAX
    maxc %r6, %r6, %r14         # vel_x >= -VMAX
    min %r7, %r7, %r12          # vel_z <= +VMAX (r12/r14 unchanged)
    maxc %r7, %r7, %r14         # vel_z >= -VMAX
    add %r4, %r4, %r6           # pos_x += vel_x
    add %r5, %r5, %r7           # pos_z += vel_z
    li  %r12, 2                 # PX = 2 << 16 (r10 still 16)
    shl %r12, %r12, %r10
    min %r4, %r4, %r12          # pos_x <= +PX
    sub %r14, %r8, %r12         # -PX
    maxc %r4, %r4, %r14         # pos_x >= -PX
    li  %r12, 1                 # PZ = 1 << 16
    shl %r12, %r12, %r10
    min %r5, %r5, %r12          # pos_z <= PZ
    maxc %r5, %r5, %r8          # pos_z >= 0
    st  %r4, [%r1 + 0]          # store state (r4..r7 die in f2q below)
    st  %r5, [%r1 + 4]
    st  %r6, [%r1 + 8]
    st  %r7, [%r1 + 12]
    add %r6, %r4, %r8           # f2q arg = pos_x
    jal %r15, f2q
    st  %r10, [%r1 + 16]        # out fp32 cam_x
    add %r6, %r5, %r8           # f2q arg = pos_z (r5 survives f2q)
    jal %r15, f2q
    st  %r10, [%r1 + 20]        # out fp32 cam_z
    li  %r14, 3                 # MVP row3[3] = 3.0 + cam_z (Q16: 3 << 16)
    li  %r10, 16
    shl %r14, %r14, %r10        # 196608
    add %r6, %r5, %r14
    jal %r15, f2q
    st  %r10, [%r1 + 28]        # out fp32 (3.0 + cam_z)
    li  %r10, 8
    shl %r8, %r3, %r10          # cookie << 8 (echo word high byte)
    add %r9, %r9, %r0           # frame counter++ (full word; masked next)
    li  %r10, 0xFF
    and %r9, %r9, %r10          # counter stays in the low byte
    add %r8, %r8, %r9
    st  %r8, [%r1 + 24]         # echo: (cookie<<8) | frame_counter
done:
    halt
f2q:
    li  %r12, 0
    cmp %r7, %r6, %r12          # nzp = sign of arg (r6; cmp writes no reg)
    brnzp p, f2q_pos            # > 0  (NOTE: 'nz' means N-or-Z in this
    brnzp n, f2q_neg            # < 0  assembler — letters are the flags to
    li  %r10, 0                 # == 0 -> +0.0f   TEST, like LC-3!)
    jr  %r15
f2q_pos:
    li  %r13, 0                 # sign = 0
    brnzp nzp, f2q_nrm
f2q_neg:
    sub %r6, %r12, %r6          # |arg| = 0 - arg
    li  %r13, 0x8000            # LI is zero-extended: bit31 via shift
    li  %r14, 16
    shl %r13, %r13, %r14        # sign bit 0x80000000
f2q_nrm:
    li  %r14, 0                 # s = normalize shift count
f2q_nloop:
    li  %r7, 30
    shr %r7, %r6, %r7           # bit30? (logical; arg > 0 here)
    cmp %r7, %r7, %r12          # r12 = 0
    brnzp p, f2q_mag            # bit30 set (r7=1 -> P)
    add %r6, %r6, %r6           # v <<= 1
    add %r14, %r14, %r0         # s++ (r0 = 1)
    brnzp nzp, f2q_nloop
f2q_mag:
    li  %r12, 141               # exponent field = 141 - s (127 + (14 - s))
    sub %r10, %r12, %r14
    li  %r12, 23
    shl %r10, %r10, %r12        # exponent field in place
    li  %r12, 1
    li  %r14, 23
    shl %r12, %r12, %r14        # 1 << 23
    sub %r12, %r12, %r0         # (1 << 23) - 1 = mantissa mask
    li  %r14, 6
    li  %r7, 1
    shl %r7, %r7, %r14          # 64 (round-half-up at bit 7)
    add %r6, %r6, %r7           # N + 64 (N in [2^30, 2^31): no overflow)
    li  %r14, 7
    shr %r6, %r6, %r14          # Q = (N+64) >> 7, Q in [2^23, 2^24)
    and %r6, %r6, %r12          # drop the implicit leading 1
    add %r10, %r10, %r6         # exponent | mantissa
    add %r10, %r10, %r13        # + sign bit
    jr  %r15
