#!/bin/sh
#
# Correctly chmod and chown the files 
#

make clean && make
if [ $? -eq 0 ]; then
    echo "chowning levelup to root..."
    sudo chown root:root levelup
    echo "chowning test_call to level0..."
    sudo chown level0:level0 test_call

    echo "setting SetUID bit on levelup"
    sudo chmod u+s levelup
    echo "setting SetGID bit on test_call"
    sudo chmod g+s test_call
fi
