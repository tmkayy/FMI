#!/bin/bash

if [[ -z "$REGISTRY_FILE" || -z "$REPORTS_DIR" ]]; then
    echo 'env vars not set' >&2
    exit 1
fi

if [[ ! -f "$REGISTRY_FILE" ]]; then
    touch "$REGISTRY_FILE"
fi

mkdir -p "$REPORTS_DIR" &>/dev/null

name="${REPORTS_DIR}/$(date +'%Y-%m-%d-%H-%M-%S').report"
touch "$name"

for arg in "$@"; do
    tempNew=$(mktemp)
    tempUn=$(mktemp)
    tempCh=$(mktemp)

    while read -r file; do
        sha=$(sha256sum "$file" | awk '{print $1}')
        path=$(realpath "$file")
        status=""
        while read -r sh p; do
            if [[ "$p" == "$path" ]]; then
                status="found"
                if [[ $sh == $sha ]]; then
                    echo "      $p" >> "$tempUn"
                else
                    echo "      $p" >> "$tempCh"
                    sed -iE "s/^${sh}/${sha}/" "$REGISTRY_FILE"
                fi
            fi
        done<"$REGISTRY_FILE"
        if [[ -z "$status" ]]; then
            echo "      $path" >> "$tempNew"
            echo "${sha} ${path}" >> "$REGISTRY_FILE"
        fi
    done< <(find "$arg" -type f 2>/dev/null)

    echo "new:" >> "$name"
    (cat "$tempNew") >> "$name"
    echo "unchanged:" >> "$name"
    (cat "$tempUn") >> "$name"
    echo "modified:" >> "$name"
    (cat "$tempCh") >> "$name"

    rm -f "$tempNew" "$tempUn" "$tempCh"
done
