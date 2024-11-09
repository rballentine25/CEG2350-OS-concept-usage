## Lab 09

- Name: Rachael Ballentine
- Email: ballentine.7@wright.edu

## Part 1 - Game the system

- Game name: `ninvaders`
- How to install: `sudo apt install ninvaders`
- Location of game executable: `/usr/games/ninvaders`
- How to run game: `ninvaders`

## Part 2 - Process Control

1. `ps` field descriptions:
   - USER / UID: `the user running the process`
   - PID: `the process ID number` 
   - PPID: `parent process ID number`
   - TTY: `controlling terminal for the process`
   - STAT: `the state of the process (state code)`
   - COMMAND / CMD: `the name of the command that started the process`
2. `ps` command:
```
ps xo user,pid,ppid,tty,stat,cmd
x option shows processes without controlling terminal
o option allows you to specify which columns are displayed
```

3. Output of `ps` with two shells, one running the game:
```
ubuntu@ip-10-0-0-25:~$ ps xo user,pid,ppid,tty,stat,cmd
USER         PID    PPID TT       STAT CMD
ubuntu       845       1 ?        Ss   /lib/systemd/systemd --user
ubuntu       846     845 ?        S    (sd-pam)
ubuntu       931     842 ?        S    sshd: ubuntu@pts/0
ubuntu       932     931 pts/0    Ss   -bash
ubuntu      1035     975 ?        S    sshd: ubuntu@pts/1
ubuntu      1036    1035 pts/1    Ss   -bash
ubuntu      1096    1046 ?        R    sshd: ubuntu@pts/2
ubuntu      1097    1096 pts/2    Ss   -bash
ubuntu      1328     932 pts/0    S+   vim Lab09.md
ubuntu      1333    1036 pts/1    S+   ninvaders
ubuntu      1336    1097 pts/2    R+   ps xo user,pid,ppid,tty,stat,cmd
```
4. For the game:
   - Process id: `1333`
   - Parent process id: `1036` 
   - What is the parent process: `-bash` 
5. `kill` to kill only the game:
   - Describe what the effect was: `running "kill 1333" in Shell B closed ninvaders in Shell A 
and it wasn't listed in the active processes anymore when the ps command was rerun in Shell B` 
6. `kill` to kill the game and it's parent process: 
   - Describe what the effect was: 
```
the new process id for Ninvaders was 1372. I ran "kill 1372" and ninvaders closed, then I tried
"kill 1036" to kill the parent. that didn't do anything (1036 was still listed when I ran ps) so
I used SIGKILL and ran "kill -9 1036". this gave output "Connection to 52.73.170.36 closed." in 
Shell A and logged me out of the aws instance
```
7. Describe what happens if you close / `exit` your connection with Shell C and determine if you can reenter the game (resume the process).
   - Answer:
```
you can start a new game process but you can't reenter the one you were in while running Shell C 
because its parent bash process is also gone (i think? not really sure what this is asking for)
```

## Part 3 - back and fore

1. Run in the foreground: `ninvaders`
2. `STOP` signal to suspend it: `ctrl + z to send SIGSTP signal`
3. Proof of life from `ps` output: 
```
ubuntu      1662    1620 pts/1    T    ninvaders
```
4. Resume in the foreground: `fg`
5. `TERMINATE` signal to kill it: `ctrl + c to send SIGINT signal` 
6. Start as a background process: `add an ampersand: "ninvaders &". it started them already
in stopped status`
7. Output of `jobs` from controlling terminal: 
```
ubuntu@ip-10-0-0-25:~$ jobs
[1]   Stopped                 ninvaders
[2]-  Stopped                 ninvaders
[3]+  Stopped                 ninvaders
```
Output of `ps`:
```
ubuntu@ip-10-0-0-25:~$ ps xo user,pid,ppid,tty,stat,cmd
USER         PID    PPID TT       STAT CMD
ubuntu       845       1 ?        Ss   /lib/systemd/systemd --user
ubuntu       846     845 ?        S    (sd-pam)
ubuntu       931     842 ?        S    sshd: ubuntu@pts/0
ubuntu       932     931 pts/0    Ss   -bash
ubuntu      1096    1046 ?        R    sshd: ubuntu@pts/2
ubuntu      1097    1096 pts/2    Ss   -bash
ubuntu      1555     932 pts/0    S+   vim Lab09.md
ubuntu      1619    1560 ?        S    sshd: ubuntu@pts/1
ubuntu      1620    1619 pts/1    Ss+  -bash
ubuntu      1694    1620 pts/1    T    ninvaders
ubuntu      1697    1620 pts/1    T    ninvaders
ubuntu      1698    1620 pts/1    T    ninvaders
ubuntu      1704    1097 pts/2    R+   ps xo user,pid,ppid,tty,stat,cmd
```
8. Kill job: 
```
in Shell A (where game was started):
to find PID of one of the jobs to kill: "pgrep ninvaders"
then to kill: "kill -KILL 1694" where -KILL does same as -9 to send SIGKILL signal (INT won't work)
could also run "kill -9 1694" right from shell B 
```
9. Move job to the foreground: `fg JOBID, so "fg 2" moves the second ninvaders (PID 1697) to fg`
10. Describe what happens, using process knowledge in your description, if you close / `exit` your connection with this shell and determine if you can reenter the game (resume the process).
   - Answer: ` same as in part 2, you can't reenter because both the process and its parents are
gone? `

## Part 4 - Detach

1. Create a `tmux` session:
2. Detach from the session:
3. `ps` command:
```
Output of command goes here
```
4. Command to list `tmux` sessions:
```
Output of command goes here
```
5. How can you determine if your `tmux` session with your game running is available?
   - Answer: 
7. Reattach to `tmux` session:
8. Kill `tmux` session: 
