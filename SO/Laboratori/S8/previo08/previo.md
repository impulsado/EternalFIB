GRUPO: YO18

# PREGUNTA 1
mknod ./pipe_ex1 p
cat > pipe_ex1  # term1
cat > pipe_ex1  # term2

Ahora lo que escribibimos en term1 aparece en term2 pero no al revés.

# PREGUNTA 2
Desde distintas shells NO, dado que las "pipes sin nombre" se aprovechan de la FDT.
Es decir, para que se puedan comunicar, deben ser parientes (Utuilizan la herencia).

Cuando nostros estamos en la shell (que ya es un proceso) todos los comandos ejecutados son hijos.
Entonces, desde la misma shell SI que podemos.

# PREGUNTA 3
Primer hem de fer close del STDIN, per a alliberar el FD.
Això no perd la relació que 0 continui sent l'estandard, donat que fd és l'index de la taula i això no varia.
Llavors per defecte, continuarà buscant-se fd = 0, pero FDT[fd] apuntarà al dispositiu logic 4 en comptes de al 0.
És possible perque dup() busca l'index més petit no fet servir.
```
// Alliberar STDIN
close(0);

// Relacionar entrada escriptura de pipe sense nom amb STDIN
// FDT[0] = 4;
dup(4);
```

# PREGUNTA 4
## createSocket
1. Primer creem un socket que permet la comunicació només entre procesos del sistema.
Ho farem amb protocol IP.

2. Una vegada el socket s'ha creat correctament, associem una direcció a aquest.
Aquesta serà la passada com a paràmetre.

3. Finalment diem que aquest socket que acabem de crear, serà per a escoltar.

Retorna el fd creat.

## serverConnection
Li passem el fd del socket que hem creat que esta en mode escolta i pot ser te alguna petició.
Si aquest socket té algun pending, crea un nou socket amb una comunicació bidireccional.
Ara per a intercanviar informació, fem ús del nou socket.
PD1 : Noves peticions de la mateixa persona faran nous sockets.
PD2 : El fd passat com argument continua estant en mode escolta.