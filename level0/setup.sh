#!/bin/sh
#
# Correctly chmod, chown, and move files
#

# Level to be copied, chowned AND chmoded
LEVEL="level0"

# Files to be copied and chowned only
FILES="objective.md"

# Level directory
DIR="/ctf/level0"

# User to chown the level files to
USER="level0"



# Run the makefile
make clean && make

# Ensure that the make exited successfuly
if [ $? -eq 0 ]; then
    # Copy files to /ctf/
    echo "sudo cp -f $LEVEL $FILES $DIR/"
    sudo cp -f $LEVEL $FILES $DIR/

    # Set ownership and permissions for level binary
    echo "sudo chown $USER:$USER $DIR/$LEVEL"
    sudo chown $USER:$USER $DIR/$LEVEL

    echo "sudo chmod 2755 $DIR/$LEVEL"
    sudo chmod 2755 $DIR/$LEVEL

    for F in $FILES; do
        echo "sudo chown $LEVEL:$LEVEL $DIR/$F"
        sudo chown $LEVEL:$LEVEL $DIR/$F
    done

fi

# Clean up
make clean
