# Admin setup guide
Setup scripts live in this directory - many require root privledges to create
directories, add users, etc.

## Level initialization
Levels are contained in `/ctf/` and are created with empty subdirectories by
running the `init_levels.sh` script. Each level contains a setup script to
automate the build process for the level.

Two levels (4 and 6) use the `cron` daemon to work properly. Running the setup
script will print out the desired cronjob, but *will not* automate adding it
to the cronfile for the level.

Additionally, some of the levels allow users to modify the level files. Fixing
this should be a simple as re-running the setup for the level.

## User creation
The `make_users.sh` script reads names from the `users.txt` file and creates
accounts for them.
