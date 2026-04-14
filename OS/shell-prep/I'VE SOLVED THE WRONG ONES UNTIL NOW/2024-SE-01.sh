#!/bin/bash

files=$(mktemp)
dict=$(mktemp)

for arg in "$@"; do
    if [[ ! "$arg" =~ -R[a-zA-Z0-9]+=[a-zA-Z0-9]*$ ]]; then
        if [[ ! -f "$arg" || ! -r "$arg"|| ! -w "$arg" ]]; then
            echo "${arg} is not a writeable and readable file or a valid replacement arg" >&2
            exit 1
        fi
        echo "$arg" >> $files
    fi
done

sort -uo "$files" "$files"

for arg in "$@"; do
    if [[ "$arg" =~ -R[a-zA-Z0-9]+=[a-zA-Z0-9]*$ ]]; then
        placehol=$(pwgen 20 1)
        cleanline=$(echo "$arg" | cut -c 3-)
        toreplace=$(echo "$cleanline" | cut -d '=' -f1)
        replacewith=$(echo "$cleanline" | cut -d '=' -f2)

        while read file; do
            #dude what
            sed -i "/^#/!s/\b$toreplace\b/$placehol/g" "$file"
        done< <(cat "$files")

        echo "${placehol} ${replacewith}" >> "$dict"
    fi
done

while read placehol replacewith; do
    while read file; do
            sed -i "s/\b$placehol\b/$replacewith/g" "$file"
    done< <(cat "$files")
done< <(cat "$dict")



rm -f "$files" "$dict"
