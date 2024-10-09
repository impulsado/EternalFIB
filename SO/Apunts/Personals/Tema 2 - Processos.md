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
Grau de concurrència: Nº processos concurrents. Només depen del Nº processos.

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
[//]: L'altre procés ha de ser del mateix usuari.

Un signal es pot:
- **Bloquejar**: Evitar que el procés rebi signal (Els ignori).
- **Capturar**: Modificar la forma, per defecte, de com es gestiona.

Els farem servir per:
- **Sincronització de processos**
- **Control de temps** (alarmes)

```
Procés executa codi -> Rep un signal -> Interromp l'execució d'aquest codi -> Salta al handler associat al signal -> Executa el handler -> Quan acaba (si sobreviu) continua on estava. 
```

[//]: Recorda que un event és un succés que requereix atenció. Llavors un signal és una forma específica d'event.

## Tipus de Signals
"SIGUSR1" i "SIGUSR2" són signals que no estan relacionats a un esdeveniment específic.
❗"SIGKILL" i "SIGSTOP" **NO** son bloquejables ni capturable. 
❗"SIGSEGV", "SIGILL", "SIGFPE" **NO** és poden bloquejar si son per culpa d'una excepció, però si que es poden gestionar.
Normalment el bloqueig d'un signal es temporal. Dins el mateix procés hi ha un bloqueig i desbloqueig.
Si un procés bloqueja X signal, no el rep i el SO el marca com a pendent de tractar. Quan aquest mateix procés el desbloqueja aquest X signal, el rebrà i el tractarà.
Per determinar quins signals bloqueja i quins permet, es fa ús de la estructura de dades `sigset_t` (màscara de senyals).

| SIGNAL      | TRACTAMENT DEFAULT | EVENT                                                   | CAPTURABLE? | BLOCK?                                   |
| ----------- | ------------------ | ------------------------------------------------------- | ----------- | ---------------------------------------- |
| **SIGCHLD** | Ignore             | Procés fill ha acabat o ha estat aturat.                | SI          | SI                                       |
| **SIGCONT** | -                  | Continua si estava aturat                               | SI          | SI                                       |
| **SIGSTOP** | Stop               | Atura el procés                                         | NO          | NO                                       |
| **SIGINT**  | Terminate          | Ctrl + C                                                | SI          | SI                                       |
| **SIGALRM** | Terminate          | Temporitzador definit per la funció `alarm()` ha acabat | SI          | SI                                       |
| **SIGKILL** | Terminate          | Matar el procés                                         | NO          | NO                                       |
| **SIGSEGV** | Core               | Invalid Memory Reference                                | SI          | Si és per excepció = NO. Altrament = SI. |
| **SIGUSR1** | Terminate          | Definit per l'usuari                                    | SI          | SI                                       |
| **SIGUSR2** | Terminate          | Definit per l'usuari                                    | SI          | SI                                       |

## Funcions
- `kill`: Enviar signal. No ha de perquè matar.
- `sigaction`: Canviar el tractament d'un signal específic.
- `sigprocmask`: Bloquejar/Desbloquejar signals. (Depen de l'opció).
- `sigsuspend`: Canvia la màscara per la passada com a parametre i susp