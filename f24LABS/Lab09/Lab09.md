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
7. Describe what happens if you close / `exit` your connection with Shell C and determine if you can reenter the game (resume the process).
   - Answer: 

## Part 3 - back and fore

1. Run in the foreground: 
2. `STOP` signal to suspend it: 
3. Proof of life from `ps` output:
```
insert line here
```
4. Resume in the foreground:
5. `TERMINATE` signal to kill it: 
6. Start as a background process: 
7. Output of `jobs` from controlling terminal:
```
Insert output here
```
Output of `ps`:
```
Insert output here
```
8. Kill job:
9. Move job to the foreground: 
10. Describe what happens, using process knowledge in your description, if you close / `exit` your connection with this shell and determine if you can reenter the game (resume the process).
   - Answer: 

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
