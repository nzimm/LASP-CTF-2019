/*
 * gcc -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// This function exists in memory, even thought it is never called
void secret_function()
{
    // Call levelup
    char *levelup = "/usr/local/bin/levelup";
    char *argv[] = { levelup, NULL};
    char *envp[] = { NULL };
    execve(levelup, argv, envp);
}

int main()
{
    char buffer[24];
    gets(buffer);
    printf("You typed: %s\n", buffer);
    return 0;
}
