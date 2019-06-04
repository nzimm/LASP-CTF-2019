CC = gcc
CLIBS=
CFLAGS = -Wall -Werror -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack

all: level5.c
	$(CC) $(CLIBS) $(CFLAGS) level5.c -o level5

clean:
	$(RM) level5
