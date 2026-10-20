# pool2d — 2x2 stride-2 MAX pool on the Ember compute core (Phase 7d).
#
# Contract (bit-exact vs tools/golden/mnist.py maxpool2):
#   input  = CHW planes, ONE pixel BYTE per 32-bit word (low byte):
#            word[base + (c*ppc + y*W + x)*4] = pixel(c,y,x) raw byte
#   output = word[obase + (c*opx + p)*4] = max byte (SAME packing)
#   Pixels are SIGNED int8 (conv outputs can be negative). The core has no
#   byte ops, so taps are mapped (b << 24): monotone under the ALU's SIGNED
#   MAXC, then (max >> 24) logical restores the winning byte. y = p/ow via
#   DIV; taps at +1 row (ws4=4*W bytes) / +1 col (+4 bytes).
#
# Params (at CMDBUF_BASE, word offsets):
#   [0]=base [1]=obase [2]=opx [3]=ow [4]=nchan [5]=ws4 [6]=ppc
#
# Regs: r0=1 r1=base r2=obase r3=opx r4=ow r5=nchan r6=c r7=scratch/taps
#       r8=p r9=K24(24)/scratch r10=ws4 r11=cbase r12=param base (HW)
#       r13=addr scratch r14=max r15=tid
    li  %r0, 1
    ld  %r1, [%r12 + 0]      # base
    ld  %r2, [%r12 + 4]      # obase
    ld  %r3, [%r12 + 8]      # opx
    ld  %r4, [%r12 + 12]     # ow
    ld  %r5, [%r12 + 16]     # nchan
    ld  %r10, [%r12 + 20]    # ws4
    sub %r6, %r6, %r6        # 0
    add %r6, %r6, %r15       # c = threadIdx
cloop:
    cmp %r7, %r6, %r5
    brnzp zp, cdone          # c >= nchan -> done
    ld  %r11, [%r12 + 24]    # ppc
    mul %r13, %r6, %r11      # c*ppc
    add %r13, %r13, %r13
    add %r13, %r13, %r13     # *4 bytes
    add %r11, %r1, %r13      # cbase
    sub %r8, %r8, %r8        # p = 0
ploop:
    cmp %r7, %r8, %r3
    brnzp zp, pdone          # p >= opx -> channel done
    div %r13, %r8, %r4       # y = p / ow
    mul %r9, %r13, %r4
    sub %r9, %r8, %r9        # x = p - y*ow
    add %r13, %r13, %r13     # 2y
    mul %r13, %r13, %r10     # 2y*ws4
    add %r9, %r9, %r9        # 2x
    add %r7, %r9, %r9        # 4x
    add %r7, %r7, %r7        # 8x bytes
    add %r13, %r13, %r7      # tap00 offset
    add %r13, %r13, %r11     # &tap00
    li  %r9, 24              # K24 (shift amount)
    ld  %r14, [%r13 + 0]     # tap(0,0)
    shl %r14, %r14, %r9
    ld  %r7, [%r13 + 4]      # tap(0,1)
    shl %r7, %r7, %r9
    maxc %r14, %r14, %r7
    add %r13, %r13, %r10     # row +1
    ld  %r7, [%r13 + 0]      # tap(1,0)
    shl %r7, %r7, %r9
    maxc %r14, %r14, %r7
    ld  %r7, [%r13 + 4]      # tap(1,1)
    shl %r7, %r7, %r9
    maxc %r14, %r14, %r7
    shr %r14, %r14, %r9      # winning byte -> low 8 bits
    mul %r9, %r6, %r3        # c*opx
    add %r9, %r9, %r8        # + p
    add %r9, %r9, %r9
    add %r9, %r9, %r9        # *4 bytes
    add %r9, %r9, %r2        # + obase
    st  %r14, [%r9 + 0]
    add %r8, %r8, %r0        # p++
    cmp %r7, %r8, %r3
    brnzp n, ploop           # p < opx
pdone:
    li  %r14, 4
    add %r6, %r6, %r14       # c += 4 (next thread lane)
    brnzp nzp, cloop
cdone:
    halt
