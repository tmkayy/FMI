#!/bin/bash

if [[ $# -lt 2 ]]; then
    echo "wrong command usage">&2
    exit 1
fi

limit=$1
shift 1
cmd="$@"
ns_const=1000000000

limit=$((limit*ns_const))

count=0
sum_exec_times=0
start=$(date +%s%N)
while true; do
    start_curr=$(date +%s%N)

    $cmd

    end=$(date +%s%N)
    count=$((count + 1))
    sum_exec_times=$((sum_exec_times + end - start_curr))

    total_time_elapsed=$((end-start))
    if [[ $total_time_elapsed -gt $limit ]]; then
        break;
    fi
done

total_secs=$(echo "scale=2; $sum_exec_times / $ns_const" | bc)
avg_secs=$(echo "scale=2; $sum_exec_times / $ns_const / $count" | bc)

echo "Ran the command '${cmd}' ${count} times for ${total_secs} seconds."
echo "Average runtime: ${avg_secs} seconds."
