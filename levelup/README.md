# `levelup.c` - progression program

This program is how students check their work, and climb the levels of this CTF
It checks that the user has an effective group ID that belongs to one of the
levels of the CTF, then adds their user to the level's supplementary group.


# Installation
This file should be installed to `/usr/local/bin/` so that it is the `$PATH`
The `setup.sh` script compiles the program, then asks for root permission to
copy the file to `/usr/local/bin` and set the SUID bit (must be root to modify
/etc/group)
