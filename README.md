# Dice Roller

To compile, just run

gcc dice.c -o dice

or use the C compiler of your choice. Works on Linux,
probably FreeBSD too, but that's really just a guess.
It shouldn't be hard to tweak the code to get it to run
on Windows, if it doesn't already (it does depend a bit
on /dev/urandom, but I'm sure it could be ported without
much fuss). The whole thing is just 50 lines of code or so,
if you don't count the help message. 

For interactive use, just run "dice", and then enter
the number and kind of dice to roll at the prompt, in the
format "XdY", where X is the number and Y is the kind of
dice to roll.

Or, you can supply the number-d-kind string as a command-
line argument, and roll dice directly from the shell.

