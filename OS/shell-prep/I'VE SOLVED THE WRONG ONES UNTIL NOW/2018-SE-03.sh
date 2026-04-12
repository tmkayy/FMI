#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo 'provide 2 args' >&2
    exit 1
fi

if [[ ! "${1}" =~ ^.*\.csv$ || ! "${2}" =~ ^.*\.csv$ ]]; then
    echo 'invalid file type. provide csv' >&2
    exit 2
fi

if [[ ! -f "$1" ]]; then
    echo "${1} is not a file" >&2
    exit 3
fi

if [[ ! -r "$1" ]]; then
    echo "${1} is not a readable file" >&2
    exit 4
fi

awk -F ',' '
{
    key=""
    for(i=2; i<=NF; i++){
        if (i>2){
            key =key ","
        }
        key = key $i
    }

    if (min_id[key]=="" || $1 < min_id[key]){
        min_id[key] = $1
        result[key] = $0
    }
}
END {
    for (key in result){
        print result[key]
    }
}
' "$1" > "$2"
