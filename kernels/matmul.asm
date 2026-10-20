# matmul — C[4][4] = A[4][4] * B[4][4] (int32, row-major).
# Thread t computes row t: for j in 0..3: acc=0; for k in 0..3:
#   acc += A[t][k] * B[k][j];  C[t][j] = acc.
# Params (at CMDBUF_BASE): [0]=A off [1]=B off [2]=C off.
# Regs: r0=1  r2=Bbase  r3=Cbase  r4=j  r5=k  r6=acc  r7/r8=data
#       r9=addr/scratch  r10=4  r11=16  r12=param base  r13=Abase  r15=tid
    li  %r0, 1
    li  %r10, 4              # float byte stride
    li  %r11, 16             # row byte stride
    ld  %r13, [%r12 + 0]     # A base (kernel-owned now)
    ld  %r2, [%r12 + 4]      # B base
    ld  %r3, [%r12 + 8]      # C base
    li  %r4, 0               # j = 0
outer:
    mul %r9, %r15, %r11      # t*16
    add %r1, %r13, %r9       # A row ptr (fresh each j)
    li  %r5, 0               # k = 0
    li  %r6, 0               # acc = 0
inner:
    ld  %r7, [%r1 + 0]       # A[t][k]
    mul %r9, %r5, %r11       # k*16
    mul %r8, %r4, %r10       # j*4
    add %r9, %r9, %r8
    add %r9, %r9, %r2        # &B[k][j]
    ld  %r8, [%r9 + 0]       # B[k][j]
    mul %r7, %r7, %r8        # product
    add %r6, %r6, %r7        # acc +=
    add %r1, %r1, %r10       # A row ptr += 4
    add %r5, %r5, %r0        # k += 1
    cmp %r9, %r5, %r10       # k < 4 ?  (only CMP sets flags)
    brnzp n, inner
    mul %r9, %r15, %r11      # t*16
    mul %r8, %r4, %r10       # j*4
    add %r9, %r9, %r8
    add %r9, %r9, %r3        # &C[t][j]
    st  %r6, [%r9 + 0]
    add %r4, %r4, %r0        # j += 1
    cmp %r9, %r4, %r10       # j < 4 ?
    brnzp n, outer
    halt
