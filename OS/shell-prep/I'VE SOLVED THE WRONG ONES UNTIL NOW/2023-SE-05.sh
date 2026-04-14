#!/bin/bash

lookups=0
occurances=$(mktemp)
limit=65536

while true; do
    found=0
    while read mem comm; do
        if [[ $mem -gt $limit ]]; then
            found=1
            echo $comm >> $occurances
        fi
    done< <(awk '
    { memory[$1]+=$2 }
    END {
        for (comm in memory){
            print memory[comm], comm
        }
    }
    ' <(ps -eo comm=,rss=))

    lookups=$((lookups+1))

    [[ $found -eq 0 ]] && break;
done
threshold=$((lookups/2))

sort "$occurances" | uniq -c | awk -v thr=$threshold '$1>=thr{print $2}'

rm -f "$occurances"
