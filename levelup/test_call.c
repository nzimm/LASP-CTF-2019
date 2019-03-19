#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <pwd.h>

int main()
{
    printf("Real: %d\nEffective: %d\n", getuid(), geteuid());

    char *argv[] = { "./levelup", "test", NULL};
    char *envp[] = { NULL };

    execve("./levelup", argv, envp);
    return 0;
}
