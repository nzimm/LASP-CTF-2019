# Level4 - introduction to cron, decyphering bash scripting
For this level you'll need to research cron, and find a way to get the level4
password. The following is the output of `crontab -u level4 -l`

```
*/1 * * * * /bin/bash /ctf/level4/run.sh
```

Unless you're already familiar with bash scripting, you might have to do some
additional research on bash to figure out how to script works.

NOTE: if you mess anything up solving this level, please let me know so I can
      reset it

## Relevant commands/search terms
cron    - daemon to execute scheduled commands
crontab - maintains crontab files for individual users

## Tips
- You don't need to edit any crontabs for this level
- The Wikipedia page on cron is actually pretty good, and a bit more clear than
  the cron and crontab manpages
