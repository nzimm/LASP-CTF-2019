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
    # Copy and chown files to /ctf/
    echo "sudo cp -f $LEVEL $FILES $DIR/"
    sudo cp -f $LEVEL $FILES $DIR/

    # Set ownership and permissions for level binary
    echo "sudo chown $USER:$USER $DIR/$LEVEL"
    sudo chown $USER:$USER $DIR/$LEVEL

    for F in $FILES; do
        echo "sudo chown $LEVEL:$LEVEL $DIR/$F"
        sudo chown $LEVEL:$LEVEL $DIR/$F
        echo "sudo chmod 440 $DIR/$F"
        sudo chmod 444 $DIR/$F
    done

    echo "sudo chmod 2550 $DIR/$LEVEL"
    sudo chmod 2550 $DIR/$LEVEL

fi

# Clean up
make clean
