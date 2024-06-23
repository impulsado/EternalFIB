	.data
cadena: .byte -1,-1,-1,-1,-1,-1
vec:	.word 5,6,8,9,1
 	
	.text
	.globl main
main: 
	li $s0,0  # i = 0; ## $s0 <-> i

while:
	li $t0,5  # $t0 = 5
	bge $s0, $t0, fi  # while(i<=5)
	
	la $t5,vec
	li $t4,4  # $t4 = 4
	subu $t2,$t4,$s0  # $t2 = 4-i
	sll $t2,$t2,2
	addu $t3,$t5,$t2  # $t3 = @vec[4-i]
	lw $t2,0($t3)  # $t2 = vec[4-i]
	li $t3,'0'  # $t3 = 0x30
	addu $t4,$t2,$t3  # $t4 = vec[4-i]+'0'
	la $t0,cadena
	addu $t0,$t0,$s0  # $t0 = @cadena[i]
	sb $t4,0($t0)  # cadena[i] = $t4  ## CUIDADO QUE HA DE SER sb perque cadena es de bytes
	
	addiu $s0,$s0,1  # i++;
	b while
fi:
	la $t0,cadena
	sb $zero,5($t0)  # cadena[5] = 0 ## Donat que es byte, puc ficar el 5 directament
	
	li $v0,4 # Fer print_string
	move $a0,$t0
	syscall 
	
	jr $ra  # Tornar al inici