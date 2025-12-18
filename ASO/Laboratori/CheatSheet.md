Autor: @impulsado

# ASO LAB CHEATSHEET

## Índex
- [Disc i Particions](#disc-i-particions)
  - [Llistar](#llistar)
  - [Desmontar](#desmontar)
  - [Crear Partició (GPT amb gdisk)](#crear-partició-gpt-amb-gdisk)
  - [Montar Partició](#montar-partició)
  - [SWAP](#swap)
  - [Arreglar GRUB (Recovery)](#arreglar-grub-recovery)
- [Xarxa](#xarxa-ifupdown)
- [Backups (SFTP + tar)](#backups-sftp--tar)
  - [Descarregar backups](#descarregar-backups)
  - [Restaurar backup](#restaurar-backup)
  - [Crear backups (find → tar)](#crear-backups-find--tar)
- [Usuaris i Grups](#usuaris-i-grups)
- [Permissos](#permissos)
- [Instal·lar Apps](#installar-apps-tarball)
- [General](#general)
  - [sudo](#sudo)
  - [Quotes](#quotes)
- [Scripts (plantilles)](#scripts-plantilles)

## Disc i Particions
### Llistar
```sh
lsblk 
sudo fdisk -l 
findmnt
```

### Desmontar
```sh
sudo umount /dev/sdXN
# o (si tens el punt de muntatge):
sudo umount <dir>
```

### Crear Particio (GPT)
```sh
sudo gdisk /dev/sdX 
# n (new)
# <enter> (default)
# <enter> (default)
# {+,-}size{K,M,G}
# t (type) * Veure taula
# w (write)
sudo partprobe /dev/sdX
lsblk
```

| Code | Name |
| --- | --- |
| EF00 | EFI system partition |
| 8304 | Linux x86-64 root (/) |
| 8300 | Linux filesystem |
| 8302 | Linux /home |
| 8200 | Linux swap | 
| 8300 | Linux filesystem |

### Montar Particio

#### Temporal
```sh
sudo mkfs -t <type> /dev/sdXN
sudo mkdir -p <dir> 
sudo mount /dev/sdXN <dir>
findmnt <dir>
```

#### Persistent
```sh
sudo blkid /dev/sdXN
sudo nano /etc/fstab
# Afegir: UUID=<uuid>  <dir>  ext4  defaults  0  2
sudo mount -a
findmnt <dir>
```

### SWAP
> **IMPORTANT**: Primer crear la partició i tipus. (* Veure [Crear Particio](#crear-particio-gpt))
#### Temporal
```sh
sudo mkswap /dev/sdXN
sudo swapon /dev/sdXN
swapon --show
```

#### Persistent
```sh
sudo blkid /dev/sdXN
sudo nano /etc/fstab
# Afegir: UUID=<uuid_swap>  none  swap  sw  0  0
sudo swapon -a
swapon --show
```

### Arreglar GRUB (Recovery)
> **IMPORTANT**: El `/dev/sdX` ens referim al directori ROOT ("/") que estem fent servir ara i hem d'arreglar 

0. Idenitificar si `UEFI` o `BIOS`
```sh
ls /sys/firmware/efi/  # Si existeix --> UEFI
```

1. Identificar directori ROOT
```sh
lsblk -f
```

2. Crear punts de muntatge perque sistema sapigui arrancar (ROOT)
```sh
sudo mkdir -p /mnt
sudo mount /dev/sdXY /mnt  # partició on hi ha "/"
```

3. (Només si existeixen particions separades) Muntar punts extra
```sh
# /boot separat:
sudo mkdir -p /mnt/boot
sudo mount /dev/sdXZ /mnt/boot

# si UEFI i hi ha ESP (vfat):
sudo mkdir -p /mnt/boot/efi
sudo mount /dev/sdXW /mnt/boot/efi

# /home separat:
sudo mkdir -p /mnt/home
sudo mount /dev/sdXH /mnt/home

# /usr/local separat:
sudo mkdir -p /mnt/usr/local
sudo mount /dev/sdXL /mnt/usr/local
```

3. Bind mounts + chroot
```sh
for i in /dev /dev/pts /proc /sys /run; do sudo mount --bind $i /mnt$i; done
sudo chroot /mnt
```

3. Reinstal·lar GRUB en disc (NO particio)
```sh
grub-install --target=x86_64-efi /dev/sdX  # Disc de "sdXY" anterior
update-grub
```

4. Canviem contrasenyes a usuaris
```sh
sudo passwd root
sudo passwd <nom>
```

5. Sortim i desmuntem (en ordre invers)
```sh
exit
for i in /run /sys /proc /dev; do sudo umount /mnt$i; done
# Si els hem afegit:
sudo umount /mnt/usr/local
sudo umount /mnt/home
sudo umount /mnt/boot/efi
sudo umount /mnt/boot
# Aquest SEMPRE:
sudo umount /mnt
```

6. Reiniciem si es demana
```sh
sudo shutdown -r now
```

---

## Xarxa
0. Identifiquem el nom de la interficie
```sh
ip -br a
```

1. Editem el fitxer de configuracio
```sh
sudo nano /etc/network/interfaces
```

2. Afegim la configuracio

DHCP
```text
auto <int name>
iface <int name> inet dhcp
```

STATIC
```text
auto <int name>
iface <int name> inet static
    address <IPv4>
    netmask <MASK>
    gateway <IP_GW>
```

3. Reiniciem el servei
```sh
sudo ip l s dev <int name> down && sudo ip l s dev <int name> up
# si falla:
sudo systemctl restart networking
```

---

## Backups

### Descarregar backups
```sh
sudo mkdir -p /backups
cd /backups
sftp <user>@asoserver.pc.ac.upc.edu
# dins ftp:
#   cd <dir>
#   get *.tar.*
#   bye
```

### Restaurar backup
> NOTA: Pot ser fa falta instal·lar `xz-utils`

#### Cas A: "Restaurar dins ROOT "
```sh
cd /
# Triar segons extensio:
sudo tar -xf /backups/home_xxx.tar # .tar
sudo tar -xJf /backups/home_xxx.tar.xz # .tar.xz
sudo tar -xzf /backups/home_xxx.tar.gz  # .tar.gz
sudo tar -xjf /backups/home_xxx.tar.bz2  # .tar.bz2
```

#### Cas B: "Restaurar dins DIRECTORY
```sh
dir=<nom_directori_desti>
sudo mkdir -p $dir
sudo tar -xJf /backups/home_xxx.tar.xz -C $dir # o l'extensio corresponent
```

#### Comprovar restauracio
```sh
tar -tf /backups/home_xxx.tar | head
# o:
tar -tJf /backups/home_xxx.tar.xz | head
```

### Crear Backups (find --> tar)
> NOTA: Si ens diuen nomes fitxers `find -type f` <br>
> NOTA: `-p` preserva permisos

#### Exemple 1 "Fitxers modificats últimes 24h"
```sh
dir=<dir>
ts=$(date +%Y%m%d-%H%M)
sudo find "$dir" -type f -mtime -1 -print0 | sudo tar --null -cpzf "/backups/backup-$ts.tar.gz" --files-from -
```

#### Exemple 2: "Fitxers d’un usuari dins d’un directori"
```sh
dir=<nom_directori_a_fer>
user=<nom_usuari>
sudo find "$dir" -type f -user "$user" -print0 | sudo tar --null -cpjf "/backups/backup-$user.tar.bz2" --files-from -
```

## Usuaris i Grups
### Grup
```sh
sudo groupadd -g <GID> <group>
# si no et donen GID:
sudo groupadd <group>
```

### Usuari
```sh
sudo useradd -u <UID> -m -d <home_user> -g <main_group> -G <g1>,<g2> <user>
sudo passwd <user>
```

Comprovar-ho:
```sh
id <user>
getent passwd <user>
getent group <group>
```

Afegir usuari a un grup (sense treure altres grups):
```sh
sudo usermod -aG <group> <user>
```

---

## Permissos
```sh
sudo chown [-R] <user>:<group> <dir>
sudo chmod <special><owner><group><other> <dir>
```

### special (sumar)
| Num | Perm |
| --- | --- |
| 4 | SetUID |
| 2 | SetGID |
| 1 | StickyBit |

---

## Instal·lar Apps
1. Preparacio
```sh
mkdir -p ~/src && cd ~/src
```

2. Descarregar (* Veure [Descarregar backups](#descarregar-backups))

3. Descomprimir
```sh
tar -xf  <nom>.tar
tar -xJf <nom>.tar.xz
tar -xjf <nom>.tar.bz2
tar -xzf <nom>.tar.gz
cd <nom>*/
```

4. Preparar + Compilar + Instal·lar
```sh
./configure --prefix=<dest>  # "/usr/local/<app>" o "/opt/<app>"
make
sudo make install
```
**IMPORTANT**: Pot ser que falli --> Buscar per internet quina llibreria instal·lar

5. Evitar escribire el path complet

SOFTLINK
```sh
sudo ln -s <dest>/<app>/bin/<cmd> /usr/local/bin/<cmd>
<cmd> --help
```

PATH
```sh
echo 'export PATH=<dir>/<app>/bin:$PATH' >> ~/.bashrc
source ~/.bashrc  # Actualitzar
```

---

## General

### sudo
1. Instal·lar `sudo`
```sh
su -
apt update
apt install sudo
```

2. Configurar usuaris
```sh
visudo  # Executar com a root
# Afegir:
# <user> ALL=(ALL:ALL) ALL
```

Alternativa (si el sistema usa el grup sudo):
```sh
sudo usermod -aG sudo <user>
```

### Quotes
1. Instal·lar eina
```sh
sudo apt update
sudo apt install quota
```

2. Activar quota al filesystem de \<dir> (editar fstab)
```sh
sudo nano /etc/fstab
# a la línia del filesystem: afegir a options -> usrquota
# (si també grups: usrquota,grpquota)
```

3. Remuntar + Preparar + Activar quota
```sh
sudo mount -o remount <dir>
sudo quotacheck -cum <dir>
sudo quotaon -v <dir>
```

4. Posar limit

OPCIÓ 1: Interactiu
```sh
sudo edquota -u <user>
```

```sh
soft=num{G,M,K}
hard=num{G,M,K}
sudo setquota -u <user> $soft $hard 0 0 <dir>
sudo repquota -s <dir> | head
```

---

## Scripts
NOTA: Aquesta seccio es per agafar idees d'altres anys

### 10 processos amb més temps CPU
```sh
ps -eo pid=,user=,time= --sort=-time | head -n 10 \
| while read -r pid usr t; do
    exe=$(readlink -f "/proc/$pid/exe" 2>/dev/null || echo "?")
    echo "$pid $usr $t $exe"
  done
```

### RSS total usuari
```sh
u="$1"
ps -u "$u" -o rss= | awk -v u="$u" '{s+=$1} END{printf "User %s is using a total of %dbytes of memory\n", u, s*1024}'
```

### Top 5 processos per memoria usuari
```sh
u="$1"
ps -u "$u" -o pid= --sort=-rss | head -n 5 \
| while read -r p; do readlink -f "/proc/$p/exe"; done
```

### Process que consumeix més memòria
```sh
ps -eo pmem,comm --sort=-pmem | head -n 2 | tail -n 1
```

### Llistar processos amb més d’un N% de memòria (flag -l N)
```sh
N="$2"
ps -eo pmem,comm --sort=-pmem \
| awk -v N="$N" '$1>=N {printf "%d %s\n", $1, $2}'
```

### Usuaris connectats + comptes desactivats
```sh
who | wc -l
awk -F: '$7 ~ /(nologin|false)$/ {c++} END{print c+0}' /etc/passwd
```

### Mostrar missatge a cada terminal (bash)
```sh
echo '/path/al/script.sh' >> ~/.bashrc
# o mostrar fitxer:
echo 'cat /var/lib/last_chrome 2>/dev/null' >> ~/.bashrc
```

### Executar cada X (cron)
```sh
crontab -e
# afegir:
# 15 */4 * * * /path/al/latest_chrome_version.sh
```