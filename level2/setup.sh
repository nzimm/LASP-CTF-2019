#!/bin/sh
#
# Correctly chmod, chown, and move files
# Additionally, run any makefiles or generation scripts on the fly
#

# Level to be copied, chowned AND chmoded for SETGID
LEVEL="level2"

# Git directory that the files live under
BUILD_DIR="/home/nizi2734/ctf.git/$LEVEL/"

# Files to be copied and chowned only
PASS_FILE="pass.txt"
FILES="objective.md level2.c data/ $PASS_FILE"

# Level directory (default to level)
DIR="/ctf/$LEVEL"

# User to chown the level files to (default to level)
USER="$LEVEL"


# Run the makefile
echo "make clean && make"
make clean && make

# Generate data files
$BUILD_DIR/generate_data_files.py

# Save password to file
grep --no-filename --text --only-matching "[0-9a-f]\{16\}" data/* | tail -n 1 > $PASS_FILE

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
    echo "sudo chown $LEVEL:$LEVEL $DIR/*"
    sudo chown $LEVEL:$LEVEL $DIR/*

    # Set the SETGID bit on main binary
    echo "sudo chmod 2755 $DIR/$LEVEL"
    sudo chmod 2755 $DIR/$LEVEL

    # Tighten read permissions on pass.txt
    echo "sudo chmod 440 $DIR/$PASS_FILE"
    sudo chmod 440 $DIR/$PASS_FILE
    

fi

# Clean up
echo "make clean"
make clean
echo "rm -r pass.txt data/"
rm -r pass.txt data/
