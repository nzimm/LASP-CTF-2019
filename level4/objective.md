# Level4 - introduction to cron, decyphering bash scripting
For this level you'll need to research cron, and how you can use the installed
crontab to get the password. The following is the output of `crontab -u level4 -l`

```
*/1 * * * * /bin/bash /ctf/level4/run.sh
```

Unless you're already familiar with bash scripting, you'll probably have to do
some additional research on bash to figure out how to script works.

## Relevant commands
crontab - Linux scheduling daemon

## Tips
- You don't need to edit any crontabs for this level
- The Wikipedia page on cron is actually pretty good, and a bit more clear than
  the cron and crontab manpages
