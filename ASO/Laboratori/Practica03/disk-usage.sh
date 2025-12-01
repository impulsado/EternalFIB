#!/bin/bash

space_limit=""
space_limit_num=""
space_limit_type=""
disk_usage=""
disk_usage_kb=""

function print_help()
{
    echo "Invalid format"
    echo "./disk-usage.sh [-g grup_name] <space_limit>"
    echo "space_limit = int[bkMG]"
    exit 1
}

function calcDisckUsage()
{
    # IMPO: "-xdev" es important perque no sumi altres sistemes de fitxers (donat que estan muntat per root)
    for file_size in $(find / -xdev -type f -user $1 -printf "%s\\n" 2>/dev/null); do
        disk_usage=$(($disk_usage + $file_size))
    done

    return 0
}

function notifyUser()
{
    return 0
}

# === MAIN ===
# Base Case
if [[ $# -ne 1 && $# -ne 3 ]]; then
    print_help
fi

if [[ $# -eq 3 && $1 != "-g" ]]; then
    print_help
fi

# General Case
if [[ $# -eq 1 ]]; then
    space_limit=$1
else
    space_limit=$3
fi

space_limit_num=${space_limit::-1}
space_limit_type=${space_limit: -1}

case "$space_limit_type" in
    "b")
        space_limit=$space_limit_num
        ;;
    "k")
        space_limit=$(echo "$space_limit_num*1000" | bc)
        ;;
    "M")
        space_limit=$(echo "$space_limit_num*1000000" | bc)
        ;;
    "G")
        space_limit=$(echo "$space_limit_num*1000000000" | bc)
        ;;
    *)
        print_help
        ;;
esac

for user in $(cut -d: -f1 /etc/passwd); do
    disk_usage=0
    calcDisckUsage "$user"

    if [[ $disk_usage -gt $space_limit ]]; then
        notifyUser "$user"
    fi

    disk_usage_kb=$(echo "$disk_usage/1000" | bc)
    echo "$user $disk_usage_kb kB"
done