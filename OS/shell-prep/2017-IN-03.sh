#!/bin/bash

awk -F ':' '$5 ~ /[^ ]*а,,,,I$/ {print substr($1, 3, 2)}' /etc/passwd | sort | uniq -c | tail -n 1

#no substr
awk -F ':' '$5 ~ /[^ ]*а,,,,I$/ { match ($1, /^s[0-9]([0-9][0-9])/ , arr);print arr[1]}' /etc/passwd | sort | uniq -c | tail -n 1
