###################################
# Standard startup code.  Invokes the routine "main"
# and calls exit() on return from main
	.text
	.globl __start
__start:
	jal	main

	li	$v0, 10
	syscall			# syscall 10 (exit)