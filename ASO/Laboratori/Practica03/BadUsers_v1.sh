#!/bin/bash
p=0  # -p: Considerar valids als que tenen processos (No llistarlos)

# === TEORIA ===
# $# : argc (No te en compte el nom del script)
# $* : argv
# $0 : name of the script
# $1 : first param
# shift : $i = $i+1 (moure params per accedir a $10 que no es pot pero ara sera $9) 


# Funcio help
function print_help
{
    echo "Usage: $0 [ options ] "
    echo "Possible options: "
    echo "-p validate users with running process "
}

# === Base Case
# Te mes d'un argument
if [ $# -gt 1 ]; then
    print_help $0
    exit
fi

# Mentre el argc > 0 --> p = 1 (tota l'estona)
# Aixo nomes es repeteix 1 vegada perque nomes hi ha 1 param i "shift" fa argc--
while [ $# -gt 0 ]; do
    case $1 in
        "-p")
            p=1
            shift;; 
        *)
            # default
            echo "Error: not valid option : $1"
            exit 1;; 
    esac
done

for user in $(cat /etc/passwd | cut -d: -f1) ; do
    home=$(cat /etc/passwd | grep "^$user:" | cut -d: -f6)
    # cat --> Mostrar tots els usuaris
    # grep --> Agafar tota la fila nomes de l'usuari que estem tractant
    # cut --> agafar el home del usuari
        # -d el delimitador es ':'
        # -f el item num 6
    
    if [ -d "$home" ]; then
        # El busquem quant. (wc -l) fitxers (-type f) que te l'usuari (-user $user) dins del seu home ("$home")
        # wc -l compta el numero de linies --> num de fitxers trobats
        num_fich=$(find "$home" -type f -user $user 2>/dev/null | wc -l)
    else
        num_fich=0
    fi

    if [ $num_fich -eq 0 ]; then
        if [ "$p" -eq 1 ]; then
            # Buscar quantitat (wc -l) de processos que te l'usuari (-u $user)
            user_proc=$($(ps -u $user | wc -l) - 1);  # -1 per treure el header
            if [ "$user_proc" -eq 0 ]; then
                echo "$user"
            fi
        else
            echo "$user"
        fi
    fi
done