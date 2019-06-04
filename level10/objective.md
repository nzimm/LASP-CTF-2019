# Level10 - buffer overflows continued
This is another buffer overflow, but you'll need to exploit it to make `levelup`
run yourself. Check out the source and fuzz the input.

Fuzzing is a way to find implementation bugs by using non-expected input:
- providing a char where an int is expected
- providing negative ints to a program expecting positive values
- providing an excesively long filename

## Tips
- You can use python to provide input the the level with
  `python2 -c "print 'A'*20" | ./level9`

- Unlike most cases, a `segmentation fault` is actually a sign that you're doing
  something right! It usually means that you've overwritten a value that the
  program needed to function nominally.

- The primary resource for a technical understanding of buffer overflows
[Smashing the Stack](https://www.eecs.umich.edu/courses/eecs588/static/stack_smashing.pdf)
