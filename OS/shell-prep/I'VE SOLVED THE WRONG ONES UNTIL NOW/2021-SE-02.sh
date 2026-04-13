#!/bin/bash

update_serial() {
    local file=$1
    local serial=0

    #remove comments
    sed -i 's/;.*//g' "$file"

    #single line
    if grep -vq '(' "$file"; then
            serial=$(awk -F ' IN ' '
            {
                print $2
            }
        ' $file | awk -F ' ' '{print $4}')
    #multi line
    else
        while IFS= read -r line; do
            if [[ $line =~ ^[0-9]+$ ]]; then
                serial=$(echo "$line" | tr -d ' ')
                break
            fi
        done < <(cat "$file")
    fi

    if [[ -z "$serial" ]]; then
        echo "could not extract serial in $file" >&2
        return 1
    fi

    today=$(date +%Y%m%d)
    local sdate="${serial:0:8}"
    local stt="${serial:8:2}"
    local new_serial=''

    if [[ $sdate -lt $today ]]; then
        new_serial="${today}00"
    else
        local new_tt=$((10#$stt + 1))
        if [[ $new_tt -gt 99 ]]; then
            echo 'tt overflow' >&2
            return 1
        fi
        new_serial="${today}$(printf '%02d' $new_tt)"
    fi
    sed -i "s/$serial/$new_serial/" "$file"
    echo "updated ${file}: ${serial} -> ${new_serial}"
}

for arg in "$@"; do
    if [[ ! -f "$arg" || ! -r "$arg" ]]; then
        echo "${arg} is not a readable file" >&2
        continue
    fi
    update_serial "$arg"
done
