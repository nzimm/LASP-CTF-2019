#!/bin/sh
#
#

# Disable ^C
trap '' 2

# Challenge user with PIN
./a.out

if [[ $? -eq 0 ]]; then
    echo Authenticated
else
    echo Failed
fi

# Re-enable ^C
trap 2
