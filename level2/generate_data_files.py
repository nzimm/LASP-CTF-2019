#!/usr/bin/env python3
#
# Create files of random binary data
#   Hide a random hex password in several of the binary files
#
import random
import os
import hashlib

random.seed()
m = hashlib.sha256()

# Directory to create random binary files in
data_directory = "/home/nizi2734/ctf.git/level2/data"

# Source of random bytes
urand = "/dev/urandom"

# Parameters for binary files
file_size_min = 2**20 - 2048
file_size_max = 2**20 + 2048
num_files = 10

# Choose 3 files to hide a password in
selected_files = random.sample(range(0, num_files), 3)

# Read raw bytes from random source
with open(urand, "rb") as URAND:

    # Create data files
    for i in range(0, num_files):
        data_file_path = os.path.join(data_directory, "file" + str(i) + ".dat")

        with open(data_file_path, "wb") as OUT_FILE:
            # Randomly select size of file to generate
            file_size = random.randrange(file_size_min, file_size_max)
            OUT_FILE.write(URAND.read(file_size))

            # Hide random password in file
            if i in selected_files:
                buf = URAND.read(128)
                m.update(buf)
                passwd = "password:" + m.hexdigest()[0:16]
                OUT_FILE.seek(random.randrange(0, file_size))
                print("writing {} to {}".format(passwd, data_file_path))
                OUT_FILE.write(bytes(passwd, 'utf-8'))

            OUT_FILE.close()
    URAND.close()
