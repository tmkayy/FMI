#!/bin/bash

if [[  ${#} -ne 2 ]]; then
    echo 'provide exactly 2 arguments'
    exit 1
fi

if [[ ! "${1}" =~ ^[1-9]*[0-9]+$ || ! "${2}" =~ ^[1-9]*[0-9]+$  ]]; then
    echo 'provide 2 positive integers'
    exit 2
fi

mkdir -p {a,b,c}

while IFS= read -r file; do
    numlines=$(wc -l < "${file}")
    if [[ ${numlines} -lt "${1}" ]]; then
        mv "${file}" a/
    elif [[ ${numlines} -ge "${1}" && ${numlines} -le "${2}" ]]; then
        mv "${file}" b/
    else
        mv "${file}" c/
    fi
done < <(find . -type f -maxdepth 1)
