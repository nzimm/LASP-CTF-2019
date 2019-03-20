#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

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
    
    setegid(getgid());

    printf("Real UID: %d\nEffective UID: %d\n", getuid(), geteuid());
    printf("Real GID: %d\nEffective GID: %d\n", getgid(), getegid());

    return 0;
}
