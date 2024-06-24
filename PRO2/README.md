# Programació 2
# GENERAL
| NOM | CODI | DATA | CRÈDITS | DIFICULTAT | CÀRREGA TREBALL | NOTA |
| --- | --- | --- | --- | --- | --- | --- |
| [Programació 2](https://www.fib.upc.edu/ca/estudis/graus/grau-en-enginyeria-informatica/pla-destudis/assignatures/PRO2) | PRO2 | Q2 | 7.5 | 5/10 | 6/10 | 9.0 |

<br>

# EXPLICACIÓ
Programació 2 s'endinsa en la POO (o OPP en angles) però aquesta serà a grans trets i no s'entrarà en conceptes molt difícils. S'explicaran el funcionament de les estructures de dades bàsiques, junt amb com s'implementen, i com funcionen els punters. Tots els conceptes són senzills, però que requeriran prova i error per a entendre'ls correctament.
La part més important d'aquesta assignatura és la pràctica (tot i que no sigui la que més nota compta). Aquesta consta d'un enunciat amb una sèrie de funcions a implementar fent ús de la programació orientada a objectes.

## Exàmens
L'examen és similar al de PRO1. Antigament, hi havia un examen de la pràctica i eren escrits, en data de juny-2024, no hi ha examen de la pràctica i els exàmens tenen la mateixa dinàmica que en PRO1.

## Pràctica
Repositori amb la pràctica: <br>
https://github.com/impulsado/PRAC-PRO2


## Recomanacions
1. Pensar a paper i escriure en pseudocodi la practica. Si no ho fas, perdràs MOLTA estona refent funcions.
2. Fer la pràctica porta de temps, si us plau, comença a fer-ho des del dia que pengin l'enunciat i ves provant que funciona tot.
3. Debuggar.
4. Buscar un professor on les seves classes siguin "entretingudes" per entendre bé els conceptes de les estructures de dades.

<br>

# DEBUGAR
**! SI US PLAU ! DEBUGA !** <br>
Debugar ajuda molt a veure com s'està executant el codi i on poden haver errades. Adjunto tutorial de com configurar-ho. Pot salvarte MOLTES vegades i està permés a l'exàmen.
<br>
Mira el video SENCER intenant entendre i replicant el que fa, de veritat, no puc recomanar-ho més. <br>
https://youtu.be/2VokW_Jt0oM?si=loPfLgIQE_lY-Gwl

<br>

# COMANDES
## Joc de proves
```sh
# Compilar (En la primera comanda has de ficar tots els fitxers *.cc )
p2++ -c ./NOM_FITXER.cc
p2++ -o ./NOM_PROGRAMA.exe ./NOM_PROGRAMA.o ./NOM_FITXER.o

# Executar programa tal i com l'executa el jutge
./NOM_PROGRAMA.exe < ./NOM_SAMPLE.inp > sortida.out

# Comparar resultat
kompare soritda.out ./NOM_SAMPLE.cor
```

<br>

# WEBS
- Pàgina principal <br>
https://www.cs.upc.edu/~pro2/index.php <br> 

- Jutge <br>
https://jutge.org/ <br>

- Examinator <br>
https://evaluator.cs.upc.edu/#/ <br>