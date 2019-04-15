#/bin/bash
#
# Generate random data files
#   requirements:
#       /dev/urandom
#       /usr/bin/dd
#   sample command (using the variables defined below):
#       dd if=/dev/urandom of=./data/file$I.dat bs=$BLOCKSIZE count=$BLOCKS
#

BLOCKS=1000
BLOCKSIZE=1024
N=9

for I in $(seq $N); do
    echo $I
done
