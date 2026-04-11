#!/bin/bash

if [[ ${#} -ne 2 ]]; then
    echo 'enter dir and arch'
    exit 1
fi

if [[ ! -d ${1} ]]; then
    echo "${1} is not a valid dir"
    exit 2
fi

if [[ ! -r ${1} ]]; then
    echo "${1} is not a valid dir"
    exit 3
fi

DIR=$1
ARCH=$2
tempfile=$(mktemp)

while read -r file; do
    filename="$(basename "$file")"
    if [[ $filename =~ ^vmlinuz-[0-9]+\.[0-9]+\.[0-9]+-${ARCH}$ ]]; then
        echo $filename >> $tempfile
    fi
done < <(find $DIR -type f -maxdepth 1)

latestandgreatest=$(cat "$tempfile" | sort -V | tail -n 1)
echo $latestandgreatest

rm -f $tempfile
