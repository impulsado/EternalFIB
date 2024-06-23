	.data
signe:		.word 0
exponent:	.word 0
mantissa:	.word 0
cfixa:		.word 0x87D18A00
cflotant:	.float 0.0

	.text
	.globl main
main:
	addiu	$sp, $sp, -4
	sw	$ra, 0($sp)

	la	$t0, cfixa
	lw	$a0, 0($t0)
	la	$a1, signe
	la	$a2, exponent
	la	$a3, mantissa
	jal	descompon

	la	$a0, signe
	lw	$a0,0($a0)
	la	$a1, exponent
	lw	$a1,0($a1)
	la	$a2, mantissa
	lw	$a2,0($a2)
	jal	compon

	la	$t0, cflotant
	swc1	$f0, 0($t0)

	lw	$ra, 0($sp)
	addiu	$sp, $sp, 4
	jr	$ra

# === DESCOMPON ===
descompon:
	slt $t0,$a0,$zero  # $t0 = cf<0
	sw $t0,0($a1)  # *s = $t0
	sll $a0,$a0,1  # cf = cf<<1

descompon_if:
	bne $a0,$zero,descompon_else  # cf!=0 goto descompon_else
	sw $zero,0($a2)  # *e = 0
	sw $a0,0($a3)  # *m = cf
	jr $ra
descompon_else:
	li $t0,18  # $t0 = 18 (Fare servir com "exp")
	
	# EXPLICACIONS
	# 1.
	# NO ENTENC PERQUE INICIALITZEM EN 18
	# ---
	# 2.
	# Portem el primer bit '1' de la mantissa a la pos 31 (Donat que quan arribi el num sera negatiu)
	# Ho fem perque la mantisa es de la forma "1,[...]" (Tot i que haurem d'eliminar aquest 1 posteriorment)
	# ---
	# 3. 
	# NO ENTENC PERQUE BAIXEM L'EXPONENT
	# ---
	# 4.
	# Fem cf>>8 per deixar en la posicio que pertoca la mantissa
	# ---
	# 5.
	# 0x7FFFFF que aixo son "0111 1111 [...]" perque aquest primer 1 conserva el bit num 22 i treu el 23-31
	# Recordem que la mantissa ocupa 23 bits així que interessa que estigui del 0 al 22.  
descompon_while:
	sll $a0,$a0,1  # cf = cf<<1  # Jo se que la primera vegada s'executa (sino hagues saltat if)
	addiu $t0,$t0,-1  # exp--
	bge $a0,$zero,descompon_while  # cf>=0 goto descompon_while
	srl $a0,$a0,8  #cf = cf>>8 # No sra perque volem afegir 0
	li $t1,0x007FFFFF 
	and $a0, $a0, $t1  # cf = cf & 0x7FFFFF
	addiu $t0,$t0,127  # exp += 127
	sw $t0,0($a2)  # *e = exp
	sw $a0,0($a3)  # *m = cf
	jr $ra

# === COMPON ===
compon:
	sll $a0,$a0,31  # signe<<31
	sll $a1,$a1,23  # exponent<<23
	or $t0,$a0,$a1  # (signe<<31)|(exponent<<23)
	or $t0,$t0,$a2  # (signe<<31)|(exponent<<23)|mantisa
	mtc1 $t0,$f0  # Fica l'enter $t0 en un registre de coma flotant
	jr $ra
