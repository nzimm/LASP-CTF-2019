CC = gcc
CFLAGS = -Wall -Werror -m32 -mpreferred-stack-boundary=2 -fno-stack-protector -z execstack


all: level0.c
	$(CC) $(CFLAGS) level0.c -o level0

clean:
	$(RM) level0
