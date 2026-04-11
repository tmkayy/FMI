#!/bin/bash

if [[ ! ${USER} =~ ^root$ ]]; then
    printf "you dont have the right, oh you dont have the right\ntherefore\n you dont have the right, oh you dont have the right"
    exit 1
fi

while IFS=: read -r user homedir; do
    if [[ ! -d "$homedir" ]]; then
        echo "$user's $homedir homedir doesnt exist"
    elif [[ ! -w "$homedir" ]]; then
        echo "$user cannot write in his homedir: $homedir"
    fi
done < <(cut -d ':' -f1,6 /etc/passwd)
