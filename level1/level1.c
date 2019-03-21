#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    // Get user's home directory
    uid_t user_ID = getuid();
    char *home_dir_temp = getpwuid(user_ID)->pw_dir;
    char home_dir[strlen(home_dir_temp) + 1];
    strncpy(home_dir, home_dir_temp, sizeof(home_dir));

    printf("home dir: %s\n", home_dir);

    // Check user's home directory permissions
    printf("Checking permissions...\n");

    return 0;
}
