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
![[Pasted image 20241013175251.png]]

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
S'esta executant Procés A -> 
SO decideix que s'ha d'executar Procés B -> 
Es guarda en la PCB del Procés A la informació -> 
Es carrega la PCB del Procés B -> 
S'executa Procés B.
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
Grau de paral·lelisme: Nº processos paral·lels. Depen del HW + Nº processos.

**Estats d'un procés**
Un procés no pot estar tota l'estona executant-se.
És per això que hi ha una classificació dels estats.
![[Pasted image 20241013171546.png]]

# Gestió de Processos
## Creació de Processos
Cada procés té el seu PID que l'identifica.
Quan un procés crea un altre, ho fa de forma jeràrquica (Arbre).
### fork();
Procés pare **crea** un procés fill que còpia exacta seva en el moment de la crida.
En el procés pare es retorna el pid del fill.
En el procés fill es retorna 0.
Pare i fill s'executen de forma concurrent (Tots dos a l'hora) i de forma independent des del mateix punt de crida.
❗És genera una nova àrea de memòria per al fill que és una **còpia** de la del pare.
```C
int pid;
pid = fork();
if (pid < 0) {
	perror("fork() ha fallat!");
	return 1;
}
else if (pid == 0) {
	printf("FILL: El meu PID és %d\n", getpid());  // Saber el PID que li ha donat el SO
	printf("FILL: El del meu pare és %d\n", getppid());  // Saber el PID del pare
}
else {
	printf("PARE: El meu PID és %d\n", getpid());  // Saber el PID que li ha donat el SO
	printf("PARE: El del mey fill és %d\n",pid);  // Quan s'executa fork() retorna automàticament el PID del fill, tot i que no hagi acabat.
}
printf("PARE/FILL: Adeu!");
```

| Fill HEREDA                | Fill NO HEREDA                 |
| -------------------------- | ------------------------------ |
| Codi, dades, pila, ...     | PID, PPID                      |
| **Programació de signals** | Comptadors Interns             |
| **Màscara de signals**     | **Alarmes i Signals pendents** |
| USERID, GROUPID            |                                |
| Dispositius Virtuals       |                                |
| Variables d'Entorn         |                                |
- **Dispositius virtuals**: Són descriptors de fitxers oberts que representen interfaces per a comunicar-se amb arxius, sockets, pipes, ... Per exemple si pare te un handler per a un fitxer obert, el fill té una copia d'aquest (El punter al fitxer és el mateix). Això significa que tant pare/fill poden llegir/escriure al mateix fitxer en temps real, però si algún tanca el seu file descriptor, no afectarà a l'altre.
- **Programació de signals**: Taula que especifica com tractar cada signal. Posterior al fork(), poden modificar aquesta taula de forma independent sense afectar-se.
- **Màscara de signals**: Determina quins signals estan allow/block. Més info. després.

## Mutació d'executable
### execlp(...);
**Reemplaça** el procés actual amb un nou procés especificat i l'executa.
1. Un programa s'executa i té valors en els seus registres.
2. Aquest programa executa un `execlp(...)` i si és exitòs, l'espai de direcció és reemplaça completament (codi i dades). Llavors els registers de la CPU es reinicien per adaptar-se a aquest nou programa. Això implica que NO és mantenen.
3. Si ``execlp(...)`` falla, aquest retorna al seu estat anterior (procés original), mantenint registres i espai de direcció intactes. Llavors el procés original executa el codi posterior.
4. Si `execlp()` acaba exitosament, no retorna al procés original.

Donat que es canvia l'espai de direccions, el procés "nou" que s'està executant no pot accedir a les dades del procés "original".

- **Canvia**: L'espai de direccions, codi, dades, PC, ...
- **No Canvia**: PID, Recursos Oberts, Signals pendents, ...

❗**NO** crea un nou procés. ❗**NO** canvia el context. 

```C
/* FORMAT */
execlp("ls", "ls", "-la", NULL);
// 1. Busca "ls" en tots els programes que hi hagi en el $PATH
// 2. Carrega la resta d'arguments.
// 2.1. El primer argument (0) en un programa sempre és el nom d'aquest mateix.
// 2.2. El segon argument (1) son les opcions que volem executar al programa
// 3. Fiquem NULL per marcar el final de la llista de paràmetres.
```

