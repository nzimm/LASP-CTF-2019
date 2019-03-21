#!/bin/sh
#
# Create the level accounts and groups for the CTF
#

# Create top level directory for ctf levels
sudo makedir /ctf/

# Create all necessary accounts
for N in {0..15}; do
    ID=$((16000 + $N))
    sudo useradd --home-dir /ctf/level$N --shell /usr/sbin/nologin --password '!!' --comment "CTF level $N" --create-home --uid $ID level$N
    echo "Created user: level$N"
done

# Setup permissions
#   must solve levelN to be added to the group for level(N+1)

# Make sure everyone can access level0
sudo chmod 555 /ctf/level0

for N in {1..15}; do
    sudo chmod 550 /ctf/level$N
    sudo chown level$N:level$N /ctf/level$N
done

