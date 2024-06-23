# PRACTICA 1 #######################

.data
dada: .half 3
pdada: .word dada

.text
.globl main

main:
    # Cargar la dirección de dada en $a0
    la $a0, dada
    
    # Cargar el valor de dada (a través de su dirección) en $a1
    lh $a1, 0($a0)  # Carga el valor de dada como half-word
    
    # Cargar la dirección de pdada en $a2
    la $a2, pdada
    
    # Cargar el valor al que apunta pdada (dirección de dada) en $a3
    lw $a3, 0($a2)  # Carga la dirección almacenada en pdada


	jr $ra		# main retorna al codi de startup

