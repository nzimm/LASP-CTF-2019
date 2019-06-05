/*
 * gcc -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack
 */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    // Get user's home directory
    uid_t user_ID = getuid();
    char *home_dir_temp = getpwuid(user_ID)->pw_dir;
    char home_dir[strlen(home_dir_temp) + 1];
    strncpy(home_dir, home_dir_temp, sizeof(home_dir));

    // Check that turnip exists
    char *file_name = ".turnip.txt";
    char file_path[strlen(home_dir) + strlen(file_name) + 2];
    sprintf(file_path, "%s/%s", home_dir, file_name);

    struct stat file_stat;
    // Check that file exists
    if ( stat(file_path, &file_stat) != -1 ) {

        // Check that file has correct group and permissions
        const char *file_grp = getgrgid(file_stat.st_gid)->gr_name;

        if ( (access(file_path, X_OK) == 0) && (strcmp(file_grp, "level0") == 0) ) {

            printf("Well done! Feel free to proceed to level 2\n");

            // Call levelup
            char *levelup = "/usr/local/bin/levelup";
            char *argv[] = { levelup, NULL};
            char *envp[] = { NULL };
            execve(levelup, argv, envp);
        }

        // Conditions not met
        else {
            printf("Make sure the file has correct group and permissions\n");
        }
    }
    else {
        printf("%s: error: make sure to read the objectives...\n", argv[0]);
    }

    return 0;
}
