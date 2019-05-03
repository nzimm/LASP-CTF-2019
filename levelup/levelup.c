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
    char *user_t = getpwuid(user_ID)->pw_name;
    char user[strlen(user_t) + 1];
    strncpy(user, user_t, sizeof(user));

    // Save groupname in buffer
    char *group_t = getpwuid(group_ID)->pw_name;
    char group[strlen(group_t) + 1];
    strncpy(group, group_t, sizeof(group));

    // Check that user has completed a level, and called this program with
    // the setGID bit
    if (user_ID != group_ID) {

        // Check that the EGID is of a valid level, and not from some other
        // program with the setGID bit set
        if (16000 <= group_ID && group_ID < 16015) {

            // get next level's group name
            char *next_level_t = getpwuid(group_ID+1)->pw_name;
            char next_level[strlen(next_level_t) + 1];
            strncpy(next_level, next_level_t, sizeof(next_level));

            char *gpasswd = "/usr/bin/gpasswd";
            char *argv[] = { gpasswd, "-a", user, next_level, NULL};
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
