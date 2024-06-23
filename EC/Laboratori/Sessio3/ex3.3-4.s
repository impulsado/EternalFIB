    .data
# int mat1[5][6];
.align 2
mat1:   .space 120

# int mat4[2][3] = {{2, 3, 1}, {2, 4, 3}};
.align 2
mat4:   2,3,1,2,4,3

# int col = 2; 
col:    .word 2

    .text
    .globl main
main:
    # 0 | ra | 4 B
    # TOTAL: 4 B
    addiu $sp,$sp,-4
    sw $ra,0($sp)

    la $a0,mat4  # a0 = &mat4[0][0]
    lw $a1,8($a0)  # a1 = mat4[0][2]
    la $t0,col
    lw $a2,0($t0)  # a2 = col
    jal subr
    li $t1,108  # (4*6 + 3)*4
    la $t0,mat1
    addu $t0,$t0,$t1  # &mat[4][3]
    sw $v0,0($t0)  # mat[4][3] = subr(mat4, mat4[0][2], col);

    la $a0,mat4  # a0 = &mat4[0][0]
    li $a1,1
    li $a2,1
    jal subr
    la $t0,mat1
    sw $v0,0($t0)  # mat[0][0] = subr(mat4, 1, 1);

    lw $ra,0($sp)
    addiu $sp,$sp,4
    jr $ra

subr:
    li $t3,3
    mult $a1, $t3  # i*3
    mflo $t0  # copy Lo to $t0
    addu $t0,$t0,$a2  # i*3+j
    sll $t0,$t0,2  # (i*3+j)*4
    addu $t0,$t0,$a0  # &x + (i*3+j)*4
    lw $t2,0($t0)

    la $t3,mat1
    li $t6,6
    mult $a2,$t6  # j*6
    mflo $t1  # copy Lo to $t1
    addiu $t1,$t1,5  # j*6+5
    sll $t1,$t1,2  # (j*6+5)*4
    addu $t1,$t3,$t1  # &mat1 + (j*6+5)*4
    sw $t2,0($t1)  #  mat1[j][5] = x[i][j];

    move $v0,$a1  # return i
    jr $ra
