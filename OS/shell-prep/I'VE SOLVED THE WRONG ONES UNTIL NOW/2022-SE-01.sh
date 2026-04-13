#!/bin/bash

wakeup="/proc/acpi/wakeup"

if [[ $# -ne 1 ]]; then
    echo "wrong amount of arguments" >&2
    exit 1
fi

if [[ ! -f "$1" || ! -r "$1" ]]; then
    echo "not a readable file" >&2
    exit 2
fi

config="$1"

while IFS= read -r line; do
    line=$(echo $line | sed 's/#.*//')
    device=$(echo $line | awk '{print $1}')
    status=$(echo $line | awk '{print $2}')

    if [[ -z "$device" || -z "$status" ]]; then
        continue
    fi

    if grep -q "^${device}" "$wakeup"; then
        currstatus=$(awk -v dev="$device" '{
        if($1==dev){
            print $3
        }
        }' "$wakeup" | tr -d '*' )
        if [[ $currstatus == $status ]]; then
            echo "${device} is already $status"
        else
            echo $device > "$wakeup"
        fi
    else
        echo "${device} not found in $wakeup" >&2
        continue
    fi

done < "$config"
