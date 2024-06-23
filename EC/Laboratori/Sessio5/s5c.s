	.data	
A:      .space  512
	.space  16  # 4*4
B:      .space  512
	.space  16  # 4*4
C:      .space  512

	.text
	.globl main
main:
        li      $t0, 0          # $t0 = i
        li      $t1, 128
        la      $t2, A          # $t2 = @A[i]
        la      $t3, B          # $t3 = @B[i]
        la      $t4, C          # $t4 = @C[i]
for:
        bge     $t0, $t1, end
        lw      $t5, 0($t2)     # $t5 = A[i]
        lw      $t6, 0($t3)     # $t6 = B[i]
        addu    $t5, $t5, $t6   
        sw      $t5, 0($t4)     # C[i] = A[i] + B[i]
        addiu	$t2, $t2, 4
        addiu	$t3, $t3, 4
        addiu	$t4, $t4, 4
        addiu	$t0, $t0, 1
        b       for
end:
	jr	$ra
