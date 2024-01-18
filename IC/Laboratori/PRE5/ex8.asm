        MOVI R5,0
        MOVI R1,0x01
        MOVI R3,0xFF
for:    AND R4,R7,R1
        BZ R4,endif
        ADD R5,R5,R6
endif:  SHL R6,R6,R1
        SHL R7,R7,R3
        BNZ R7,for