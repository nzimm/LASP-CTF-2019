# Level13 - shellcode in the environment
For this level, you'll need to find another way to get your shellcode onto
the stack, as the buffer isn't large enough.

Recall the structure main's stack frame:
  |   ... ... ... ...   |
  |   local variables   |
  | saved frame pointer | <-- ebp
  |   return address    |
  |        argc         |
  |        argv         |
  |        envp         |
  |environment variables|

This may or may not have been covered in the advanced lecture - if you've made
it this far, I'd be more than happy to give a more detailed description.

## Tips
- Bash will pass it's environment on to programs it executes. Try searching
  exporting an obvious environment variable, say `export test=AAAAAAAAA...`
  and looking for it in GDB.

- The addresses of environment variables are much more subject to change than
  stack variables. Keep this in mind when setting up shellcode and choosing a
  return address.
