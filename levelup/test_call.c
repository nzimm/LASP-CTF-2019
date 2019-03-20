#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>

int main()
{
    printf("Real UID: %d\nEffective UID: %d\n", getuid(), geteuid());
    printf("Real GID: %d\nEffective GID: %d\n", getgid(), getegid());


    char *argv[] = { NULL};
    char *envp[] = { NULL };

    execve("./levelup", argv, envp);
    return 0;
}
