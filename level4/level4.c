#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define PASSLEN 17

int main()
{
    const char *passwd_file = "/ctf/level4/pass.txt";
    char passwd[PASSLEN], guess[PASSLEN];
    FILE *file;

    // Read password from file
    file = fopen(passwd_file, "r");
    if (file) {
        fgets(passwd, PASSLEN, file);
    }

    // Prompt user
    printf("Password: ");
    fgets(guess, PASSLEN, stdin);

    // Stall for effect
    sleep(3);

    if ( strncmp(guess, passwd, PASSLEN) == 0 ) {
        printf("Correct!\n");

        // Call levelup
        char *levelup = "/usr/local/bin/levelup";
        char *argv[] = { levelup, NULL};
        char *envp[] = { NULL };
        execve(levelup, argv, envp);
    }
    else {
        printf("Hmm, that doesn't look quite right...\n");
        return 1;
    }
    return 0;
}
