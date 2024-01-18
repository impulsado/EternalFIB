        MOVI R5,0       ; Resultat
        MOVI R2,0x10    ; Comptador 16
        MOVI R1,0x01    ; Constant per multi
        MOVI R3,0xFF    ; Constant per div
for:    AND R4,R7,R1    ; Comprovar si LSB==1
        BZ R4,endif    ; si no es, anar a endif
        ADD R5,R5,R6    
endif:  SHL R6,R6,R1    ; Multiplicar
        SHL R7,R7,R3    ; Dividir
        ADDI R2,R2,-1
        BNZ R2,for      ; Mentre no sigui 0, repetir
