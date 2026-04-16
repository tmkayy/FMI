#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo 'incorrect use of script'>&2
    exit 1
fi

ugroup=$(stat -c '%G' "$1")
ugroups=$(groups)

if [[ ${UID} -eq 0 ]]; then
    while read -r file; do
        chgrp "$ugroup" "$file"
        chmod ug+rw,o-rwx "$file"
    done< <(find "$1" -type f)

    while read -r dir; do
        chmod ug+rwx,o-rwx "$dir"
    done< <(find "$1" -type d)
elif echo "$ugroups" | grep -Eq "\b${ugroup}\b"; then
    umask 0007
else
    echo 'you dont have the right'>&2
    exit 2
fi
