#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>


/*
 * Handles output on failure to pass validation
 */
int error() {
    printf("What are you doing?? Go back and break the level!\n"
           "(This command only works if your EGID is level0-15)\n");
    return 1;
}

/*
 * Checks calling user's RGID and EGID
 *   if they do not agree, then user is added to EGID group
 *   otherwise, print a rude message 
 */
int main(int argc, char* argv[])
{
    if (argc != 1) {
        printf("usage: %s\n", argv[0]);
        return 1;
    }

    printf("Real UID: %d\nEffective UID: %d\n", getuid(), geteuid());
    printf("Real GID: %d\nEffective GID: %d\n", getgid(), getegid());

    if (getgid() != getegid()) {
        // Check that the EGID is a valid level
        if (16000 <= getegid() && getegid() <= 16015) {
            printf("Adding user %s to group %s...\n",
                   getpwuid(getuid())->pw_name,
                   getpwuid(getegid())->pw_name
            );
        }
        else {
            return(error());
        }
    }
    else {
        return(error());
    }

    return 0;
}
