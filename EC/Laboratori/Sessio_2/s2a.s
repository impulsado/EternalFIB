	.data

	.text
	.globl main
main:
	li $s1, 23 # Y
	li $s0, 8  # X

# COPIA EL TEU CODI AQUI
	li $t1,1  # 0x00000001
	sllv $t1,$t1,$s0  # 1<<X
	addi $t1,$t1,-1  # (1<<X)-1
	xor $s1, $s1, $t1  # Y = Y^((1<<X)-1)

	jr $ra
