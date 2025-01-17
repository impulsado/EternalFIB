GRUPO: YO18

# SO-LAB-PREV3
## Ejecuta ejemplo_fork1
'''
Soy el proceso 6748
Soy el proceso 6749
'''
No lo podemos saber por qué el sistema no nos asegura que, como se están ejecutando diversas cosas a la vez, primero sea el hijo y luego el padre o viceversa.

## Ejecuta ejemplo_fork2
'''
Antes del fork: Soy el proceso 7799
PADRE: Soy el proceso 7799
Los DOS: Soy el proceso 7799
HIJO: Soy el proceso 7800
Los DOS: Soy el proceso 7800
'''
Podemos observar que aquí se está ejecutando parte del código del padre que debería de haberse ejecutado después de que muriese el hijo (línea 3). Esto nos verifica la respuesta anterior del ejemplo_fork1.
En este caso, primero muestra el PID del padre, luego, gracias al Switch() sabemos identificar quien es el padre y mostrar un texto custom, y luego lo hace el hijo.

## Ejecuta ejemplo_fork3
'''
Antes del fork: Soy el proceso 7937
PADRE: Soy el proceso 7937
Solo lo ejecuta el padre: Soy el proceso 7937
HIJO: Soy el proceso 7938
'''
En este caso el padre empieza ejecutando la línea que escribe su PID (antes del fork)
Después se ejecuta el frok() y se entra en el switch() y como está dentro del proceso hijo y este tiene un PID=0, ejecuta el primer caso y termina.
Finalmente, entra el padre al switch() y como su PID es distinto de 0 y -1, ejecuta el último caso.
Cuando salimos del switch(), esas últimas instrucciones las ejecuta el padre porque el hijo ha muerto en el switch().

## Ejecuta ejemplo_fork4
'''
Antes del fork: Soy el proceso 8149
PADRE: Soy el proceso 8149
Solo lo ejecuta el padre: Soy el proceso 8149
HIJO: Soy el proceso 8150
HIJO acaba: Soy el proceso 8150
'''
Aquí lo que pasa es que, el padre empieza ejecutándose y no hay ninguna instrucción que le haga esperar a la muerte del hijo. Entonces el hijo tarda demasiado en morir, el padre muere (ejecutando previamente lo que deba de ejecutar). El proceso hijo que ha quedado huérfano, es adoptado por "init" y cuando acaba el bucle muestra el texto por pantalla, muere.

Para esperar a que el padre espere la muerte del hijo antes de morir él, deberemos ejecutar un waitpid() con la opción 0 para que espere.

En mi caso lo he puesto después del switch() 'waitpid(pid,NULL,0); /* Esperar a que hijo muera y ya, sin guardar nada */' y me cambia el resultado a:
'''
Antes del fork: Soy el proceso 8517
PADRE: Soy el proceso 8517
HIJO: Soy el proceso 8518
HIJO acaba: Soy el proceso 8518
Solo lo ejecuta el padre: Soy el proceso 8517
'''

## Ejecuta ejemplo_fork5
'''
Antes del fork: Soy el proceso 8696
PADRE: Soy el proceso 8696
HIJO: Soy el proceso 8697
HIJO:La variable_global vale A y la local a
PADRE:La variable_global vale A y la local a
Solo lo ejecuta el padre: Soy el proceso 8696
'''
Ahora la muerte de los procesos es igual al orden que hemos corregido en el ejemplo anterior. Es decir, hasta que no muere el hijo, no muere el padre gracias al waitpid(). En este caso se ha configurado con un '-1' que indica que espere la muerte del primer hijo, da igual quien, y como solo hay un hijo, el comportamiento es el mismo.
Respecto al tema de las variables, en ambos procesos (padre e hijo) valen lo mismo porque en ningún momento se modifican y porque el hijo hereda los valores de las variables que tiene el padre en el momento previo de hacer el fork().
Notar que si desde el hijo se cambia el valor a alguna variable, da igual si es global o local, el padre no va a notar los cambios.

'''
Antes del fork: Soy el proceso 8946
PADRE: Soy el proceso 8946
HIJO: Soy el proceso 8947
HIJO:La variable_global vale H y la local h
PADRE:La variable_global vale A y la local a
Solo lo ejecuta el padre: Soy el proceso 8946
'''

## Ejecuta ejemplo_fork6
Descripcion del formato:
"[PADRE/HIJO]:La variabe_global vale variable_global++"
Este mensaje lo escribirán 10 mil veces el padre y 10 mil el hijo y cada 1 mil cambiará el valor de variable_global siendo esta incrementada 10 veces hasta 'K'/'k'.

Porque:
Observamos que dentro de cada bucle de cambio de variable, se ejecutara 10 veces. Primero incrementando y luego mostrando por pantalla (La 'A'/'a' nunca se mostrarán).
Como NO hay un waitpid, no se nos asegura que el padre ejecute su código después de la muerte del hijo. Es decir, NO podemos asegurar que siempre se ejecute el código de la misma manera. Además, el PID cambia así que seguro que el contenido JAMÁS será el mismo.

## Modifica el fichero Makefile.ejemplos
El problema está en que estamos tratando de acceder a una variable local de main desde una función que no es esta misma. Entonces en el contexto de la función "Escribe_variables()" no sabe que es "variable_local".
Para solucionarlo modificamos la cabecera de la función para que reciba esta variable como parámetro y añadimos "variable_local" como parámetro en todas las llamadas de función en main.

## Ejecuta ejemplo_exec1
Este programa primero muestra por pantalla el PID del proceso padre.
Luego ejecuta el comando 'ls' con el parámetro '-l' y esto hace cambiar el espacio de memoria, código, PC,...
Si el 'execlp' no falla, no se ejecutará todo el código posterior a la llamada, haciendo así que el PID del proceso solo se muestre 1 vez.

## Ejecuta ejemplo_exec2
En este caso pasa igual que el anterior, primero se muestra el PID del "ejemplo_exec2", luego se llama al programa "ejemplo_fork1" SIN CREAR UN NUEVO PROCESO y este printa el mismo PID que el de "ejemplo_exec2". Posteriormente este programa "ejemplo_fork1" si que crea un nuevo proceso hijo con el fork() y el PID_hijo se muestra por pantalla.
Como la ejecución del programa es exitosa, el programa principal "ejemplo_exec2" no acaba ejecutando nada posterior a 'execlp()'.

## Consulta en el man
Me ha hecho falta consultar el man de waitpid para saber que includes hacía falta hacer para modificar el fork4 y eso estaba en "SYNOPSIS".
