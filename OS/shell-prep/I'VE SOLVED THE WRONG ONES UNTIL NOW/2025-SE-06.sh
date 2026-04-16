#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo 'Expected one argument' >&2
    exit 1
fi

if [[ ! -d "${1}" || ! -r "${1}" ]]; then
    echo 'Arg must be a readable directory' >&2
    exit 2
fi

dir="${1}"
new_dir="${1}/.data"

mkdir -p "${new_dir}" &>/dev/null

while read -r file; do
    if [[ -L "${file}" ]]; then
        continue
    fi

    sum=$(sha256sum "${file}" | cut -d ' ' -f 1)
    found=""
    dir_name=$(dirname "${file}")


    while read -r datafile; do
        name=$(basename "${datafile}")

        if [[ "${name}" == "${sum}" ]]; then
            found="true"
        fi
    done < <(find "${new_dir}" -type f 2>/dev/null)

    if [[ -z "${found}" ]]; then
        new_path="${new_dir}/${sum}"
        mv "${file}" "${new_path}"
        ln -s "$(realpath --relative-to="${dir_name}" "${new_path}")" "${dir_name}/$(basename "${file}")"
    fi
done < <(find "${dir}" -type f ! -path "${new_dir}/*" 2>/dev/null)
