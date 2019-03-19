#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

/*
 * Inputs:  user to be leveled up
 * Outputs: N/a
 *
 * Verifies the caller's UID is allowed to modify user groups
 */
int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("usage: %s USERNAME\n\n  USERNAME    name of user to levelup\n", argv[0]);
        return 1;
    }

    printf("Real: %d\nEffective: %d\n", getuid(), geteuid());
    
    seteuid(getuid());

    printf("Real: %d\nEffective: %d\n", getuid(), geteuid());

    return 0;
}
