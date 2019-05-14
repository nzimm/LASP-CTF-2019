#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define PIN_LEN 4

int main()
{
    char pin[PIN_LEN + 1], guess[PIN_LEN + 1];
    FILE *file_pointer;

    // Read pin from file
    file_pointer = fopen("/ctf/level6/pin.txt", "r");
    fscanf(file_pointer, "%s", pin);

    // Get user guess
    printf("Enter four digit PIN: ");
    fgets(guess, PIN_LEN + 1, stdin);

    // Sleep for 0.2 seconds
    struct timespec len;
    len.tv_sec  = 0;
    len.tv_nsec = 300000000L;
    nanosleep(&len, NULL);

    if ( strncmp(pin, guess, PIN_LEN) == 0 ) {
        printf("Correct PIN!\n");

        // Call levelup
        char *levelup = "/usr/local/bin/levelup";
        char *argv[] = { levelup, NULL};
        char *envp[] = { NULL };
        execve(levelup, argv, envp);

        return 0;
    } else {
        printf("Incorrect PIN...\n");
        return 1;
    }
    return 0;
}
