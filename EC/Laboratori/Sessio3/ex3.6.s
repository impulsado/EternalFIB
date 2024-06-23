	.data
mat:	.word 0,0,2,0,0,0
	.word 0,0,4,0,0,0
	.word 0,0,6,0,0,0
	.word 0,0,8,0,0,0
	
resultat: .byte 0

	.text
	.globl main
main:
	addiu $sp,$sp,-4
	sw $ra,0($sp)

	la $a0,mat
	jal suma_col
	la $t0,resultat
	sw $v0,0($t0)  # resultat = suma_col(mat);
	
	lw $ra,0($sp)
	addiu $sp,$sp,4
	jr $ra

suma_col:
	la $t1,mat
	addiu $t0,$t1,8  # p = &mat[0][2]
	move $t1,$zero  # i = 0

	move $v0,$zero  # suma = 0
	li $t4,4  # max
suma_col_for: 
	lw $t2,0($t0)  # *p
	addu $v0,$v0,$t2  # suma += *p
	addiu $t0,$t0,24  # p+=6
	addiu $t1,$t1,1  # i++
	blt $t1,$t4,suma_col_for  # if i<max goto suma_col_for 

	jr $ra