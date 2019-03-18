#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

#define LONG_PATH_SIZE 15

int main(int argc, char* argv[])
{
    // Check size of argv
    uid_t ruid = getuid();
    user_data = getpwuid(ruid);
    return 0;
}
