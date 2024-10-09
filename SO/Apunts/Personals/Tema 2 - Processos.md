# Conceptes

**PCB (Process Control Bank)**
Conté informació que el sistema necessita per gestionar un procés.
Depen del sistema i de la màquina (NO portable).
- Espai d'adreces: (1) Codi, pila, dades, ...
- Context d'execució:
	- (2) Software: PID, planificació, informació sobre l'ús del dispositiu, ...
	- (3) Hardware: TLB, PC, ...

**Concurrència**
"Paral·lelisme Virtual". Permet executar diversos processos de forma simultània.

**Fils d'execució (Threads)**
"Thread"/"Subprocés" és una seqüencia de tasques encadenades molt petita.
Un fil és una tasca que pot ser executada a l'hora a

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
