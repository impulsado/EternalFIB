#!/bin/bash

# === TEORIA ===
# $# : argc (No te en compte el nom del script)
# $* : argv
# $0 : name of the script
# $1 : first param
# shift : $i = $i+1 (moure params per accedir a $10 que no es pot pero ara sera $9) 

# ==================
# GLOBAL VARIABLES
# ==================
global_user=""
global_time=""
global_days=""

# ==================
# FUNCTIONS
# ==================
function print_help
{
    echo "Usage: $0 [ options ] "
    echo "Possible options: "
    echo "-t time "
}

function hasProcesses
{
    # Buscar quantitat (wc -l) de processos que te l'usuari (-u $user)
    local user_proc=$(($(ps -u "$global_user" 2>/dev/null | wc -l) - 1))  # -1 per treure el header
    
    # No te processos
    if [[ "$user_proc" -eq 0 ]]; then
        return 0
    fi

    # Si te processos
    return 1
}

function formatDate
{
    # NOTA: Estem com treballant $1 que equival al primer parametre dins la funcio
    # ${variable:position:length}
    # ${variable::-1} --> Treure ultim caracter
    # ${variable: -1} --> Agafar ultim caracter
    local num=${1::-1}
    local units=${1: -1}
    
    case "$units" in
        "d") 
            units="days" 
            global_days=$(( $num * 1 ))
            ;;
        "w") 
            units="weeks" 
            global_days=$(( $num * 7 ))
            ;;
        "m") 
            units="months"
            global_days=$(( $num * 30 ))
            ;;
        "y") 
            units="years"
            global_days=$(( $num * 365 ))
            ;;
        *) 
            echo "Invalid time format"
            exit 1 
            ;;
    esac
    

    global_time=$(date -d "$num $units ago" +"%Y-%m-%d %H:%M:%S")
    return 0
}

function hasLoggedIn
{
    local num_of_logins=$(($(wtmpdb last "$global_user" --since "$global_time" | wc -l) - 2))  # -2 perque hi ha 2 linies fixes sempre

    if [[ "$num_of_logins" -le 0 ]]; then
        return 0
    fi

    return 1
}

function hasModifiedFiles
{
    # '-' --> less
    # '+' --> more

    local num_modified=$(find / -user "$global_user" -atime "-$global_days" 2>/dev/null | wc -l)

    if [[ "$num_modified" -eq 0 ]]; then
        return 0
    fi

    return 1
}

function baseCase
{
    # Max 2 param
    if [[ "$#" -ne 2 ]]; then
        print_help
        exit 1
    fi

    # Invalid param
    if [[ "$1" != "-t" ]]; then
        print_help
        exit 1
    fi

    return 0
}


# ==================
# MAIN
# ==================

for user in $(cat /etc/passwd | cut -d: -f1); do
    # === BASE CASE
    baseCase "$@"  # Passar a baseCase tot l'array d'arguments

    # === GENERAL CASE
    global_user=$user

    hasProcesses 
    if [[ "$?" -eq 1 ]]; then
        continue  # Te processos --> No es inactiu
    fi

    formatDate "$2"  # Passar a formatDate el temps que ha introduit usuari

    hasLoggedIn
    if [ "$?" -eq 1 ]; then
        continue
    fi

    hasModifiedFiles
    if [ "$?" -eq 1 ]; then
        continue
    fi 

    echo "$user"
done