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
Cada vegada que es crea un nou procés es genera un PCB associat. 
En aquesta estructura de dades es guarda "tota" la informació del programa.
Depen del sistema i de la màquina (NO portable).
- Espai d'adreces: (1) Codi, pila, dades, ...
- Context d'execució:
	- (2) Software: PID, planificació, informació sobre l'ús del dispositiu, ...
	- (3) Hardware: TLB, PC, ...

```
Procés A, Procés B;
S'executa Procés A -> SO decideix que s'ha d'executar Procés B -> Es guarda en la PCB del Procés A la informació -> Es carrega la PCB del Procés B -> S'executa Procés B.
```

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
- [ ] FICAR IMATGE

# Gestió de Processos
## Creació de Processos
Cada procés té el seu PID que l'identifica.
Quan un procés crea un altre, ho fa de forma jeràrquica (Arbre).
### fork();
Procés pare genera un procés fill que còpia exacta seva en el moment de la crida.
Pare i fill s'executen de forma concurrent (Tots dos a l'hora) i de forma independent des del mateix punt de crida.
❗És genera una nova àrea de memòria per al fill que és una **còpia** de la del pare.
```C
int ret;
pid = fork();
if (pid < 0) {
	perror("fork() ha fallat!");
	return 1;
}
else if (pid == 0) {
	// Només ho executa el fill.
}
else {
	// Només ho executa el pare.
}
```

## Seqüencials v.s. Concurrents
### Seqüencial
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

### Concurrents
![[Pasted image 20241010085724.png]]

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
- `kill(...)`: Enviar signal. No ha de perquè matar.
- `sigaction(...)`: Canviar el tractament d'un signal específic.
- `sigprocmask(...)`: Canviar màscara per la passada com a paràmetre. Pot {Bloquejar, Desbloquejar} els signals depenent de l'opció.
- `sigsuspend(...)`: Canvia la màscara per la passada com a paràmetre i suspèn el procés fins rebre un signal no bloquejat.
- `alarm(...)`: Programar l'enviament automàtic del signal "SIGALARM". Només pot haver 1 configurada a l'hora.

[//]: `struct sigaction sa` Defineix **com gestionar** un signal (configuració). 
[//]: `sigaction(...)` **Aplica la configuració** a un signal específic.

### kill(...);
```C
kill(int pid, int signal);
```

### struct sigaction;
- **sa_handler**: Especificar tractament que volem (Handler).
	- `SIG_IGN`: Ignorar signal rebut.
	- `SIG_DFL`: Handler per defecte.
	- `custom_handler`: Kernel executa funció específica. El SO s'encarrega de passar el nº de signal. Això permet que diversos signals pugin fer servir mateixa funció.
- **sa_mask**: Màscara de signals que volem {Block/Allow}. Fa un OR de la màscara prèvia (Manté els bloquejats previs).
	- Buida: Només bloqueja el signal que s'està tractant.
	- A l'acabar el handler, es restaura la sa_mask prèvia.
- **sa_flags**: Configurar opcions adicional que modifiquen com es comporta el handler.
	- `SA_RESETHAND`: Post-tractament, es restaura el handler per defecte.
	- `SA_RESTART`: Reiniciar "syscall" si és interrompuda pel mateix signal, "reiniciar" la syscall. 

### sigaction(...);


### Exemple de "struct sigaction" + "sigaction(...)"
Configurar un handler específic que executarà el pare quan mori un fill. Mentre s'executa aquest ``custom_handler`` no pot ser acabat (Terminate) per un Ctrl+C.
```C
void custom_handler(int sig_num);

struct sigaction sa;
// Handler específic
sa.handler = custom_handler;
// Més opcions del comportament del Handler
sa.sa_flags = SA_RESTART;
// Signals block durant execució del Handler
sigemptyset(&sa.sa_mask);  // Només block el signal que s'està tractant
sigaddset(&sa.sa_mask, SIGINT);  // Afegir el bloqueig del SIGINT mentre custom_handler

// Aplicar la configuració a SIGCHLD (Mort d'un fill)
if (sigaction(SIGCHLD, &sa, NULL) == -1) {

}


```