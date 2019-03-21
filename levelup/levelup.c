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

    // Get UID and EGID
    uid_t user_ID  = getuid();
    gid_t group_ID = getegid();

    // Save username in buffer
    char *name = getpwuid(user_ID)->pw_name;
    char user[strlen(name) + 1];
    strncpy(user, name, sizeof(user));

    // Save groupname in buffer
    name = getpwuid(group_ID + 1)->pw_name;
    char group[strlen(name) + 1];
    strncpy(group, name, sizeof(group));

    printf("adding %s to group %s...\n", user, group);

    // Check that user has completed a level, and called this program with
    // the setGID bit
    if (user_ID != group_ID) {

        // Check that the EGID is of a valid level, and not from some other
        // program with the setGID bit set
        if (16000 <= group_ID && group_ID < 16015) {
            char *gpasswd = "/usr/bin/gpasswd";
            char *argv[] = { gpasswd, "-a", user, group, NULL};
            char *envp[] = { NULL };

            // Grant root to update /etc/groups
            setresuid(0,0,0);

            // execve 'consumes' current process
            execve(gpasswd, argv, envp);

            // This does not execute
            return 2;
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
