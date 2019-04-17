#!/usr/bin/env python3
import random
import os

#data_directory = "/home/nizi2734/ctf.git/level2/data"
data_directory = "/home/nzimm/git/ctf/level2/data"
random_source = "/dev/urandom"

with open(random_source, "rb") as URAND:
    #for i in range(0,10):
    for i in range(0,1):
        data_file_path = os.path.join(data_directory, "file" + str(i) + ".dat")
        with open(data_file_path, "wb") as OUT_FILE:
            OUT_FILE.write(URAND.read(1000))
            OUT_FILE.close()
    URAND.close()
