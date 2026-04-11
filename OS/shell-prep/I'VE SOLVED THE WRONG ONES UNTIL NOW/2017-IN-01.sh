#!/bin/bash

if [[ ${#} -ne 3 ]]; then
    echo 'provide exactly 3 arguments'
    exit 1
fi

if [[ ! -f "${1}" ]]; then
    echo 'not a valid file argument'
    exit 2
fi

tempfile1=$(mktemp)
tempfile2=$(mktemp)

terms1=$(grep -E "^${2}=.*" "${1}" | cut -d '=' -f2)
terms2=$(grep -E "^${3}=.*" "${1}" | cut -d '=' -f2)

echo "$terms1" | tr ' ' '\n' | sort | uniq > $tempfile1
echo "$terms2" | tr ' ' '\n' | sort | uniq > $tempfile2

val2=$(comm -13 $tempfile1 $tempfile2 | tr '\n' ' ')

sed -i "s/^${3}=.*/${3}=${val2}/g" "$1"

rm -f $tempfile1
rm -f $tempfile2
