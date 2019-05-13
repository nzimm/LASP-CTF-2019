#!/bin/bash
#
# Create the level accounts and groups for the CTF
#

# Create top level directory for ctf levels
sudo mkdir /ctf/

# Create all necessary accounts
for N in {0..15}; do
    ID=$((16000 + $N))

    # Create the level directory
    sudo mkdir /ctf/level$N
    echo "Created /ctf/level$N"

    # Create user
    sudo useradd --home-dir /ctf/level$N --shell /usr/sbin/nologin --password '!!' --comment "CTF level $N" --no-create-home --uid $ID level$N
    echo "Created user: level$N"
done


# Setup permissions
#   must solve levelN to be added to the group for level(N+1)

# Make sure everyone can access level0
sudo chown level0:level0 /ctf/level0

for N in {1..15}; do
    sudo chmod 550 /ctf/level$N
    sudo chown level$N:level$N /ctf/level$N
done

