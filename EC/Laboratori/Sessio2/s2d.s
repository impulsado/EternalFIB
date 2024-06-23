.data
alfabet: .asciiz "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
w1:      .asciiz "ARQUITECTURA"
         .space 3
w2:      .space 16
w3:      .space 16
count:   .word 0

.text
.globl main
main:
   addiu $sp, $sp, -4
   sw    $ra, 0($sp) 
   la    $s0, count
   la    $a0, w1
   la    $a1, w2
   jal   codifica 
   sw    $v0, 0($s0)
   la    $a0, w2
   la    $a1, w3
   jal   codifica 
   lw    $s1, 0($s0)
   addu  $s1, $s1, $v0
   sw    $s1, 0($s0)
   li    $v0, 4
   la    $a0, w2
   syscall
   la    $a0, w3
   syscall
   lw    $ra, 0($sp)
   addiu $sp, $sp, 4
   jr    $ra

g:  
   lb    $t0, 0($a1)
   li    $t1, 'A'
   addiu $t1, $t1, 25
   sub   $t1, $t1, $t0
   add   $t0, $a0, $t1
   lb    $v0, 0($t0) 
  
   jr $ra


codifica:
   addiu $sp, $sp, -16
   sw    $ra, 0($sp)
   sw    $s0, 4($sp)
   sw    $s1, 8($sp)
   sw    $s2, 12($sp)
   move  $s0, $a0
   move  $s1, $a1 
   move  $s2, $zero
while:
   lb    $t0, 0($s0)
   #lb    $t0, 0($t0) #! Error 1
   beq   $t0, $zero, fi_while
   la    $a0, alfabet
   move  $a1, $s0 #! Error 2
   jal   g  
   sb    $v0, 0($s1) #! Error 3
   addiu $s0, $s0, 1
   addiu $s1, $s1, 1
   addiu $s2, $s2, 1  
   b     while     
 fi_while:
   sb    $zero, 0($s1)
   move  $v0, $s2
   lw    $ra, 0($sp)
   lw    $s0, 4($sp)
   lw    $s1, 8($sp)
   lw    $s2, 12($sp)
   addiu $sp, $sp, 16
   jr    $ra



 
