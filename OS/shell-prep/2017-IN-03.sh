#!/bin/bash

awk -F ':' '$5 ~ /[^ ]*а,,,,I$/ {print substr($1, 2, 2)}' /etc/passwd | sort | uniq -c | tail -n 1
