# matadd — A[i] += B[i], 32 elements per thread (128 total, 4 threads).
# Params (at CMDBUF_BASE): [0] = A byte offset, [1] = B byte offset.
# Regs: r1=i  r2=Abase r3=Bbase r4=32 r5=cmp scratch r6=Aptr r7=Bptr
#       r8/r9=data  r10=1  r11=4 (stride)
    li  %r10, 1
    li  %r9, 2               # shift amount (setup only)
    li  %r11, 4              # byte stride
    ld  %r2, [%r12 + 0]      # A base (VRAM byte offset)
    ld  %r3, [%r12 + 4]      # B base
    li  %r4, 32              # per-thread element count
    mul %r5, %r15, %r4       # threadIdx * 32
    shl %r5, %r5, %r9        # *4 -> base byte offset (r5 done after this)
    add %r6, %r2, %r5        # my A pointer
    add %r7, %r3, %r5        # my B pointer
    li  %r1, 0               # i
loop:
    ld  %r8, [%r6 + 0]
    ld  %r9, [%r7 + 0]       # r9 free again (shift done in setup)
    add %r8, %r8, %r9
    st  %r8, [%r6 + 0]
    add %r6, %r6, %r11       # A ptr += 4
    add %r7, %r7, %r11       # B ptr += 4
    add %r1, %r1, %r10
    cmp %r5, %r1, %r4        # only CMP sets flags! (r5 free: base consumed)
    brnzp n, loop            # i < 32 ?
    halt
