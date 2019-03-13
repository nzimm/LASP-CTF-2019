# Introductory CTF for LASP Summer 2019 training
CTF to teach self-learning to Linux beginners and foster understanding of shell
fundamental

## Overview
CTF stands for Capture The Flag. This CTF has [???] levels, which range from
introductory concepts to advanced ones. Ideally this exercise proves
informative to beginners, while still engaging to power users.

## How do I get started?
The slideshow should provide a more thorough introduction, but here's a brief
summary:
- You will have an account created on the training host
- Level material can be found the `/ctf/` directory
- Starting at `level0`, `objective.md` contains the challenge details
- After solving a level, run the system command `levelup` to unlock the next
  level

## Level group 1 (delim TBD)
The first group of levels focus on building a fundamental knowledge of the
Linux command line. After reaching level 5, you should be able to:
1. Discover and switch between different shells on the system
2. Lookup and modify environment variables
3. Use and effectively search `man` pages
4. Basic file I/O with shell commands and pipes
5. Basic scripting

## Level group 2
Shell script security
1. Environment manipulation
2. Input sanitization

## Level group 3
Intermediate security concepts
1. Buffer overflows
2. Integer overflows

## Setup guide
Each level contains an admin setup file that discuses what steps to take when
setting up initially. Each level is a user on the system, and as students
progress, their account is added to the level groups which they have completed.

The default user directory is `/home/` but I find it cleaner if the level data
is stored under `/ctf/level{0..N}` instead.

The `levelN` binaries should be runable 
