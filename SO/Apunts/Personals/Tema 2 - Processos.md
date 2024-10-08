## Seqüencials v.s. Concurrents
### Sequencial
```C
for (i = 0; i<num_hijos; i++) {
	int pid = fork();
	if (pid == 0) {
		printf("HIJO: %d PID", pid);
		exit(0);
	}
	waitpid(pid, NULL)  // Esperar a la mort del fill
	}
```