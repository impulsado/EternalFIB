NOM GRUP: YO18

# Preguntes
## P1
mkdir {S1,S2,S3,S4,S5}

## P2
ls
ls -a

## P3
ls -l
permissions,num_links,owner,owner_group,file_size,last_mod,name

## P4
Visualitza > Mostra fitxers ocults
Visualitza > Mode de vista > Detalls
Visualitza > Mostra informació adicional > Altres > Permisos, Propietari, Grup Propietari

## P5
rm -r S1
find S1
mkdir S1

## P6
La diferència és que al "cat" mostra tot el contingut a la terminal i, si ocupa més que tota la teva panatalla, només veus el final. En cas contrari, "less" ""obre"" un programa que et permet visualitzar des de l'inici i anar baixant per pàgines i quan etiguis llest, pots sortir amb 'q' i reprendre l'intèrpret de comandes.
Si volguessis tenir un comportament "similar" podries fer servir "cat test3.txt | more"

## P7
-i : "prompt before overwrite"
Això significa que si al fer el "cp", al destí, ja hi ha un fitxer que es diu igual, preguntarà si vols sobreescriure.

alias cp='cp -i'

## P8
### rm
-i : "prompt before any removal"
Això significa que abans d'eliminar qualsevol arxiu (directori/fitxer) preguntarà si estàs segur.

alias rm='rm -i'
### mv
-i : "prompt before overwrite"
Això signifa que si al moure un arxiu (directori/fitxer), al destí, hi ha un mateix arxiu amb el mateix nom, sortirà un prompt preguntant si estàs segur.

## P9
cat f1 --> OK
chmod ugo=w f1
cat f1 --> S'ha denegat el permís
chmod ugo=r f1
rm f1
En aquesta última comanda ens surt si volem eliminar un fitxer buit protegit contra escriptura (per què només té per lectura), però si fiques "S" de "Si" ja et deixa eliminar-ho.

## P10
PATH: Llistat de directoris on la shell cerca per comandes.
HOME: Directori "principal" de l'usuari actual.
PWD: Nom del directori actual on s'esta treballant.

## P11
Quan fem "echo $PATH" podem veure que els directoris estàn separats per ":"

## P12
export glob_var_1=1
export glob_var_2=2
echo $glob_var_1
echo $glob_var_2

## P13
S'ha executat el "ls" que tinc el el directori actual.
"which ls" --> "/dades/pau.bru/Documents/ls"

## P14
Si que està definit en el PATH per què ho hem fet al afegir "." en aquesta.
Això significa que al executar una comanda, la shell primer buscarà si, en el directori actual, hi ha algún programa amb aquest nom. Altrament, buscarà en els altres directoris definits en el PATH.

## Com modificar PATH
Hi ha diverses formes de fer-ho:
1. Amb "awk" o "set" que serveixen per manipular text desde la terminal.
2. Recarregar la variable $PATH fent un "source /etc/profile"
3. Copiar només el que t'interessa i assignar de nou amb un "export PATH=[directoris que interessen]"

## P15
En aquest cas s'ha executat el "ls" que es la comanda definida pel sistema per què el bash troba primer en un dels directoris previs al "." un programa que es diu "ls".

## P16
">" sobreesciu el contingut i ">>" fa append al fitxer, sense sobre escriure.
