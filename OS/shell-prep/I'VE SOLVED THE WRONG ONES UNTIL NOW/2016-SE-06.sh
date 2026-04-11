#!/bin/bash

if [[ ${#} -ne 1 ]]; then
    echo 'enter only a file name'
    exit 1
fi

if [[ ! -f "${1}" ]]; then
    echo 'not a file'
    exit 2
fi

sed -E 's/^[1-9]+[0-9]*г\. - //g' "${1}" | sort | awk '{print NR ". " $0}'
