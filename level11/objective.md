# Level11 - overflowing return address
Congratulations! You've reached the levels where you will need to start using
GDB. You'll need to overwrite the return address for the `main()` function with
the address for `secret_function()`.

Remember - a seg fault means you're on the right path. First try to produce a
seg fault, then run GDB with the same input.

## Tips
- You can print arbitrary binary data using python2 print statements like:
  `python2 -c "print 'ABCD' + b'\xde\xad\xbe\xef'"`

- GDB is a pain to use, feel free to ask for help if you need a starting point.
  After getting your bearings, you'll start figuring out the stack best by trying
  different inputs and examining the stack.

## intro to GDB
- `$ gdb level11`             - launch gdb on the level11 executable
- `(gdb) b main`              - set a breakpoint at the start of `main()`
- `(gdb) disas [function]`    - display the disassembeled instructions for a function
- `(gdb) x/5xw $ebp`          - examine 5 words of data (displayed in hex) from the
         | |||  |               address ebp is pointing at
         | |||  |
         | |||  `- stack address to start at
         | ||`---- defines the unit of size (b=byte, h=2bytes, w=4bytes,
         | |`----- the format to display data (x=hex, s=string, i=machine instruction, etc.)
         | `------ number of units to examine
         `-------- examine data on the stack
