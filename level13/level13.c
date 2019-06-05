/*
 * gcc -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
    // Buffer size decreased to prevent shellcode injection
    char buffer[24];
    puts("Enter something...");
    gets(buffer);
    printf("You typed: %s\n", buffer);
    return 0;
}
