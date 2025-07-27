.data
    .align 16
	mask: .byte 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1  # mascara

.text
	.align 16
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
    xor %eax, %eax  # i (eax) = 0
    movl 8(%ebp), %ecx  # ecx = &mata
    movl 12(%ebp), %edx  # edx = &matb
    movl 16(%ebp), %esi
    imul %esi, %esi  # esi = n*n
    
    pxor %xmm0, %xmm0
    movdqa mask, %xmm1

processar_for:
    # comprovació
    cmpl %esi, %eax
    jge processar_rof  # if (i >= n^2/16) processar_rog

    # cos
    movdqa (%ecx, %eax), %xmm2  # mata[i], mata[i+1], ..., mata[i+15]
    pand %xmm1, %xmm2  # xmm2 &= xmm1
    pcmpgtb %xmm0, %xmm2  # mata[i]>0, mata[i+1]>0, ..., mata[i+15]>0
    movdqa %xmm2, (%edx, %eax)  # matb[i]&=mata[i]
    # NOTA: En aquest cas "pcmpgtb" ja fica '255' o '0' si és més gran o no
    # incrementar
    addl $16, %eax  # ara anem de 16 en 16
    jmp processar_for

processar_rof:
# El final de la rutina ya esta programado
    emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
