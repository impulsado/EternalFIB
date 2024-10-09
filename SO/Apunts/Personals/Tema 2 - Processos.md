# Conceptes
**Procés**
Representació del SO d'un programa en execució.
[//]: Quan executem un programa -> Crea un procés.

**Programa**
Codi i definició de dades que al ficar-ho en execució necessitem:
- Assig. memòria per a codi, pila i dades.
- Inicialitzar registres de la CPU.
- Oferir accés als dispositius. (Interactuar amb teclat, pantalla, ...)

[//]: Si un programa és simplement una suma de dos números i ja, el SO continua havent d'assignar memòria i inicialitzar registres. 

![[programa.png]]

**PCB (Process Control Bank)**
Conté informació que el sistema necessita per gestionar un procés.
Depen del sistema i de la màquina (NO portable).
- Espai d'adreces: (1) Codi, pila, dades, ...
- Context d'execució:
	- (2) Software: PID, planificació, informació sobre l'ús del dispositiu, ...
	- (3) Hardware: TLB, PC, ...

**Concurrència**
"Paral·lelisme Virtual". Permet executar diversos processos de forma simultània.
Grau de concurrència: Nº processos concurrents. Només depen del nº processos.

**Fils d'execució (Threads)**
"Thread"/"Subprocés" és una seqüència de tasques encadenades.
Un procés està format per:
- Recursos: Memòria, Fitxers, Permisos, ...
- Threads: Unitats d'execució que fan ús d'aquests recursos. (Pot ser 1 o +)
Un fil és una tasca que pot ser executada a l'hora amb una altra tasca. (Fer ús paral·lelisme).
Els fils comparteixen mateixos recursos, llavors els permet intercanviar informació sense ús de crides a sistema.
Grau de paral·lelisme: Nº processos paral·lels. Depen del HW+ Nº processos.

**Estats d'un procés**
Un procés no pot estar tota l'estona executant-se.
És per això que hi ha una classificació dels estats.


# Gestió de Processos
## Seqüencials v.s. Concurrents
### Sequencial
Fins que no mor un fill, no pasa a  
```C
for (i = 0; i<num_hijos; i++) {
	int pid = fork();
	if (pid == 0) {
		printf("HIJO: %d PID", pid);
		exit(0);
	}
	waitpid(pid, NULL, 0);  // Esperar a la mort del fill
}
```

# Signals
Notificar events a un procés. Pot enviar-ho {Kernel, Altre procés}. 
L'altre procés ha de ser del mateix usuari.
La comanda `kill` envia un signal, no ha de perquè matar. 
