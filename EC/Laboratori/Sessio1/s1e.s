.data
A:      	.word 3,5,7  # A[3] = {3,5,7};
punter:      	.word 0  # punter = 0;

.text
.globl main
main:
        la $t0,A  # $t0 = &A[0]
        addiu $t0,$t0,8  # $t0 = &A[0+2]  ## 8=2*4 on 2 es la pos. i 4 pq. es word
        la $t1,punter  # $t1 = &punter
        sw $t0,0($t1)  # punter = &A[2];
        
        lw $t2,0($t1)  # $t2 = punter ($t1)  ## Valor de punter (que es &A[2])
        lw $t3,0($t2)  # temp = A[2]  ## temp es la variable $t3
        addiu $t3,$t3,2  # temp = temp + 2;

        lw $t2,0($t1)  # $t2 = punter
        lw $t4,-8($t2)  # temp2 = A[0]  ## tempo2 es la variable $t4
        addu $t3,$t4,$t3  # temp = temp2 + temp;
	
	lw $t2,0($t1)  # $t2 = punter
        sw $t3,-4($t2)  # A[1] = temp;

        li $v0,1  # Carregar el codi del syscall per fer print
        move $a0,$t3  # Mou a $a0 (Variable del MARS) el valor de temp ($t3).
        syscall  # Executa el print(temp)

        jr $ra		# main retorna al codi de startup
