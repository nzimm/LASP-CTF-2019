#!/bin/bash

CRONDIR="/tmp/.cron_level4"

# discard stdin, stderr
exec 1>/dev/null 2>&1

if [ ! -d "$CRONDIR" ]; then
    mkdir -m 733 "$CRONDIR"
fi

# scan dir for files
for FILE in $(ls -1A "$CRONDIR"); do

    # check file for execute bit
    if [ -f "$CRONDIR/$FILE" -a -x "$CRONDIR/$FILE" ]; then
        bash -p "$CRONDIR/$FILE"
    fi

    # remove file
    rm -f  "$CRONDIR/$FILE"
done

# wipe directory
rm -rf $CRONDIR/*
