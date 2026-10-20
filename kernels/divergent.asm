# divergent — tid-dependent trip count; thread 0 skips the loop entirely.
# Result: smem[64+tid] = tid*(tid+1)/2, then to CMDBUF_BASE+0x100+4*tid.
    li  %r1, 0               # acc
    li  %r2, 0               # i
    li  %r3, 64
    add %r3, %r3, %r15       # smem slot 64+tid
    li  %r6, 1
loop:
    cmp %r4, %r2, %r15       # nzp = (i - tid); only CMP sets flags!
    brnzp p, done            # i > tid -> done
    mul %r5, %r2, %r15
    add %r1, %r1, %r5
    add %r2, %r2, %r6
    brnzp nzp, loop
done:
    sts %r1, [%r3 + 0]
    bar
    lds %r7, [%r3 + 0]
    li  %r10, 4
    mul %r10, %r15, %r10
    li  %r11, 256            # 0x100
    add %r11, %r11, %r10
    add %r11, %r12, %r11
    st  %r7, [%r11 + 0]
    halt
