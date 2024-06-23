    .data
V1: .space  64
M:  .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
    .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
    .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
    .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
    .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
    .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0
    .word   0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1
V2: .word   -5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10
    
    .text
    .globl main
main:
    li $t0,0  # k = 0
    li $t9,4  # k_max = j_max = 4

fork:
    bge $t0,$t9,end_fork  # if (k>=k_max) goto end_fork
    li $t1,0  # i = 0
    li $t8,16  # i_max = 16

fori:
    bge $t1,$t8,end_fori  # if (i>=i_max) goto end_fori
    li $v0,0  # tmp = 0
    li $t2,0  # j = 0

forj:
    bge $t2,$t9,end_forj  # if (j>=j_max) goto end_forj
    # === MATRIU
    # M[0][0] + ((i*NC)+(j+k*4))*T
    # Calcular Columna (j+k*4)*T
    sll $t3,$t0,2  # k*4
    addu $t3,$t3,$t2  # j+k*4
    sll $t3,$t3,2  # (J+k*4)*4  ## int = 4 B
    # Calcular fila (i*NC)*T
    sll $t4,$t1,6  # i*4*2 ## 6 = 4+2 on 4 = NC i 2 = Tamany de int
    # Calcular posició
    la $t5,M
    addu $t5,$t5,$t3
    addu $t5,$t5,$t4
    lw $t5,0($t5)  # M[i][j+k*4]
    
    # === VECTOR
    la $t6,V2
    addu $t6,$t6,$t3  # @V2[j+k*4]
    lw $t6,0($t6)  # V2[j+k*4]

    # === OPERAR
    mult $t5,$t6  # M[i][j+k*4]*V2[j+k*4]
    mflo $t7
    addu $v0,$v0,$t7  # tmp += M[i][j+k*4]*V2[j+k*4]
    
    addiu $t2,$t2,1  # j++
    b forj

end_forj:
    # === VECTOR
    la $t5,V2
    sll $t6,$t1,2  # i*4
    addu $t5,$t5,$t6  # @V[i]
    lw $t7,0($t5)  # V[i]
    addu $t7,$t7,$v0  # V[i] += tmp
    sw $t7,0($t5)

    addiu $t1,$t1,1  # i++
    b fori

end_fori:
    addiu $t0,$t0,1  #k++
    b fork

end_fork:
    jr $ra