CC = gcc
CLIBS=
CFLAGS = -Wall -Werror -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack

all: level7.c
	$(CC) $(CLIBS) $(CFLAGS) level7.c -o level7

clean:
	$(RM) level7