```C
// OK
execl("temp.x", "temp.x", NULL);
execl("./temp.x", "temp.x", NULL);
execlp("./temp.x", "temp.x", NULL);
// KO
execlp("temp.x", "temp.x", NULL);  // Cuidado amb el "./"
```
[//]: Normalment voldrem crear un fill i que aquest executi ``execlp(...)`` perquè quan acabi l'execució d'aquest "nou" procés, el fill morirà i el procés principal (pare) continua.

## Esperar a un Procés
Si volem que un procés pare esperi al fill, podem fer servir funcions de la familia `wait`.
Normalment s'utilitza per a sincronitzar processos.
Aquesta funció retorna el PID del fill que ha acabat.
```C
/* FROMAT */
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);
```
- **pid**: Número de procés que ha d'esperar.
	- `-1`: Esperar fins que mori el primer fill. No importa quin sigui.
	- `pid`: Espera fins que mori aquest fill determinat.
- **\*status**: Punter a variable del tipus int on guardare el valor d'acabament del procés.
	- `NULL`: No guardar el valor de retorn.
	- ``&status``: Guarda el valor a la variable ``int status``.
- **options**: Determinar comportament que ha de tindre el procés mentre espera.
	- `0`: Atura't i espera fins que mori el fill.
	- ``WNOHANG``: Si el fill encara esta viu, la funció retorna automàticament i continua amb l'execució. No espera.

[//]: ``wait(&st);`` és el mateix que ``waitpid(-1, &st, 0);``

```C
// Esperar fins que no hi hagin més fills vius
while (waitpid(-1,NULL,0)>0);
// `-1` fa que esperi la mort de qualsevol fill.
// `NULL` fa que no guardi el valor de retorn.
// `0` fa que esperi fins la mort
// Quan no quedin més fills que esperar, waitpid retornarà -1 i sortirà del bucle.
```

## Acabar amb Procés
Un procés pot acabar:
- **Voluntàriament**: Hi ha un ``exit``. S'alliberen recursos i PCB que tenia.
- **Involuntàriament**: Un signal "el mata".

```C
/* FORMAT */
void exit(int status);
```

| exit(int status);        | \_exit(int status);    |
| ------------------------ | ---------------------- |
| Funció de llibreria de C | Syscall                |
| Realitza "neteja"        | Acaba de forma abrupta |
[//]: Mentre que pare no consulta si fill ha mort, el PCB es manté. Normalment es fa ús de ``waitpid(...)``.
[//]: Si pare ha mort abans que acabin els fills, `init` els hereda.

### Gestió d'acabament
Saber **com** ha mort:
- `WIFEXITED(status)`: Saber si procés ha mort per `exit(status)`.
- ``WIFSIGNALED(status)``: Saber si procés ha mort per signal.

Saber **causa exacta** de la mort:
- `WEXITSTATUS(status)`: Saber número del `exit()`. Agafa uns determinats bits del ``status``.
- `WTERMSIG(status)`: Saber quin signal ha matat al procés.

❗**SEMPRE** haurem de controlar com acaben els nostres programes.

```C
/* FORMAT DE TRACTAMENT*/
void treatDeath(int status) {
    if (WIFEXITED(status)) {
        // Mort normal amb exit(status);
        int exit_code = WEXITSTATUS(status);
        printf("Ha mort per culpa d'un exit() amb exit_code = %d\n", exit_code);
    }
    else if (WIFSIGNALED(status)) {
        // Mort per signal
        int signal_code = WTERMSIG(status);
        printf("Ha mort per culpa d'un signal amb signal_code = %d\n", signal_code);
    }
    else {
        // Altres que encara no hem vist
    }
}
```

## Seqüencials v.s. Concurrents
```ad-attention
El que importa és ON fas el ``waitpid(...)``;
- **DINS == SEQÜENCIAL**: El procés pare (el que genera els fill) estarà esperant fins que fill acabi.
- **FORA == CONCURRENT**: El procés pare genera tots els fills i després ja esperarà fins que tots acabin.
```
[//]: Sempre que en el ``waitpid(...)`` fiquem l'opció ``0``.
### Seqüencial
Fins que no ha mort el fill, el pare espera. 
```C
int i;
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
Es generen X processos que s'executen "a l'hora". Poden estar tots actius.
❗**NO** és sinònim d'arbre de processos. 
```C
int i;
for (i = 0; i<num_fills; i++) {
	int pid = fork();
	if (pid == 0) {
		printf("FILL: Tinc el PID %d", pid);
		exit(0); 
	}
}
int pid_child;
while ((pid_child = waitpid(-1,NULL,0)) > 0) {
	printf("PARE: Ha mort el fill amb PID: %d", pid_child);
}
```

## Esquema disseny programa
![[Pasted image 20241014112517.png]]

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
Procés executa codi -> 
Rep un signal -> 
Interromp l'execució d'aquest codi -> 
Salta al handler associat al signal -> 
Executa el handler -> 
Quan acaba (si sobreviu) continua on estava. 
```

[//]: Recorda que un event és un succés que requereix atenció. Llavors un signal és una forma específica d'event.

## Tipus de Signals
"SIGUSR1" i "SIGUSR2" són signals que no estan relacionats a un esdeveniment específic.
❗"SIGKILL" i "SIGSTOP" **NO** son bloquejables ni capturable. 
❗"SIGSEGV", "SIGILL", "SIGFPE" **NO** és poden bloquejar si son per culpa d'una excepció, però si que es poden gestionar.
Normalment el bloqueig d'un signal és temporal.
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
int kill(int pid, int signal);
```

### struct sigaction;
- **sa_handler**: Especificar tractament que volem (Handler).
	- `SIG_IGN`: Ignorar signal rebut.
	- `SIG_DFL`: Handler per defecte.
	- `custom_handler`: Kernel executa funció específica. El SO s'encarrega de passar el nº de signal. Això permet que diversos signals pugin fer servir mateixa funció.
- **sa_mask**: Màscara de signals que volem {Block/Allow}. Fa un OR de la màscara prèvia (Manté els bloquejats previs).
	- Buida: Només bloqueja el signal que s'està tractant.
	- En acabar el handler, es restaura la ``sa_mask`` prèvia.
- **sa_flags**: Configurar opcions adicional que modifiquen com es comporta el handler.
	- `0`: Configuració per defecte.
	- `SA_RESETHAND`: Post-tractament, es restaura el handler per defecte.
	- `SA_RESTART`: Reiniciar "syscall" si és interrompuda pel mateix signal, "reiniciar" la syscall. 

### sigaction(...);
```C
int sigaction(int signum, struct sigaction *new_sa,
            struct sigaction *old_sa);
```
[//]: `old_sa` pot ser NULL.

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
// És comú bloquejar el propi signal que tractarem
sigemptyset(&sa.sa_mask);  // No bloquejar cap
sigaddset(&sa.sa_mask, SIGCHLD);  // Bloquejar SIGCHLD mentre custom_handler
sigaddset(&sa.sa_mask, SIGINT);  // Bloquejar SIGINT mentre custom_handler

// Aplicar la configuració a SIGCHLD (Mort d'un fill)
if (sigaction(SIGCHLD, &sa, NULL) == 0) {
	perror("ERROR: Ha fallat el sigaction()\n");
}
```

### {Block/Unblock} signals
```C
int sigprocmask(int operation, sigset_t *new_mask, sigset_t *old_mask);
```
Les operacions que es poden fer són:
- `SIG_BLOCK`: **Afegir** els signals de la nova a la màscara vella.
- ``SIG_UNBLOCK``: **Treure** els signals indicats en la nova màscara.
- `SIG_SETMASK`: **Canviar** la màscara vella per la nova.

### Esperar Signal
1. La màscara de signals canvia de forma temporal (sense alterar l'original).
2. El procés queda suspès (Bloquejat) i espera fins que arribi un signal que no estigui bloquejada per la màscara temporal (``mask<SIGNUM> == 0``).
3. Quan el rep, el procés desperta. Executa el handler específic i la màscara es restaura.

[//]: Ús freqüent per evitar `race conditions`.

```C
int sigsuspend(sigset_t *temp_mask);
```

### Manipulació de la màscara
```C
sigset_t mask;  // Iniciar màscara
sigemptyset(&mask);  // Buida
sigfillset(&mask);  // Plena
sigaddset(&mask, SIGNUM);  // Afegir bloqueig del signal (mask<SIGNUM> = 1)
sigdelset(&mask, SIGNUM);  // Treure bloqueig del signal (mask<SIGNUM> = 0)
sigismember(&mask, SIGNUM);  // Saber si esta block (true) o no (false).
```

## Sincronització entre processos
### Activa
**Consumeix CPU** així que fer-ho servir quan saps que has d'esperar poc.
```C
void config_esperar_alarma() {
	alarma = 0;
}

void esperar_alarma() {
	while (alarma != 1)
}
```

# Gestió Interna de Processos
Per gestionar els processos necessitem:
- **Estructures de dades**: 
	- Representar propietats i recursos --> PCB
	- Representar i gestionar threads --> Depen del SO
- **Estructures de gestió**: Organitzar els PCB's en funció del seu estat o necessitats del SO. Normalment són llistes i cues, però poden haver arbres, hash maps, ...
- **Algorisme/s de planificació**: Com gestionar les estructures.
- **Mecanismes**: Apliquin les decisions.

## PCB
Informació associada a cada procés.  
Depèn del sistema (NO PORTABLE).
- **PID:** El sistema necessita saber a quin procés ens referim.
- **USERID, GROUPID:** Saber quins permisos té el procés per evitar que accedeixi a qualsevol recurs.
- **Estat: RUN, READY, ...:** Necessitem saber en quin estat està el procés si ha estat interromput.
- **Espai per guardar registres de la CPU:** Mantenir el context del procés tot i que hi hagi canvis.
- **Dades per gestionar signals:** Facilitar la comunicació i la resposta a esdeveniments.
- **Informació sobre la planificació:** Determinar l'ordre d'execució; sense això, el SO seria poc eficient.
- **Informació de gestió de memòria:** Controla l'assignació i l'ús de memòria; sense això, podrien haver conflictes o errors de segmentació.
- **Informació sobre gestió de l'E/S:** Permet que els processos interaccionin correctament amb els dispositius d'entrada/sortida.
- **Accounting:** Monitoritzar i controlar els recursos utilitzats; seria impossible gestionar eficientment els recursos.

## Planificació
### Estructures
Depèn del SO, hi ha tipus d'estructures diferents.
Per exemple: Hi ha diverses cues, depenent l'estat i el SO va movent els processos entre cues.
- **Cua de processos**: Tots els processos creats pel sistema.
- **Cua de processos READY**.
- **Cua de processos SLEEPING**.

### Planificació
Gestiona l'ús de la CPU: Qui s'executa, Qui surt d'estar executant-se, Quant de temps, ...
Cada X temps, en la interrupció de rellotge, es comprova (Evitar monopoli de CPU).
- **No Preemptiva**: Procés s'executa fins que acaba o passa a "SLEEPING". (FIFO)
[//]: El SO "no modifica" l'estat del procés.
- **Preemptiva**: El SO "permet" la CPU a un procés durant X temps. Si aquest es passa del temps, el SO el passa a "READY" i fica un altre. (Round Robbin).

### Tipus de processos
- **Processos de Càlcul**: Temps Computació > E/S.
- **Processos d'E/S**: Temps Computació < E/S.

### Mecanismes
**Context Switching**: Procés ha de deixar la CPU i s'ha de carregar un altre.
[//]: Aquest canvi de context s'executa en mode kernel.
1. Guardar la informació del procés actual en la seva PCB i passa a estar en "READY".
2. Planificador escull quin es el següent procés.
3. Es carrega la PCB del nou procés i aquest està en "RUN".

❗Aquest canvi es un temps **NO ÚTIL** de l'aplicació --> Ha de ser ràpid.

### Mètriques
**Turnaround Time**: Temps **TOTAL** (En tots els estats) des de que procés arriba al SO fins que acaba.
**Temps d'espera**: Suma del temps que el procés ha estat en "READY".

### Round Robbin
Temps es subdivideix en intervals fixos anomenats `quantums`. $10 \leq q \leq 100$ mil·lisegons.
Cada procés rep el mateix `quantum`.
Processos s'organitzen en una cua circular (Request Queue) --> No importa la prioritat.
Quan a un procés se li acaba el seu ``quantum`` (i no ha acabat) el scheduler l'interromp i realitza "Context Switching".
Esdeveniments que activen el Round Robbin:
- **RUN --> SLEEPING**: Procés passa al final de la cua de "SLEEPING" fins que acaba E/S. (No preemptiu)
- **RUN --> ZOMBIE**: Procés acaba amb la seva execució. (No preemtiu)
- **S'acaba el quantum**: Procés passa al final de la cua de "READY". (Preemtiu)

Cap procés espera més de $(N-1)*q$ mil·lisegons. $N$ nº processos i $q$ quantum.
- $q$ GRAN --> **Ordre Seqüencial**.
- $q$ petit --> **Overhead** si el context switching és costós.