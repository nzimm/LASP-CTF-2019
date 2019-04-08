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

    printf("home dir: %s\n", home_dir);

    // Check for special file
    char *file_name = "turnip.txt";
    char file_path[strlen(home_dir) + strlen(file_name) + 2];
    sprintf(file_path, "%s/%s", home_dir, file_name);

    struct stat result_file;
    if ( stat(file_path, &result_file) != -1 ) {
        // DEBUG
        printf("%s has group %s\n", file_path, getgrgid(result_file.st_gid)->gr_name);
    }
    else {
        printf("%s: error: couldn't stat %s\n", argv[0], file_path);
    }
    struct stat result_home_dir;

    // Check user's home directory permissions
    printf("Checking permissions...\n");

    if (stat(home_dir, &result_home_dir) != -1) {
        printf("%o\n", result_home_dir.st_mode);
    }

    return 0;
}
