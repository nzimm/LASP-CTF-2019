#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    char check[4] = "\xde\xad\xbe\xef";
    char input[128];

    gets(input);
    printf("%s\n", input);

    if (strncmp(check, "\xde\xfa\xce\xd0", 4) == 0)
    {
        printf("Great work!\n");

        // Call levelup
        char *levelup = "/usr/local/bin/levelup";
        char *argv[] = { levelup, NULL};
        char *envp[] = { NULL };
        execve(levelup, argv, envp);
    }

    else if (strncmp(check, "\xde\xad\xbe\xef", 4) != 0)
    {
        printf("Keep trying, you're on the right track!\n");
    }

    else
    {
        printf("Check buffer unaltered\n");
    }
    return 0;
}
