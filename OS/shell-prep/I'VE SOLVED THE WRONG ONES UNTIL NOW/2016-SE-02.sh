#!/bin/bash

#idk
if [[ ! ${USER} =~ ^root$ ]]; then
    printf "you dont have the right, oh you dont have the right\ntherefore\n you dont have the right, oh you dont have the right"
    exit 1
fi

if [[ ! "$#" -eq 1 ]]; then
    echo 'need only 1 arg'
    exit 2
fi

if [[ "$1" =~ ^[1-9]+[0-9]*$ ]]
    echo 'NapN'
    exit 3
fi

ps -e -o uid=,pid=,rss= | awk -v limit="$1" '
{
    sum[$1] += $3
    count[$1]++
    if ($3 > max[$1]) { max[$1] = $3; pid[$1] = $2 }
}
END {
    print "USER\tTOTAL_RSS\tPROCS"
    for (u in sum) {
        cmd = "id -nu " u 2>/dev/null || echo u
        cmd | getline name; close(cmd)
        printf "%s\t%d\t%d\n", name, sum[u], count[u]
        if (sum[u] > limit) {
            system("kill -TERM " pid[u] " 2>/dev/null; sleep 1; kill -KILL " pid[u] " 2>/dev/null")
        }
    }
}'
