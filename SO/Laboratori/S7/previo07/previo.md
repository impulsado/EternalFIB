# PREGUNTA 1
Retorna la quantitat de chars llegits. Pot ser 1024 i inferior.
./es1 < input.in

# PREGUNTA 2
!RECORDA!
- "pro1 > pro2" redirecciona la sortida de pro1 al fitxer pro2.
- "pro1 | pro2" connecta la sortida de pro1 amb l'entrada de pro2.

El grep fa que es mostrin només els fitxers del directori actual que continguin "es".

# PREGUNTA 3
ps -o user,pid,command

# PREGUNTA 4
Fer Codi

# PREGUNTA 5
Quan fem un write(&num) se'n va on esta guardat el numero i mostra el binari corresponent al numero guardat.
Aquest valor no inteligible per a nosaltres,pero al ser un "int" sempre sera 4B. (Depen de l'arquitectura)

Quan fem un write(buff) anem a la direccio base d'on esta la cadena que equival al numero.
No estem mostrant el numero com a tal sino que buff[0] buff[1] ... donat que hem fet el sprintf

# PREGUNTA 6
## a
El myDriver1.c implementa la funció "read_driver_1".

## b
El major és un id que identifica al device driver mentre que el minor identifica al dispositiu (gestionat pel device manager determinat).