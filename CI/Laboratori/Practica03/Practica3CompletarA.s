.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
# Aqui has de introducir el codigo
movl $1, %eax  ; i = 1
for:
	cmpl 12(%ebp), %eax
	jge rof  ; if (i>=elementos) rof

	movl 8(%ebp), %ecx   ; ecx = &vector[0]
	movl (%ecx, %eax, 4), %edx  ; Vector[i]
	movl -4(%ecx, %eax, 4), %ebx  ; Vector[i-1]
	cmpl %edx, %ebx
	jne for_fi  ; if (Vector[i] != Vector[i-1]) for_fi
	movl %eax, -4(%ebp)  ; res = i

for_fi:
	incl %eax  ; i++
	jmp for

rof:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
