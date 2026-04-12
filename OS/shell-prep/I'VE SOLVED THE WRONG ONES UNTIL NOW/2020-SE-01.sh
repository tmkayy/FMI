#!/bin/bash

if [[ $# -ne 2 ]]; then
    echo 'provide file and dir' >&2
    exit 1
fi

if [[ ! -d "$2" || ! "$1" =~ ^.*\.csv$ ]]; then
    echo 'invalid argument/s' >&2
    exit 2
fi

CSV="$1"
DIR="$2"

echo "hostname,phy,vlans,hosts,failover,VPN-3DES-AES,peers,VLAN Trunk Ports,license,SN,key" > "$CSV"

extract_value() {
    local file="$1"
    local pattern="$2"
    grep "^$pattern" "$file" 2>/dev/null | cut -d':' -f2- | sed 's/^[[:space:]]*//;s/[[:space:]]*$//'
}

for file in "$DIR"/*.log; do
    [[ -f "$file" ]] || continue

    hostname=$(basename "$file" .log)

    phy=$(extract_value "$file" "Maximum Physical Interfaces")
    vlans=$(extract_value "$file" "VLANs")
    hosts=$(extract_value "$file" "Inside Hosts")
    failover=$(extract_value "$file" "Failover")
    vpn=$(extract_value "$file" "VPN-3DES-AES")
    peers=$(extract_value "$file" "\*Total VPN Peers")
    trunk=$(extract_value "$file" "VLAN Trunk Ports")

    license=$(grep "^This platform has a" "$file" | sed 's/This platform has a //;s/ license\.$//')

    sn=$(extract_value "$file" "Serial Number")

    key=$(extract_value "$file" "Running Activation Key")

    echo "$hostname,$phy,$vlans,$hosts,$failover,$vpn,$peers,$trunk,$license,$sn,$key" >> "$CSV"
done
