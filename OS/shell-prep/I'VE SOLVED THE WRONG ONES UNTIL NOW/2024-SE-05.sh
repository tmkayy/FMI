#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo "use 2 arguments" >&2
    exit 1
fi

if [[ ! -f "$2" || ! -w "$2" ]]; then
    echo "provide a writeable file">&2
    exit 4
fi

cmd="$1"
records="$2"
now1=$(date +'%Y-%m-%d %R')
now2=$(date +'%A %H')
value=$($cmd)

if [[ "$?" -ne 0 ]]; then
    exit 3
fi

wday=$(echo "$now2" | cut -d ' ' -f1)
hr=$(echo "$now2" | cut -d ' ' -f2)

avg=$(awk -v w=$wday -v h=$hr '
w == $1 && h==$2 {
    total+=$3
    count+=1
}
END {
    if(count>0){
        printf "%.4f", total/count
    }
}
' "$records")

echo "$wday $hr $value" >> "$records"

result=$(awk -v val=$value -v avg=$avg -v now=$now1 '
BEGIN {
    if(val*2<avg||avg*2<val){
        print now ": " val " abnormal"
    }
}')

if [[ ! -z $result ]]; then
    echo "$result"
    exit 2
fi
