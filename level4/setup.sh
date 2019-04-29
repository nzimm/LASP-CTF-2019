#!/bin/sh
#
# Correctly chmod, chown, and move files
# Additionally, run any makefiles or generation scripts on the fly
#

# Level to be copied, chowned AND chmoded for SETGID
LEVEL="level4"
SGID_FILES="$LEVEL run"

# Git directory that the files live under
BUILD_DIR="/home/nizi2734/ctf.git/$LEVEL/"

# Files to be copied and chowned only
PASS_FILE="pass.txt"
FILES="objective.md level4.c bin/ $PASS_FILE"

# Level directory (default to level)
DIR="/ctf/$LEVEL"

# User to chown the level files to (normally this should just be level)
USER="$LEVEL"


# Run the makefile and wipe bin/
echo "make clean && make"
make clean && make
echo "rm -rf pass.txt bin/"
rm -rf pass.txt bin/

# Setup bin/
mkdir $BUILD_DIR/bin/
ln -s $(which ls) $BUILD_DIR/bin/ls
ln -s $(which cat) $BUILD_DIR/bin/cat


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
    echo "sudo chown -R $LEVEL:$LEVEL $DIR/*"
    sudo chown -R $LEVEL:$LEVEL $DIR/*

    # Set the SETGID bit on main binary
    for F in $SGID_FILES; do
        echo "sudo chmod 2755 $DIR/$F"
        sudo chmod 2755 $DIR/$F
    done

    # Tighten read permissions on pass.txt
    echo "sudo chmod 440 $DIR/$PASS_FILE"
    sudo chmod 440 $DIR/$PASS_FILE

fi

# Clean up
echo "make clean"
make clean

echo "rm -rf pass.txt bin/"
rm -rf pass.txt bin/
