#!/bin/sh
#
# setup.sh
#   Correctly chmod, chown, and move the `levelup` binary
#   Should be placed in `/usr/local/bin/` and needs root permissions to alter
#   user supplemental groups
#

LEVELUP="levelup"
DIR="/usr/local/bin"

# Run the makefile
make clean && make

# Ensure that the make exited successfuly
if [ $? -eq 0 ]; then
    echo "sudo cp -f $LEVELUP $DIR/"
    sudo cp -f $LEVELUP $DIR/

    echo "sudo chown root:root $DIR/$LEVELUP"
    sudo chown root:root $DIR/$LEVELUP

    echo "sudo chmod u+s $DIR/$LEVELUP"
    sudo chmod u+s $DIR/$LEVELUP

fi
