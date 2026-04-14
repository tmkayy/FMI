#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "provide only 1 directory">&2
    exit 1
fi

if [[ ! -d "$1" || ! -r "$1" ]]; then
    echo 'not a readable directory'>&2
    exit 2
fi

dir="$1"
tempdir=$(mktemp -d)

filescount=$(find $dir -type f | wc -l)
threshold=$(( filescount / 2 ))

while read file; do
    while read count word; do
        if((count>=3)); then
            echo $word >> "${tempdir}/foundinfiles"
        fi
        echo "$word $count" >> "${tempdir}/totalcounts"
    done< <(grep -oE "[a-z]+" "$file" | sort | uniq -c)
done< <(find $dir -type f)

while read count word; do
    if (($count>=threshold)); then
        echo $word >> "${tempdir}/candidates"
    fi
done< <(sort "${tempdir}/foundinfiles" | uniq -c)

awk '{total[$1]+=$2} END {
    for (w in total){
        print total[w], w
    }
}' "${tempdir}/totalcounts" | sort -rn | grep -Ff "${tempdir}/candidates" | head | awk '{print $2}'


rm -rf "$tempdir"
