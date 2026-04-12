#!/bin/bash

if [[ $# -ne 2 ]]
    echo 'wrong parameter count' >&2
    exit 1
fi

if [[ ! -d $1 || ! -d $2 ]]
    echo 'wrong argument type' >&2
    exit 2
fi

REPO="$1"
PACKAGE="$2"

PACKAGENAME=$(basename "$REPO")
PACKAGEVERSION=$(cat "${PACKAGE}/version" | tr -d '\n')
FULLNAME="${PACKAGENAME}-${PACKAGEVERSION}"

temp_archive=$(mktemp)
tar -C "$PACKAGE/tree" -c . | xz > "$temp_archive"
CHECKSUM=$(sha256sum "$temp_archive" | cut -d ' ' -f1)
ARCHIVE_PATH="${REPO}/packages/${CHECKSUM}.tar.xz"

mv "$temp_archive" "$ARCHIVE_PATH"
DB="$REPO/db"

old_checksum=$(grep "^${PKG_FULL_NAME} " "$DB" | cut -d ' ' -f2)
if [[ -n "$old_checksum" ]]; then
    grep -v "^${PKG_FULL_NAME} " "$DB" > "${DB}.tmp"
    mv "${DB}.tmp" "$DB"

    [[ "$old_checksum" != "$CHECKSUM" ]] && rm -f "$REPO/packages/$old_checksum.tar.xz"
fi

echo "$PKG_FULL_NAME $CHECKSUM" >> "$DB"
sort -o "$DB" "$DB"
