#!/bin/sh
#
# Correctly chmod, chown, and move files
#

# Level to be copied, chowned AND chmoded
LEVEL="level1"

# Files to be copied and chowned only
FILES="objective.md level1.c"

# Level directory (default to level)
DIR="/ctf/$LEVEL"

# User to chown the level files to (default to level)
USER="$LEVEL"



# Run the makefile
make clean && make

# Ensure that the make exited successfuly
if [ $? -eq 0 ]; then
    echo "sudo cp -f $LEVEL $FILES $DIR/"
    sudo cp -f $LEVEL $FILES $DIR/

    # Setup level ownership and permissions
    echo "sudo chown $USER:$USER $DIR/$LEVEL"
    sudo chown $USER:$USER $DIR/$LEVEL

    for F in $FILES; do
        echo "sudo chown $LEVEL:$LEVEL $DIR/$F"
        sudo chown $LEVEL:$LEVEL $DIR/$F
        echo "sudo chmod 440 $DIR/$F"
        sudo chmod 440 $DIR/$F
    done

    echo "sudo chmod 2550 $DIR/$LEVEL"
    sudo chmod 2550 $DIR/$LEVEL

fi

# Clean up
make clean
