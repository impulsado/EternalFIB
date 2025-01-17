Sesión        4: Preparación Previa
Sobre alarm1:
Pregunta 1
Cuando pasan 5 segundos no ocurre nada porque la alarma está programada para 10 segundos. El programa se queda en “SUSPENDED” hasta que suene.


Pregunta 2
El comportamiento es el mismo porque en ambos casos el proceso acaba. El mensaje que se muestra es distinto, en este caso “Killed”.


Pregunta 3
El proceso encargado es el shell. Esto es por qué este se encarga de ejecutar el “./alarm1” y espera a que acabe. Cuando acaba, si lo mata un signal, muestra que signal lo ha matado.
Para recoger el estado de finalización de un proceso, la shell utiliza `waitpid(pid,&status,NULL);`


Pregunta 4
No hace falta porque el tratamiento por defecto de SIGALRM, SIGINT es hacer un exit(x) y al tener el sigsuspend antes del exit(1), jamás llegaremos a este.


Sobre alarm2:
Pregunta 1
Cada vez que {Suena una alarma/Se envia signal de alarma} el contador de segundos += 10; haciendo que cada vez se acerque más a la condición final del while.


Pregunta 2
No se puede modificar el tratamiento de cualquier señal.
SIGKILL y SIGSTOP NO son capturables (tampoco bloqueables).


Pregunta 3
void funcion_alarma (int s) {
  int seg_pendents = alarm(0);
  if (seg_pendents%10 != 0) {
        printf("ALARMA DE KILL\n");
        return;
  }
  char buff[256];
  segundos = segundos + 10;
  sprintf (buff, "ALARMA pid=%d: %d segundos\n", getpid (), segundos);
  write (1, buff, strlen (buff));
}

Sobre alarm3:
Pregunta 1
Tanto el padre como el hijo ejecutan el handler de la alarma porque la alarma se configura después del fork(). El hijo la trata igual que el padre porque al hacer “fork()” se hereda tanto la mascara como el tratamiento de los signals (pero los signals no).
Si movemos “alarm(10)” antes del fork, la alarma se asocia al padre. El hijo se crea, pero este se queda “infinito” en el sigsupend().


Sobre alarm4:
El padre se queda en un sigsuspend infinito porque no hay ninguna alarma previamente programada. El hijo cada 10 segundos ejecuta el handler hasta que sea 100 el tiempo acumulado.
Para evitar que el padre se quede en bucle infinito, solo hay que poner en el switch pid>=0
y ahora ambos harán alarma.
Sobre ejemplo_waitpid:
Pregunta 2
Todos mueren por exit porque el handler del SIGALRM es no hacer nada y post sigsuspend hay un exit(0).
while (hijos > 0) {
      pid = waitpid (-1, &res, 0);
      sprintf (buff, "Termina el proceso %d\n", pid);
      write (1, buff, strlen (buff));
      hijos--;
      contador++;
      if (WIFEXITED(res)) printf("Muerto por EXIT\n");
      else if (WIFSIGNALED(res)) printf("Muerto por SIGNAL\n");
}

Pregunta 3


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>


/*
=== IMPORTANTE ===
No es seguro usar printf() dentro de los handlers porque no es considerada una funcion "segura"
Pero yo lo he usado para facilitar la lectura y en este ejercicio no era tan importante.
*/


int vPids[10];
int hijos_activos = 0;


void error_y_exit (char *msg, int exit_status) {
    perror (msg);
    exit (exit_status);
}


void custom_handler(int SIGNUM) {
    if (SIGNUM == SIGALRM) {
        int i;
        for (i = 0; i<10; i++) {
            if (vPids[i] != -1) {
                hijos_activos--;
                kill(vPids[i], SIGKILL);
            }
            printf("PADRE: He matado a %d\n", vPids[i]);
        }
        exit(0);
    }
    else if (SIGNUM == SIGCHLD) {
        int pid,i;
        int tiempo_restante = alarm(0);
        printf("PADRE: Te quedaban %d segundos restantes",tiempo_restante);
        while ((pid = waitpid(-1,NULL,0))>0) {
            for (i = 0; i<10; i++) {
                if (vPids[i]==pid) {
                    vPids[i] = -1;
                    hijos_activos--;
                    printf("PADRE: He recibido la muerte de %d\n", pid);
                    break;
                }
            }
        }
    }
}


void hijo_alarma(int SIGNUM) {
    // NO HACER NADA
}


int main(void) {
    char buff[256];
    sigset_t mask;
    struct sigaction sa;
    int pid, hijo;
    
    // Evitar que arribi una alarma/mori fill abans del sigsuspend
    sigemptyset (&mask);
    sigaddset (&mask, SIGALRM);
    sigaddset (&mask, SIGCHLD);
    sigprocmask (SIG_BLOCK, &mask, NULL);
    
    for (hijo = 0; hijo<10; hijo++) {
        pid = fork();
        if (pid<0) error_y_exit("ERROR: Crear Hijo\n",1);
        else if (pid > 0) {
            vPids[hijo] = pid;
            hijos_activos++;
        }
        else {
            sa.sa_handler = hijo_alarma;
            sa.sa_flags = SA_RESTART;
            sigfillset (&sa.sa_mask);
            if (sigaction (SIGALRM, &sa, NULL) < 0) error_y_exit ("sigaction", 1);


            /* Escribe aqui el codigo del proceso hijo */
            sprintf (buff, "Hola, soy %d\n", getpid ());
            write (1, buff, strlen (buff));


            alarm (1);
            sigfillset (&mask);
            sigdelset (&mask, SIGALRM);
            sigdelset (&mask, SIGINT);
            sigsuspend (&mask);


            /* Termina su ejecución */
            exit (0);
        }
    }


    sa.sa_handler = custom_handler;
    sigfillset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGCHLD,&sa,NULL);
    sigaction(SIGALRM,&sa,NULL);


    sigset_t mascara;
    sigfillset(&mascara);
    sigdelset(&mascara,SIGCHLD);
    sigdelset(&mascara,SIGALRM);
    
    alarm(2);
    while (hijos_activos>0) sigsuspend(&mascara);


    return 0;
}


