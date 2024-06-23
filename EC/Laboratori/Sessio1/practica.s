	.data
aa:	.byte -5
bb: .half -344
cc: .dword -3
dd: .byte 0xA0 	# Tot i .byte no distingeix entre signed i unsigned 
				# Hauriem de fer això en el .text: li $t0, 0xA0 && sb $t0, 0(dd)
ee: .word 5799
ff: .half -1