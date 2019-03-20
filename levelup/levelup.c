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
    strncpy(user, name, strlen(name));

    // Save groupname in buffer
    name = getpwuid(group_ID)->pw_name;
    char group[strlen(name) + 1];
    strncpy(group, name, strlen(name));

    printf("user: %s\ngroup: %s\n", user, group);

    // Check that user has completed a level, and called this program with
    // the setGID bit
    if (user_ID != group_ID) {

        // Check that the EGID is of a valid level, and not from some other
        // program with the setGID bit set
        if (16000 <= group_ID && group_ID <= 16015) {
            printf("Adding user %s to group %s...\n", user, group);

            char *usermod = "/usr/bin/usermod";
            char *argv[] = { usermod, "-a", "-G", group, user, NULL};
            char *envp[] = { NULL };

            execve(usermod, argv, envp);

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
