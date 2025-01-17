# PREGUNTA 1
## PUNTO 1
Podemos saberlo ejecutando el comando `df -T`
"""
Filesystem     Type  1K-blocks     Used Available Use% Mounted on
tmpfs          tmpfs    400540     1804    398736   1% /run
/dev/sda1      ext4   28723236 16651840  10587008  62% /
tmpfs          tmpfs   2002684    17364   1985320   1% /dev/shm
tmpfs          tmpfs      5120        4      5116   1% /run/lock
tmpfs          tmpfs    400536      164    400372   1% /run/user/1001
"""

## PUNTO 2
Para saber el numero de inodos libres y los utilizados podemos usar el comando `df -i`
"""
Filesystem      Inodes  IUsed   IFree IUse% Mounted on
tmpfs           500671   1080  499591    1% /run
/dev/sda1      1835008 365430 1469578   20% /
tmpfs           500671     76  500595    1% /dev/shm
tmpfs           500671      4  500667    1% /run/lock
tmpfs           100134    191   99943    1% /run/user/1001
"""

## PUNTO 3
Para saber el espacio libre de un sistema de ficheros podemo usar el comando `df -l`
[//]: En este caso estamos viendo de los sistemas de ficheros locales.
"""
Filesystem     1K-blocks     Used Available Use% Mounted on
tmpfs             400540     1804    398736   1% /run
/dev/sda1       28723236 16651888  10586960  62% /
tmpfs            2002684    16960   1985724   1% /dev/shm
tmpfs               5120        4      5116   1% /run/lock
tmpfs             400536      164    400372   1% /run/user/1001
"""

# PREGUNTA 2
## PUNTO 1
El que tiene el mismo inodo es el hardlink dado que ambos ficheros "pr.txt" y hl_pr apuntan al mismo fichero fisico.
Esto no sucede con sl_pr porque este solo apunta al puntero que apunta al inodo de pr.txt

### sl_pr
Softlink (Acceso Directo).
"""
  File: sl_pr -> pr.txt
  Size: 6         	Blocks: 0          IO Block: 4096   symbolic link
Device: 801h/2049d	Inode: 1059147     Links: 1
Access: (0777/lrwxrwxrwx)  Uid: ( 1001/  alumne)   Gid: ( 1001/  alumne)
Access: 2024-12-08 16:13:59.360250448 +0100
Modify: 2024-12-08 16:13:58.772250489 +0100
Change: 2024-12-08 16:13:58.772250489 +0100
 Birth: 2024-12-08 16:13:58.772250489 +0100
"""

### hl_pr
Hardlink.
"""
  File: hl_pr
  Size: 19        	Blocks: 8          IO Block: 4096   regular file
Device: 801h/2049d	Inode: 1059137     Links: 2
Access: (0664/-rw-rw-r--)  Uid: ( 1001/  alumne)   Gid: ( 1001/  alumne)
Access: 2024-12-08 16:13:48.276251206 +0100
Modify: 2024-12-08 16:13:48.276251206 +0100
Change: 2024-12-08 16:14:04.628250093 +0100
 Birth: 2024-12-08 16:13:48.276251206 +0100
"""

## PUNTO 2
### cat
No hay diferencia dado que ambos estan mostrando el contenido del fichero pr.txt.

### namei
Lo que hace este comando es seguir el rastro de un fichero hasta que encuentra "fin".
En este caso, el sl_pr es un fichero que apunta a otro fichero, no es el "fin" por si mismo.
De lo contrario, hl_pr, aunque siga siendo un link, este apunta directamente al inodo original.

### readlink
Permite ver el path al que apunta el Softlink.
No veremos resultado en el hardlink porque este no apunta a otro directorio, es el fichero como tal.

## PUNTO 3
Al eliminar el fichero "pr.txt" el softlink no sabra donde apuntar. 
Seguira existiendo pero apunta a un fichero que no existe.
De lo contrario, hardlink sigue apuntado al inodo del fichero aunque se haya eliminado el original.
