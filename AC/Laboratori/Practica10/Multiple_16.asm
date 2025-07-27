.text

es_multiple_16:
    # El registre es "%edx"
    movl %edx, %ebx
    andl $0x0000000F, %ecx
    cmpl $0, %ecx
    je si_es
    movl $0, %eax
    ret
si_es:
    movl $1, %eax
    ret