#!/bin/bash

if [[ ! -d '/home' ]]; then
    echo 'no /home directory found'
    exit 1
fi

result=$(find /home -type f 2>/dev/null -printf '%T@ %u %p\n' | sort -nr | head -n 1)

if [[ -z $result ]]; then
    echo 'no files found'
    exit 2
fi

time=$(echo "$result" | awk '{printf $1}')
user=$(echo "$result" | awk '{printf $2}')
file=$(echo "$result" | awk '{printf $3}')

echo "User with latest modified file: $user"
echo "Time modified: $time"
echo "File: $file"
