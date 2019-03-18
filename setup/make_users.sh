#!/bin/sh
#
# Create user accounts
#   Takes usernames from users.txt
#   Initializes accounts without passwords, root must set initial passwords
#

# Create all necessary accounts
for USER in $(cat users.txt); do
    if [ ! -d /home/$USER ]; then
        sudo useradd --home-dir /home/$USER --skel ./home_dir_skel --shell /usr/bin/fish --password '!!' --create-home --key UID_MIN=1000 --key UID_MAX=15999 $USER
        sudo chmod 755 /home/$USER
        echo "Created user: $USER"
    fi
done
