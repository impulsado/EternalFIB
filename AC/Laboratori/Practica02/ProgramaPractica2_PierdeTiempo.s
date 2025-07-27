	.file	"ProgramaPractica2_PierdeTiempo_v1.c"
	.text
.globl PierdeTiempo
	.type	PierdeTiempo, @function
PierdeTiempo:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$0, -12(%ebp)
	movl	$1, -4(%ebp)
	jmp	.L2
.L6:
	movl	$1, -8(%ebp)
	jmp	.L3
.L5:
	movl	-8(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jne	.L4
	movl	-4(%ebp), %eax
	addl	%eax, -12(%ebp)
.L4:
	addl	$1, -8(%ebp)
.L3:
	movl	-8(%ebp), %eax
	cmpl	-4(%ebp), %eax
	jle	.L5
	addl	$1, -4(%ebp)
.L2:
	movl	-4(%ebp), %eax
	cmpl	8(%ebp), %eax
	jl	.L6
	movl	-12(%ebp), %eax
	leave
	ret
	.size	PierdeTiempo, .-PierdeTiempo
	.ident	"GCC: (Ubuntu/Linaro 4.4.4-14ubuntu5) 4.4.5"
	.section	.note.GNU-stack,"",@progbits
