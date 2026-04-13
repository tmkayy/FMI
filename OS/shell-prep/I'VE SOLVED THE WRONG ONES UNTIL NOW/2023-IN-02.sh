#!/bin/bash

# slop
if [[ $# -ne 1 ]]; then
    echo "provide 1 arg" >&2
    exit 1
fi

if [[ ! -d "$1" || ! -r "$1" ]]; then
    echo "not a readable directory" >&2
    exit 2
fi

dir="$1"

tempfile=$(mktemp)

sha256sum "$dir"/* | sort | while read -r hash file; do
    inode=$(stat -c '%i' "$file")
    echo "$hash $inode $file"
done > "$tempfile"

while read -r hash; do
    group=$(grep "^$hash " "$tempfile")
    #file is hardlink if its inode appears more than once in the group
    standalones=$(while read -r inode; do
        echo "$group" | awk -v i="$inode" '$2==i {print $3}'
    done < <(echo "$group" | awk '{print $2}' | sort | uniq -u))

    hardlink_inodes=$(echo "$group" | awk '{print $2}' | sort | uniq -d)

    if [[ -n "$hardlink_inodes" && -n "$standalones" ]]; then
        #mixed: delete all standalones, one from each hardlink grou
        echo "$standalones"
        while read -r inode; do
            echo "$group" | awk -v i="$inode" 'NR==1 && $2==i {print $3}'
        done < <(echo "$hardlink_inodes")
    elif [[ -n "$hardlink_inodes" ]]; then
        #only hardlinks: delete one from each group
        while read -r inode; do
            echo "$group" | awk -v i="$inode" 'NR==1 && $2==i {print $3}'
        done< <(echo "$hardlink_inodes")
    else
        #only standalones: keep one, delete the rest
         echo "$standalones" | tail -n +2
    fi

done< <(awk '{print $1}' "$tempfile" | uniq)

rm -f "$tempfile"
