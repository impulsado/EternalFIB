	.data
fib:	.space 40 # 4*10
	
	.text
	.globl main
main:
	li $s0,2  # i = 2; ## $s0 <-> i
	la $t2,fib
	li $t0,0
	sw $t0,0($t2) # fib[0] = 0;
	li $t0,1
	sw $t0,4($t2) # fib[1] = 1;
	
while:
	slti $t0,$s0,10
	beq $t0,$zero,fi  # while (i<10)
	
	la $t3,fib
	sll $t0,$s0,2
	addu $t3,$t3,$t0  # $t3 = @fib[i]
	lw $t1,-4($t3)  # $t1 = fib[i-1]
	lw $t2,-8($t3)  # $t2 = fib[i-2]
	addu $t4,$t1,$t2  # $t4 = fib[i-1] + fib[i-2]
	sw $t4,0($t3)  # fib[i] = $t4
	
	addiu $s0,$s0,1  # i++;
	b while
fi: