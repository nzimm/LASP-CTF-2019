#!/bin/sh
#
# setup.sh
#   Correctly chmod, chown, and move the `scoreboard` script
#   Should be placed in `/usr/local/bin/`
#

SCOREBOARD="scoreboard"
DIR="/usr/local/bin"

# Ensure that the make exited successfuly
if [ $? -eq 0 ]; then
    echo "sudo cp -f $SCOREBOARD $DIR/"
    sudo cp -f $SCOREBOARD $DIR/

    echo "sudo chown root:root $DIR/$SCOREBOARD"
    sudo chown root:root $DIR/$SCOREBOARD

fi
