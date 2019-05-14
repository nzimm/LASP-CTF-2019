# Level7 - basic command injection
Similar to level5, level7 does not call levelup directly. You need to figure
out how to make the binary to run a different, or an additional, command

## Tips
- the C `system(const char *command)` function runs `command` as if you typed
  it into your command prompt: from simple commands to complex pipes.
