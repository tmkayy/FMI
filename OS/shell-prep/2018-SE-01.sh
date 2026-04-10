#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo 'more than 1 argument'
    exit 1
fi

LOGDIR=$1

if [[ ! -d "$LOGDIR" ]]; then
    echo 'logdir doesnt exist or is not a directory'
    exit 2
fi

if [[ ! -r "$LOGDIR" ]]; then
    echo 'not readable directory'
    exit 3
fi

tempfile=$(mktemp)

while read filename; do
    friend=$(basename "$(dirname "$filename")")
    lines=$(cat "$filename" | wc -l 2>/dev/null)

    echo -e "$friend\t$lines" >> "$tempfile"
done < <(find "$LOGDIR" -type f -name "*.txt" -readable 2>/dev/null)

awk -F '\t' '
{
    sum[$1] += $2
}
END {
    for (friend in sum) {
        print sum[friend] "\t" friend
    }
}' "$tempfile" | sort -rn | head |
awk -F '\t' '
{
    printf "Friend: %-30s -> %8d lines\n", $2, $1
}'

rm -f "$tempfile"
