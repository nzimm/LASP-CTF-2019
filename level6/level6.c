#include <stdio.h>
#include <string.h>

int main()
{
    char pin[5], guess[5];
    FILE *file_pointer;

    // Read pin from file
    file_pointer = fopen("./pin.txt", "r");
    fscanf(file_pointer, "%s", pin);

    // Get user guess
    printf("Enter four digit PIN: ");
    fgets(guess, 5, stdin);

    if ( strncmp(pin, guess, 4) == 0 ) {
        printf("Correct PIN!\n");
        return 0;
    } else {
        printf("Incorrect PIN...\n");
        return 1;
    }
    return 0;
}
