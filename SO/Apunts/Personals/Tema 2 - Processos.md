## PCB
Conté informació que el sistema necessita per gestionar un procés.
Depén del sistema i e l
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
