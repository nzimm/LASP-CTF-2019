/*
 * gcc -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Simple SGID wrapper for ls
 */
int main(int argc, char* argv[])
{
    char ls[] = "/usr/bin/ls ";

    // If no arguments, just run command
    if (argc < 2) {
        printf("%s\n", ls);
        system(ls);
    }

    // Otherwise concatenate command with first argument
    else {
        char *full_command;
        size_t commandLen;

        // Calculate full string length
        commandLen = strlen(ls) + strlen(argv[1]) + 1;
        full_command = (char *) malloc(commandLen);

        // Create full command string
        strncpy(full_command, ls, commandLen);
        strncat(full_command, argv[1], (commandLen - strlen(ls)) );

        // Execute command string
        printf("%s\n", full_command);
        system(full_command);

    }
    return 0;
}
