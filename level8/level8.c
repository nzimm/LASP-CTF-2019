#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Simple SGID wrapper for ls
 *   [*] Now, with input sanitization!
 */
char *sanitize(char unsafe[])
{
    int i, j;

    // Loop over unsafe input
    for (i = 0; unsafe[i] != '\0'; i++)
    {
        // Check for danger characters
        while (unsafe[i] == '|' || unsafe[i] == '&' ||
               unsafe[i] == ';' || unsafe[i] == '`')
        {
            // Shift remaining characters left
            for (j = i; unsafe[j] != '\0'; j++)
            {
                unsafe[j] = unsafe[j+1];
            }
            // Ensure string is null-terminated
            unsafe[j] = '\0';
        }
    }
    return unsafe;
}

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

        // Sanitize command string
        char *safe_command = sanitize(full_command);

        // Execute command string
        printf("%s\n", safe_command);
        system(safe_command);

    }
    return 0;
}
