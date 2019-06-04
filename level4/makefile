CC = gcc
CLIBS=
CFLAGS = -Wall -Werror -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack

all: level4.c
	$(CC) $(CLIBS) $(CFLAGS) level4.c -o level4

clean:
	$(RM) level4
