.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp

	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo
    movl $0, %eax  # i (eax) = 0
    movl 8(%ebp), %ecx  # ecx = &mata
    movl 12(%ebp), %edx  # edx = &matb
    movl 16(%ebp), %esi
    imul %esi, %esi  # esi = n*n

processar_for:
    # comprovació
    cmpl %esi, %eax
    jge processar_rof  # if (i >= n^2) processar_rog

    # cos
    movb (%ecx, %eax), %bl  # mata[i]
    andb $1, %bl  # mata[i] &= 1
    movb %bl, (%edx, %eax)  # matb[i] = mata[i]&1
    cmpb $0, %bl
    je processar_for_fi  # if (0 == matb[i]) processar_for_fi

    movb $255, (%edx, %eax)  # matb[i] = 255
processar_for_fi:
    # incrementar
    incl %eax
    jmp processar_for

processar_rof:
# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
