#!/bin/bash

num=10

if [[ "$1" =~ ^-n$ ]]; then
    if [[ ! "$2" =~ [1-9]+[0-9]* ]]; then
        echo 'provide a number' >&2
        exit 1
    else
        num=$2
    fi
    shift 2
fi

tempfile=$(mktemp)

for arg in "$@"; do

idf=$(basename "$arg" .log)

awk -F ' ' -v name="$idf" '{
timestamp=$1 " " $2
data=""

for(i=3;i<=NF;i++){
if(i==3){
    data = data " "
}
data=data $i
}

print timestamp " " name " " data
}' "$arg" | tail -n $num >> $tempfile

done

sort -k1,1 -k2,2 $tempfile

rm -f $tempfile
