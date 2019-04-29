#!/usr/bin/env python3
#
# Create directory tree with numerous small files
#   Each file contains random bytes, giving them sizes in a fixed range
#
import random
import os
import hashlib

random.seed()
m = hashlib.md5()

# Base directory for this level
build_dir = "/home/nizi2734/ctf.git/level3"

# Directory to create random binary files
data_directory = os.path.join(build_dir, "data/")

try:
    os.mkdir(data_directory)
except:
    print("data directory exists")

# Source of random bytes
urand = "/dev/urandom"

# File to store password file name in
passwd_file = os.path.join(build_dir, "pass.txt")

# Parameters
file_size_min       = 10
file_size_max       = 99
pwd_file_size       = 42    # file size representing password
directory_names     = ['alice', 'bob', 'carol', 'eve', 'mallory']
num_sub_dirs        = 20
num_data_files      = 20
pwd_file_exists     = False

with open(urand, "rb") as URAND:
    # Create base directories in reverse order
    for base in directory_names[::-1]:
        base_dir_path = os.path.join(data_directory, base)
        try:
            os.mkdir(base_dir_path)
        except:
            print("base dir exists: {}".format(base_dir_path))
            continue

        # Create sub directories
        for sub_dir in range(0, num_sub_dirs):
            sub_dir_path = os.path.join(base_dir_path, base + str(sub_dir))
            try:
                os.mkdir(sub_dir_path)
            except:
                print("sub dir exists: {}".format(sub_dir_path))
                continue

            # Create data files
            for data_file in range(0, num_data_files):
                m.update(URAND.read(1))
                file_name = m.hexdigest()[:16]
                data_file_path = os.path.join(sub_dir_path, file_name)

                file_size = random.randrange(file_size_min, file_size_max)

                # Check if this is the first file of proper length
                if file_size == pwd_file_size and pwd_file_exists == False:
                    print("Making pwd file: {}".format(data_file_path))

                    # Write filename to passwd file
                    with open(passwd_file, "w") as PASS_FILE:
                        PASS_FILE.write(file_name)
                        PASS_FILE.close()
                    pwd_file_exists = True

                # Now write random data to data_file_path
                with open(data_file_path, "wb") as OUT_FILE:
                    OUT_FILE.write(URAND.read(file_size))
                    OUT_FILE.close()







## Choose 3 files to hide a password in
#selected_files = random.sample(range(0, num_files), 3)
#
## Read raw bytes from random source
#with open(urand, "rb") as URAND:
#
#    # Create data files
#    for i in range(0, num_files):
#        data_file_path = os.path.join(data_directory, "file" + str(i) + ".dat")
#
#        with open(data_file_path, "wb") as OUT_FILE:
#            # Randomly select size of file to generate
#            file_size = random.randrange(file_size_min, file_size_max)
#            OUT_FILE.write(URAND.read(file_size))
#
#            # Hide random password in file
#            if i in selected_files:
#                buf = URAND.read(128)
#                m.update(buf)
#                passwd = "password:" + m.hexdigest()[0:16]
#                OUT_FILE.seek(random.randrange(0, file_size))
#                print("writing {} to {}".format(passwd, data_file_path))
#                OUT_FILE.write(bytes(passwd, 'utf-8'))
#
#            OUT_FILE.close()
#    URAND.close()
