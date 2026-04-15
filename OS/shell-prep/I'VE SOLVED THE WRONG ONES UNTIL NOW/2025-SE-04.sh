#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo 'Expected 2 args' >&2
    exit 1
fi

if [[ ! -d "${1}" || ! -r "${1}" ]]; then
    echo 'First arg must be a readable directory' >&2
    exit 2
fi

mkdir -p "${2}" &>/dev/null

old_dir_path=$(realpath "${1}")
new_dir_path=$(realpath "${2}")

while read -r file; do
    path=$(realpath "${file}" | sed "s:^${old_dir_path}:${new_dir_path}:;s:\.bcf$:\.bcf2:")
    mkdir -p $(dirname "${path}") &>/dev/null

    awk -F '=' '
    {
        key = $1
        value = $2

        seen[key]++
        values[key, seen[key]] = value
    }
    END {
        for (key in seen) {
            if (seen[key] == 1) {
                print key ": " values[key, 1]
            }
            else {
                print key ":"
                for (i = 1; i <= seen[key]; i++) {
                   print "    - " values[key, i]
                }
            }
        }
    }
    ' "${file}" > "${path}"
done < <(find "${1}" -type f -name '*.bcf' 2>/dev/null)
