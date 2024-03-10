    .data
result: .word 0
num:    .byte '0'

    .text
    .globl main
main:
    # Variables Principals
    la $t0,result # &result
    la $t1,num
    lb $t1,0($t1)  # num
    
    # Constants
    li $t3,'a'
    li $t4,'z'
    # (A&&B)
    blt $t1,$t3,or  # if num<a goto or
    bgt $t1,$t4,or  # if num>z goto or
    sw $t1,0($t0)  # result = num
    j niam  # Final
or: 
    # Constants
    li $t3,'A'
    li $t4,'Z'
    # (C&&D)
    blt $t1,$t3,else  # if num<A goto else
    bgt $t1,$t4,else  # if num>Z goto else
    sw $t1,0($t0)  # result = num
    j niam  # Final
else:
    # Constants
    li $t3,'0'
    li $t4,'9'
    blt $t1,$t3,elsee  # if num<0 goto elsee
    bgt $t1,$t4,elsee  # if num>9 goto elsee
    subu $t1,$t1,$t3  # num-'0'
    sw $t1,0($t0) # result = num-'0'
    j niam  # Final
elsee:
    li $t2,-1
    sw $t2,0($t0)  # result = -1
niam:
    jr $ra