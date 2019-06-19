#!/bin/bash
# inspired by root-me.org

CRONDIR="/tmp/.cron_level4"

# discard stdin, stderr
exec &>/dev/null

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
