#!/bin/sh
#
# Correctly chmod, chown, and move files
# Additionally, run any makefiles or generation scripts on the fly
#

# Level to be copied, chowned AND chmoded for SETGID
LEVEL="level3"

# Git directory that the files live under
BUILD_DIR="/home/nizi2734/ctf.git/$LEVEL/"

# Files to be copied and chowned only
PASS_FILE="pass.txt"
FILES="objective.md level3.c data/ $PASS_FILE"

# Level directory (default to level)
DIR="/ctf/$LEVEL"

# User to chown the level files to (normally this should just be level)
USER="$LEVEL"


# Run the makefile and wipe data/
echo "make clean && make"
make clean && make
echo "rm -rf pass.txt data/"
rm -rf pass.txt data/

# Generate data files
$BUILD_DIR/generate_directory_tree.py

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

    # Chown the special password file to level4
    LVL4_PASSWD=$(find /ctf/$LEVEL/data/ -name $(cat $BUILD_DIR/$PASS_FILE))
    echo "sudo chown level4 $LVL4_PASSWD"
    sudo chown level4 $LVL4_PASSWD

    # Set the SETGID bit on main binary
    echo "sudo chmod 6755 $DIR/$LEVEL"
    sudo chmod 6755 $DIR/$LEVEL

    # Tighten read permissions on pass.txt
    echo "sudo chmod 400 $DIR/$PASS_FILE"
    sudo chmod 400 $DIR/$PASS_FILE

fi

# Clean up
echo "make clean"
make clean

echo "rm -rf pass.txt data/"
rm -rf pass.txt data/
