/*
 * gcc -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // this should be an absolute path, not a relative path
    system("./bin/ls");
    return 0;
}
