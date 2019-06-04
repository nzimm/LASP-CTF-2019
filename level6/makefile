CC = gcc
CLIBS=
CFLAGS = -Wall -Werror -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack

all: level6.c
	$(CC) $(CLIBS) $(CFLAGS) level6.c -o level6

clean:
	$(RM) level6
