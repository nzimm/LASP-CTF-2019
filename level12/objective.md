# Level12 - injecting shellcode
The last level already contained code that you wanted to use - but what if you
want to run custom code? If you can get your code into the process memory and
jump to it, you can execute arbitrary instructions!

Traditional shellcode is a small amount of machine language that spawns a shell
when run by the processor.

I've provided shellcode that will not open a shell, but instead calls levelup
directly. Your goal is to inject the shellcode into the process memory, then
overwrite the return address to point to the start of your shellcode.

## Tips
- For the shellcode to run, you need to overwrite the return address to
  *exactly* the first byte. Consider using a "NOP sled" to increase the target.
  [https://stackoverflow.com/questions/14760587/how-does-a-nop-sled-work]

- If you want a refresher on what the stack looks like, feel free to ask for a
  refresher. Working with GDB is much easier when you know what to expect.

## intro to GDB
- `$ gdb level11`             - launch gdb on the level11 executable
- `(gdb) b main`              - set a breakpoint at the start of `main()`
- `(gdb) disas [function]`    - display the disassembled instructions for a function
- `(gdb) x/5xw $ebp`          - examine 5 words of data (displayed in hex) from the
         | |||  |               address ebp is pointing at
         | |||  |
         | |||  `- stack address to start at
         | ||`---- defines the unit of size (b=byte, h=2bytes, w=4bytes,
         | |`----- the format to display data (x=hex, s=string, i=machine instruction, etc.)
         | `------ number of units to examine
         `-------- examine data on the stack
