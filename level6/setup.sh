#!/bin/sh
#
# Correctly chmod, chown, and move files
# Additionally, run any makefiles or generation scripts on the fly
#

# Level to be copied, chowned AND chmoded for SETGID
LEVEL="level6"

# Git directory that the files live under
BUILD_DIR="/home/nizi2734/ctf.git/$LEVEL/"

# Files to be copied and chowned only
FILES="objective.md level6.c generate_pin.py pin.txt"

# Level directory (default to level)
DIR="/ctf/$LEVEL"

# User to chown the level files to (normally this should just be level)
USER="$LEVEL"

# Make pin.txt
echo "$BUILD_DIR/generate_pin.py > $BUILD_DIR/pin.txt"
$BUILD_DIR/generate_pin.py > $BUILD_DIR/pin.txt

# Run the makefile
echo "make clean && make"
make clean && make

# Ensure that make exited successfuly
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
    echo "sudo chmod 440 $DIR/*"
    sudo chmod 440 $DIR/*

    # Set special ownership on main binary and pin.txt
    echo "sudo chown $USER:$USER $DIR/$LEVEL $DIR/pin.txt"
    sudo chown $USER:$USER $DIR/$LEVEL $DIR/pin.txt

    echo "sudo chmod 6550 $DIR/$LEVEL"
    sudo chmod 6550 $DIR/$LEVEL

    echo "sudo chmod 400 $DIR/pin.txt"
    sudo chmod 400 $DIR/pin.txt

fi

# Clean up
echo "make clean && rm $BUILD_DIR/pin.txt"
make clean && rm $BUILD_DIR/pin.txt

# Print instruction to install crontab
echo
echo "[*] Optional [*]"
echo "install crontab to auto-regenerate new PINs"
echo "0 8-18 * * * /usr/bin/python3 /ctf/level6/generate_pin.py > /ctf/level6/pin.txt"
