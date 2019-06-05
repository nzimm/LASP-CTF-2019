/*
 * gcc -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SIZE 7

void
print_list(unsigned int list[], int len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", list[i]);
    }
    puts("");

/* DEBUG
    for (int i = 0; i < len; ++i)
    {
        printf("%x ", list[i]);
    }
    puts("");
*/
}

int
main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("usage: %s INDEX VALUE\n", argv[0]);
        exit(1);
    }

    unsigned int list[SIZE] = {1, 1, 2, 3, 5, 8, 13};
    print_list(list, SIZE);

    int index, value;
    index = strtol(argv[1], NULL, 10);
    value = strtoll(argv[2], NULL, 16);
    printf("writing %x index %d\n", value, index);

    list[index] = value;

    print_list(list, SIZE);

    return 0;
}
