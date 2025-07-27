.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo
; &(Matriz + 4(3*i + j))
	movl $0, -4(%ebp)  ; res = 0
	xorl %ecx, %ecx  ; i = 0 [Optimitzacio]
for:
	cmpl $3, %ecx
	jge rof; if (i>=3) rof

	xorl %edx, %edx  ; j = 0 [Optimitzacio]
for_for:
	cmpl %ecx, %edx
	jg for_rof  ; if (j>i) for_rof

	movl 8(%ebp), %eax  ; eax = &Matriz[0][0]
	imull $3, %ecx, %ebx  ; ebx = 3*i
	addl %edx, %ebx  ; ebx + j
	movl (%eax, %ebx, 4), %eax  ; eax = Matriz[i][j]
	addl %eax, -4(%ebp)  ; res += eax

	incl %edx  ; j++
	movl %edx, -12(%ebp)  ; Guardar j en stack
	jmp for_for
for_rof:
	addl 12(%ebp), %ecx  ; i += salto
	movl %ecx, -8(%ebp)  ; Guardar i en stack
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