# Programació 1
# GENERAL
| NOM | CODI | DATA | CRÈDITS | DIFICULTAT | CÀRREGA TREBALL | NOTA |
| --- | --- | --- | --- | --- | --- | --- |
| [Programació 1](https://www.fib.upc.edu/es/estudios/grados/grado-en-ingenieria-informatica/plan-de-estudios/asignaturas/PRO1) | PRO1 | Q1 | 7.5 | 7/10 | 7/10 | 9.5 |

<br>

# EXPLICACIÓ
Programació 1 ensenya els fonaments de la programació funcional: Bucles, Funcions, Recursivitat, Vectors...<br>
És una assignatura que requereix que li dediquis una mica de temps cada dia. No és molt exigent, però si fas una mica cada dia en comptes de molt un dia, notaràs molt la diferència.

## Exàmens
Respecte als exàmens, aquests són molta part mental. Els exercicis proposats al jutge no són gaire diferents del que et trobaràs el dia de l'examen i tindrà un factor clau com et mentalitzis.

## Recomanacions
1. DEBUGAR.
2. Intentar fer els exercicis del jutge en menys de 30 min cadascun. Hi haurà exercicis que els faràs en menys temps i alguns que requeriràs hores, però els exàmens estan pensats perquè tardis de mitja 30 min per exercici.
3. ChatGPT pot ser perillós si t'acostumes.
4. Dibuixa, dibuixa, dibuixa. Tindre un paper i escriure que faràs i trobar patrons i punts claus farà que milloris molt.
5. No et frustris si ets nou programant. La programació requereix temps i dedicació. Al principi la corba d'aprenentatge és prou inclinada, però a la llarga, quan comencis a entendre com funciona, veuràs que t'ajudarà en el dia a dia aquesta nova mentalitat i resoldràs exercicis molt més ràpid.

<br>

# DEBUGAR
**! SI US PLAU ! DEBUGA !** <br>
Debugar ajuda molt a veure com s'està executant el codi i on poden haver errades. Adjunto tutorial de com configurar-ho. Pot salvarte MOLTES vegades i està permés a l'exàmen.
<br>
Mira el video SENCER intenant entendre i replicant el que fa, de veritat, no puc recomanar-ho més. <br>
https://youtu.be/2VokW_Jt0oM?si=loPfLgIQE_lY-Gwl

<br>

# P1++ V.S. G++
g++ serveix per compilar els programes de C++ i p1++ és un aliàs de g++ amb uns paràmetres específics que ha decidit la UPC. P1++ és més estricte amb la sintaxi i altres coses per evitar que la gent tingui "males pràctiques".
<br>
Es poden fer servir els dos però "p1++" només ho podràs fer servir si fas ús de la màquina virtual que proporciona la FIB o configures l'alias al bashrc.

<br>

# COMANDES
## Compilar
```sh
# Compilar sense limitacions
g++ -o ./NOM_FITXER.exe ./NOM_FITXER.cc

# Compilar amb alias FIB 
p1++ -o ./NOM_FITXER.exe ./NOM_FITXER.cc

# Paràmetres de p1++
g++ -ansi -O2 -DNDEBUG -D_GLIBCXX_DEBUG -Wall -Wextra -Werror -Wno-sign-compare -Wshadow -o ./NOM_FITXER.exe ./NOM_FITXER.cc
```

## Joc de proves
```sh
# Compilar
p1++ -o ./NOM_FITXER.exe ./NOM_FITXER.cc

# Executar programa tal i com l'executa el jutge
./NOM_FITXER.exe < ./NOM_SAMPLE.inp > sortida.out

# Comparar resultat
kompare soritda.out ./NOM_SAMPLE.cor
```

<br>

# WEBS
- Pàgina principal <br>
https://pro1.cs.upc.edu/ <br> 

- Jutge <br>
https://jutge.org/ <br>

- Examinator <br>
https://evaluator.cs.upc.edu/#/ <br>