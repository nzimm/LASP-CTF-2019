#!/bin/sh
#
# Correctly chmod, chown, and move files
# Additionally, run any makefiles or generation scripts on the fly
#

# Level to be copied, chowned AND chmoded for SETGID
LEVEL="level4"

# Git directory that the files live under
BUILD_DIR="/home/nizi2734/ctf.git/$LEVEL/"

# Files to be copied and chowned only
FILES="objective.md $LEVEL.c pass.txt run.sh"

# Files to be executable
XFILES="run.sh"

# Level directory (default to level)
DIR="/ctf/$LEVEL"

# User to chown the level files to (normally this should just be level)
USER="$LEVEL"


# Run the makefile and wipe bin/
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
        echo "sudo chmod 440 $DIR/$F"
        sudo chmod 440 $DIR/$F
    done

    # Tighten passwd.txt permissions
    echo "sudo chmod 400 $DIR/pass.txt"
    sudo chmod 400 $DIR/pass.txt

    # Chown files to levelN:levelN
    echo "sudo chown -R $USER:$USER $DIR/*"
    sudo chown -R $USER:$USER $DIR/*

    # Make additional files executable
    echo "sudo chmod 550 $DIR/$XFILES"
    sudo chmod 550 $DIR/$XFILES

    # Set the SETGID bit on main binary
    echo "sudo chmod 6550 $DIR/$LEVEL"
    sudo chmod 6550 $DIR/$LEVEL

fi

# Setup tmp cron directory
echo "sudo rm -rf /tmp/.cron_level4"
sudo rm -rf /tmp/.cron_level4

echo "mkdir /tmp/.cron_level4"
mkdir /tmp/.cron_level4

echo "sudo chown level4:level4 /tmp/.cron_level4"
sudo chown level4:level4 /tmp/.cron_level4

echo "sudo chmod 733 /tmp/.cron_level4"
sudo chmod 733 /tmp/.cron_level4

# Clean up
echo "make clean"
make clean

# Print warning to install crontab
echo
echo "[*] Warning [*]"
echo "ensure crontab is installed for level4 user"
echo "*/1 * * * * /bin/bash /ctf/level4/run.sh"
