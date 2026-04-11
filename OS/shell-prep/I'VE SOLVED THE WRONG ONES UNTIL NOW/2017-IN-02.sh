#!/bin/bash

if [[ ${UID} -ne 0 ]]; then
    echo 'needs to be executed as root'
    exit 1
fi

if [[ ${#} -ne 3 ]]; then
    echo 'provide exactly 3 arguments'
    exit 2
fi

if [[ ! -d "${1}" || ! -d "${2}" ]]; then
    echo 'not a valid dir argument/s'
    exit 3
fi

SRC=$1
DST=$2
ABC=$3

while read -r file; do
    newloc=$(echo $file | sed "s:^${SRC}:${DST}:")
    mkdir -p "$(dirname "${newloc}")"
    mv $file $newloc
done < <(find "${SRC}" -type f -name "*${ABC}*")
