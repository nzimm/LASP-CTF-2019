CC = gcc
CLIBS=
CFLAGS = -Wall -Werror -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack

all: level3.c
	$(CC) $(CLIBS) $(CFLAGS) level3.c -o level3

clean:
	$(RM) level3
