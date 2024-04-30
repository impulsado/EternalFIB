# IMPORTANT
**NO** pots fer `tar` desde qualsevol ruta.
S'ha de fer desde la mateixa on estan els fitxers. Si ho fas des d'una altra, pot ser que et quedi tal que:

```Estructura Incorrecta
program.tar:
- X13425/CuaIOParInt.hh
- X13425/CuaIOParInt.cc
- X13425/program.cc
```
Això el Jutge no ho accepta donat que el seu Makefile no té en compte que hi hagi una carpeta (En aquest cas "X13425"), sino que està dissenyat perquè estiguin a l'arrel.

Per a solucionar-ho s'ha de fer `cd /path/to/[on estigui program.cc]` i des d'aqui fer `tar -cvf result.tar program.cc file.hh file.cc`
La estructura resultant és tal que:

```Estructura Correcta
program.tar:
CuaIOParInt.hh
CuaIOParInt.cc
program.cc
```