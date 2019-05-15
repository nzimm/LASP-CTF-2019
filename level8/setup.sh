#!/bin/sh
#
# Correctly chmod, chown, and move files
# Additionally, run any makefiles or generation scripts on the fly
#

# Level to be copied, chowned AND chmoded for SETGID
LEVEL="level8"

# Git directory that the files live under
BUILD_DIR="/home/nizi2734/ctf.git/$LEVEL/"

# Files to be copied and chowned only
FILES="objective.md $LEVEL.c"

# Level directory (default to level)
DIR="/ctf/$LEVEL"

# User to chown the level files to (normally this should just be level)
USER="$LEVEL"


# Run the makefile
echo "make clean && make"
make clean && make


# Ensure that the make exited successfuly
if [ $? -eq 0 ]; then

    # Copy main binary
    echo "sudo cp -f $LEVEL $DIR/"
    sudo cp -f $LEVEL $DIR/

    # Copy additional files
    for F in $FILES; do
        echo "sudo cp -rf $BUILD_DIR/$F $DIR/"
        sudo cp -rf $BUILD_DIR/$F $DIR/
    done

    # Chown files to levelN:levelN
    echo "sudo chown -R $USER:$USER $DIR/*"
    sudo chown -R $USER:$USER $DIR/*

    # Set the SETGID bit on main binary
    echo "sudo chmod 2755 $DIR/$LEVEL"
    sudo chmod 2755 $DIR/$LEVEL

fi

# Clean up
echo "make clean"
make clean
