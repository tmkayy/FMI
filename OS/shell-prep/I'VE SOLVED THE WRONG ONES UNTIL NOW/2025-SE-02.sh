#!/bin/bash
if [[ ! -d "$SVC_DIR" ]]; then
    echo 'You must set SVC_DIR env' >&2
    exit 1
fi
if [[ $# -lt 1 || $# -gt 2 ]]; then
    echo 'Invalid args' >&2
    exit 2
fi

found=""
if [[ $# -eq 2 ]]; then
    service="$2"
    while read -r file; do
        name=$(awk -F ': ' '
        $1 == "name" { print $2 }
        ' "$file")
        if [[ "${name}" == "${service}" ]]; then
            found="$file"
            break
        fi
    done < <(find "$SVC_DIR" -type f 2>/dev/null)
    if [[ -z "${found}" ]]; then
        echo "Service ${service} not found" >&2
        exit 2
    fi
fi

cmd="$1"

get_field() {
    awk -F ': ' -v s2="$2" '
    $1 == s2 { print $2 }
    ' "$1"
}

get_pids_running() {
    while read -r file; do
        pidfile=$(get_field "${file}" "pidfile")
        name=$(get_field "${file}" "name")
        if [[ -f "${pidfile}" ]] && ps -p "$(cat "${pidfile}")" &>/dev/null; then
            echo "$name"
        fi
    done < <(find "$SVC_DIR" -type f 2>/dev/null)
}

if [[ "${cmd}" == "start" ]]; then
    comm=$(get_field "$found" "comm")
    pidfile=$(get_field "$found" "pidfile")
    outfile=$(get_field "$found" "outfile")


    if [[ -f "${pidfile}" ]] && ps -p "$(cat "${pidfile}")" &>/dev/null; then
        echo 'Process already running'
        exit 0
    fi
    (eval "$comm") &>"${outfile}" &
    echo "$!" > "${pidfile}"

elif [[ "${cmd}" == "stop" ]]; then
    pidfile=$(get_field "$found" "pidfile")
    if [[ -f "${pidfile}" ]]; then
        pid=$(cat "${pidfile}")
        kill -SIGTERM "${pid}"
        exit 0
    else
        echo "No pid file" >&2
        exit 3
    fi

elif [[ "${cmd}" == "running" ]]; then
    get_pids_running | sort
elif [[ "${cmd}" == "cleanup" ]]; then
    while read -r file; do
        pidfile=$(get_field "${file}" "pidfile")
        found_service=$(get_pids_running | awk -v service="$(get_field "${file}" "name")" '
        $0 == service { print "true" }
        ')
        if [[ "${found_service}" != "true" ]]; then
            rm -f "${pidfile}"
        fi
    done < <(find "$SVC_DIR" -type f 2>/dev/null)
else
    echo "Invalid command" >&2
    exit 5
fi
