#include <stdio.h>
#include <string.h>

// This function exists in memory, but is not called in nominal execution
int secret_function() {
    printf("You've run the secret function!\n");
    return(0);
}

int main() {
    char buff[4];
    scanf("%s", buff);
    printf("%s\n", buff);
    return(0);
}
