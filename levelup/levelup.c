#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>


/*
 * Handle output on failure to pass validation
 */
int error(char *reason) {
    printf("What are you doing?? You shouldn't be calling this!\n%s\n", reason);
    return 1;
}

/*
 * Checks caller's real uid, gid and effective gid
 *   uid must match rgid, and egid must be a valid level for user to leveled
 *   Otherwise, print a rude message
 *   NOTE: this assumes UID == GID for all level accounts
 */
int main(int argc, char* argv[])
{
    if (argc != 1) {
        printf("usage: %s\n", argv[0]);
        return 1;
    }

    // Get uid, gid and egid
    uid_t uid  = getuid();
    gid_t gid  = getgid();
    gid_t egid = getegid();

    // uid should equal gid (newgrp sets gid to level)
    if (uid == gid) {

        // gid should not equal egid, and egid should be a valid level
        if (gid != egid && 16000 <= egid && egid < 16015) {

            // Save username in buffer
            char *user_t = getpwuid(uid)->pw_name;
            char user[strlen(user_t) + 1];
            strncpy(user, user_t, sizeof(user));

            // Save next group name in buffer
            char *next_group_t = getpwuid(egid + 1)->pw_name;
            char next_group[strlen(next_group_t) + 1];
            strncpy(next_group, next_group_t, sizeof(next_group));

            // Setup gpasswd call
            char *gpasswd = "/usr/bin/gpasswd";
            char *argv[] = { gpasswd, "-a", user, next_group, NULL};
            char *envp[] = { NULL };

            // Grant root to update /etc/groups
            setresuid(0,0,0);

            // execve 'consumes' current process
            execve(gpasswd, argv, envp);

            // Should not reach this line
            return 2;
        }
        else {
            return(error("(EGID must be level1-15)"));
        }
    }
    else {
        return(error("(UID does not match GID, try relogging)"));
    }

    return 0;
}
