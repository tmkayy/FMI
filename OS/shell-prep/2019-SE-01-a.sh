#!/bin/bash

max_abs=0
temp=$(mktemp)

while IFS= read -r line; do
    if [[ "$line" =~ ^-?[1-9]+[0-9]*$ ]]; then
        echo "$line" >> "$temp"

        if [[ "$line" -lt 0 ]]; then
            abs_value=$(( line * -1 ))
        else
            abs_value=$line
        fi

        if [[ "$abs_value" -gt "$max_abs" ]]; then
            max_abs=$abs_value
        fi
    fi
done

sort -n "$temp" | uniq > "${temp}.uniq"
mv "${temp}.uniq" "$temp"

while IFS= read -r line; do
    if [[ "$line" -lt 0 ]]; then
            abs_value=$(( line * -1 ))
    else
            abs_value=$line
    fi
    if [[ "$abs_value" -eq "$max_abs" ]]; then
        echo "$line"
    fi
done < "$temp"

rm -f "$temp"
