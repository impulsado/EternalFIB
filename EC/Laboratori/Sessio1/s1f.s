.data
vec:    .word 9,8,7,6,5,4,3,2,1
# &vec[i] = &vec[0]+(tamany_element_vector(4)*posicio(i))

.text
.globl main
main:
    # OBJECTIU:  $s1 <- vec[i]
    la $t0,vec  # $t0 = @vec[0]  ## Guardar valor primera pos del vector
    sll $t1,$s2,2  # $t1 = $s2*4  ## Multiplicar per 4 el valor de 'i' (que esta en $s2)
    addu $t0,$t0,$t1 # $t0 = $t0+$t1 ## Sumar la direccio final
    lw $s1,0($t0)  # $s1 = vec[2]  ## Carregar el contingut de la pos 2 del vector
    jr $ra  # Tornar al inici