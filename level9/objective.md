# Level9 - simple buffer overflow
We're gonna start looking at buffer overflows now. Buffer overflows are a result
of a programs failure to verify the bounds of something it's trying to write to.

You don't *need* to bust out GDB for this level, and in fact I recommend you
start by just fuzzing the program to learn how it handles various length inputs.

## Tips
- You can use python to provide input the the level with
  `python2 -c "print 'A'*20" | ./level9`

- I find python2 print statements more straightforward to work with when printing
  binary, for example: `python2 -c "print 'ABCD' + b'\xde\xad\xbe\xef'"`

- Unlike most cases, a `segmentation fault` is actually a sign that you're doing
  something right! It usually means that you've overwritten a value that the
  program needed to function nominally.

- The primary resource for a technical understanding of buffer overflows
[Smashing the Stack](https://www.eecs.umich.edu/courses/eecs588/static/stack_smashing.pdf)
