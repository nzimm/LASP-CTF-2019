CC = gcc
CLIBS=
CFLAGS = -Wall -Werror -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack

all: level2.c
	$(CC) $(CLIBS) $(CFLAGS) level2.c -o level2

clean:
	$(RM) level2
