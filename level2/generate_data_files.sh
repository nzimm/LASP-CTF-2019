#/bin/bash
#
# Generate random data files
#   requirements:
#       /dev/urandom
#       /usr/bin/dd
#

BLOCKS=1000
BLOCKSIZE=1024
DIR="/home/nizi2734/ctf.git/level2/data"
SOURCE="/dev/urandom"
N=9

for I in $(seq $N); do
    dd if=$SOURCE of=$DIR/file$I.dat count=$BLOCKS bs=$BLOCKSIZE
done
