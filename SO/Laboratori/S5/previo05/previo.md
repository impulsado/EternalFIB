---
GRUP: YO18
---

# Gestión de Memoria
## PUNT 1
"B" Està en la secció BSS (Variables Globals NO Inicialitzades)
"D" Inicialitzat en la secció ".data" (Variables Globals SI Inicialitzades)
"R" Read Only
"U" Indefinit
"T" Esta en la secció .text (El Codi)
"C" Common symbols.

Les variables i,s no podrem saber mai les direccions donades que aquestes son part del codi.
No son un simbol definit previament sino que son part d'una funció.

La funció suma:
00000000000011c9 T suma

## PUNT 2
[Modificar codi]

## PUNT 3
Per a compilar amb una llibreria estàtica:
gcc -o mem1_previo_v2 mem1_previo_v2.c -static

! Fer ús de -static-libgcc no funciona perque pot ser que necessitis altres llibreries hi hagi conflicte.

## PUNT 4
[Modificar codi]

## PUNT 5
Jo diria que és el "r-xp" perque es el que te permissos d'execució i un codi s'ha d'executar.

La diferencia es que en la seccio de dades no ha de variar perque nosaltres estem assignant memoria dinamica.
Aquesta no te res a veure amb memoria de dades i la memoria de dades no varia perque es el mateix codi.

Respecte el HEAP si que hi ha diferencia, donat que en el V2 estem fent servir memoria dinàmica i en v1 no.

### mem2_previo
No surt ni el "[HEAP]"

### mem2_previo_v2
#### vector[10];
"""
00401000-00486000 r-xp 00001000 08:02 1967095                            /home/paubru/SO/S5/mem2_previo_v2
00d30000-00d53000 rw-p 00000000 00:00 0                                  [heap]
"""
· 53000-30000 = 23000

#### vector[40000];
"""
00401000-00486000 r-xp 00001000 08:02 1967095                            /home/paubru/SO/S5/mem2_previo_v2
02306000-02350000 rw-p 00000000 00:00 0                                  [heap]
"""
· 2350000-2306000 = 44000

## PUNT 6
[Modificar Codi]