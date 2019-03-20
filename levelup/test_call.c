#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>

/*
 * mimick a level program that has been broken
 *   binary should have SetGID bit set
*/
int main()
{
    printf("Real UID: %d\nEffective UID: %d\n", getuid(), geteuid());
    printf("Real GID: %d\nEffective GID: %d\n", getgid(), getegid());


    char *argv[] = { "./levelup", NULL};
    char *envp[] = { NULL };

    execve("./levelup", argv, envp);
    return 0;
}
