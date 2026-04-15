#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "provide 2 args" >&2;
    exit 1
fi

if [[ ! -f "$1" || ! -f "$2" || ! -r "$1" ]]; then
    echo "not readable file">&2
    exit 2
fi

filename=$(basename "$2" | sed -E 's:(.*)\.[a-z0-9]+$:\1:')

cfg="$1"

while IFS= read -r line; do
    lang=$(echo $line| cut -d' ' -f1)
    dir=$(echo $line | awk '{print $NF}' | sed -E "s:^'(.*)'$:\1:")
    types=$(echo $line | awk '{
        for(i=2;i<NF;i++) {
            if ($i == 2){
            answer=$i
            }else{
            answer = answer " " $i
            }
        }
    } END {print answer}' | sed -E "s/^ *//;s/ *$//")

    listener="-no-listener"
    visitor=""
    for arg in $types; do
        if [[ "$arg" =~ "visitor" ]]; then
            visitor="-visitor"
        elif [[ "$arg" =~ "listener" ]]; then
            listener=""
        elif [[ "$arg" != "recognizer" ]]; then
            echo "invalid type ${arg}" >&2
        fi
    done

    query="antlr4 -Dlanguage=${lang} ${visitor} ${listener} -o ${dir}/${filename} ${2}"
    query=$(echo "$query" | tr -s ' ')
    $query

done < "$cfg"

