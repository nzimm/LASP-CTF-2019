/*
 * gcc -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {

    char command[24] = "/ctf/level10/bin/";
    char file_path[128];

    // Check for correct number of arguments
    if (argc != 3) {
        printf("Wrong number of arguments\n\n");
        printf("usage: %s COMMAND FILE\n", argv[0]);
        printf("    COMMAND         [ uniq | cat | ls ]\n");
        printf("    FILE            file to run command on\n");

        return(1);
    }

    // Check argv[1]
    printf("Checking filename %s%s\n", command, argv[1]);

    if (strncmp("ls", argv[1], strlen("ls")) == 0 ||
        strncmp("cat", argv[1], strlen("cat")) == 0 ||
        strncmp("uniq", argv[1], strlen("uniq")) == 0 )
    {
        strcat(command, argv[1]);
    }

    else
    {
        printf("%s: error: invalid command\n", argv[0]);

        return(1);
    }

    // Store argv[2] and execute command
    strcpy(file_path, argv[2]);

    printf("executing %s %s\n\n", command, file_path);

    char *args[] = { command, file_path, NULL };
    execve(command, args, NULL);

    return 0;
}
