# barrier — block-wide sum through smem atomics; every thread reads 60.
# Phase 1: each thread clears its own slot (128+tid), BAR.
# Phase 2: all threads atomic_add tid*10 into slot 128, BAR, read back.
    li  %r1, 128
    add %r2, %r1, %r15       # my slot
    li  %r3, 0
    sts %r3, [%r2 + 0]       # clear my slot
    bar
    li  %r4, 10
    mul %r4, %r15, %r4       # tid*10
    li  %r5, 128
    atomic_add %r4, [%r5 + 0]
    bar
    lds %r6, [%r5 + 0]       # 0+10+20+30 = 60 for everyone
    li  %r7, 320             # 0x140
    add %r8, %r12, %r7
    li  %r9, 4
    mul %r9, %r15, %r9
    add %r8, %r8, %r9
    st  %r6, [%r8 + 0]
    halt
