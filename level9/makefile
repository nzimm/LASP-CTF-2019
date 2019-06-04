CC = gcc
CLIBS=
CFLAGS = -Wall -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack

all: level9.c
	$(CC) $(CLIBS) $(CFLAGS) level9.c -o level9

clean:
	$(RM) level9
