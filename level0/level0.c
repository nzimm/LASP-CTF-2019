#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

#define LONG_PATH_SIZE 15

int main()
{
    // Note: if students have read access to the executable, they can discover
    // these strings by running `ltrace` or using GDB - could be fixed with a
    // config file, but makes for a good example
    const char *login_shell_short = "fish";
    const char *login_shell = "/usr/bin/fish";
    const char *bash_shell = "/bin/bash";
    char guess[LONG_PATH_SIZE];

    // Part 1, get user's answer
    printf("What was your default login shell?\n");
    fgets(guess, LONG_PATH_SIZE, stdin);

    // Set tailing newline to \0
    guess[strlen(guess) - 1] = '\0';

    // Check answer - both `fish` and `/usr/bin/fish` are valid
    if ( strncmp(guess, login_shell, strlen(guess)) == 0 || 
         strncmp(guess, login_shell_short, strlen(guess)) == 0 ) {

        printf("Correct! ");

        // Part 2, check if the user has changed their login shell to bash 
        uid_t ruid = getuid();
        struct passwd *user_data;
        user_data = getpwuid(ruid);

        if ( strncmp(user_data->pw_shell, bash_shell, strlen(bash_shell)) == 0 ) {
            printf("Feel free to set your login shell to your preference.\n");
            
            // Call levelup
            char *levelup = "/usr/local/bin/levelup";
            char *argv[] = { levelup, NULL};
            char *envp[] = { NULL };
            execve(levelup, argv, envp);
        }

        else {
            printf("Before moving on to level 1, change your login shell to "
                   "bash (you can switch it to whichever shell you'd like "
                   "after passing this level). \n");
            return 1;
        }
    }
    else {
        printf("Hmm, that doesn't look quite right...\n");
        return 1;
    }
    return 0;
}
