CC = gcc
CFLAGS = -m32 -mpreferred-stack-boundary=2 -fno-stack-protector

all: vuln.c
	$(CC) $(CFLAGS) vuln.c -o vuln

clean:
	$(RM) vuln
