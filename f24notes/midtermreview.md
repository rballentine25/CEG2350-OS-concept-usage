# Midterm Review for CEG 2350
---
list of lab topics:
- Lab #1: not relevant dont look at it
- Lab #2: steps to create ssh keypair and add to gitHub. Git commands. chmod. create and switch between users
- Lab #3: ssh config file. piping/appending/overwriting (|, >, >>, <<). PATH. command line args
- Lab #4: task tracker bash script using command line args/loops/functions.
- Lab #5: sed, awk, and regex
- Lab #6: getopts

## Intro topics

1. How did the modern computer come to be?
SKIPPING THIS FOR NOW

2. Shells
<br> A shell is a command interpreter program that enables users to interact with an OS. Types of shells:  
   - Windows: powershell, cmd
   - Linux / Mac: bash, sh, zsh
3. SSH
<br> ssh is a secure shell. it is a network protocol used for operating network services securely over an unsecured network. It provides a mechanism for establishing a cryptographically secured connection. 
- `ssh -i ceg2350key.pem ubuntu@52.73.170.36`
  <br>-i flag is the identity flag, which is the file that contains the private key for the key pair being used.
  <br>syntax for ssh in this format is `ssh -i path_to_key ubuntu@AWS_IP`
- ssh keys come in public-private key pairs. they are usually stored on your PC in a hidden file named .ssh (dot makes invisible)
- to create a keypair: use command `ssh-keygen -t ed25519`
  <br> -t specifies the type of key to create and the ed25519 is one of those options
- adding key to GitHub: copy contents of .pub file from key into GitHub, then use the ssh command to clone the repo
- WHERE AND WHAT PERMISSIONS: both public and private keys go into hidden .ssh folder.
  <br>private key should have read and write access for user ONLY. should be (-rw-------).
 <br>Public key should have read/write for user and read for everyone else (-rw-r--r--)
- CONFIG FILE: config file may not exist. must have chmod 600 permissions (-rw-------). once set up, provides shortcut for ssh command `ssh hostname1`. takes structure<br>
```
Host hostname1
   HostName IPADDRESS
   User UBUNTU
   IdentityFile PATH_TO_KEY
   Port 22
```

## Files, directories, and OS structure

1. OS structure in Linux (and Mac) vs Windows
   <br> TREE BASE: `C:\` in Windows, `/` in linux/mac
   <br> other stuff with kernels, etc but we haven't gotten to that
3. Files vs directories: 
   - Commands: ls, cp, mkdir, rmdir, vim, mv, rm, cd, cat, touch, head/tail, less/more
4. Importance of names and extensions (file)
   <br> file types: .md, .txt, .sh, etc
   <br>
6. __Ownership & sharing__
   - rwx: read (4), write (2), execute (1). execute allows running a file as a program or entering the directory
   - classes: "user" is the owner of the file. this is usually the creator but ownership can be changed with `chown` command
     <br>"group" is users in the same group as file owner
     <br> "other" is any other users on the system who dont match the first two criteria
   - __creating users__: `sudo adduser USERNAME`. Username should be all lowercase in new_user format (may have to use `--force-badname`)
     <br> to see all users, run `cat /etc/passwd` and new users will be at bottom
     <br> to switch between users: `su username` and use exit to go back to default user
     <br> `deluser` to delete a user
   - __creating groups__: `addgroup group_name`
     <br> to add a user to a group: `sudo usermod -aG group_name user_name`. aG is append groups
     <br> run `cat /etc/group` to see all groups and their members, or `getent group groupname` to see the members of just a particular group
     <br> to change group permissions on a file: `sudo chgrp group_name file_or_folder`
   - __sudo & the root user__: root user is "superuser" and has access to entire system. it has full control and override permissions and is the only user able to do certain system admin tasks.
     <br> to protect the system, __you dont have root access__ but you can execute commands as the root user using `sudo`
7. PATH vs path and environment variables
   - relative path: where you are, ex currfolder/myfile
   - absolute path: full directory path
   - __PATH__ is an environment variable that tells the system where to look for executable files. it is a list of directories that the shell searches through to find files to run. you can make a script executable from any folder by adding it to the /bin folder, since /bin is included in PATH
   - you can view PATH with `echo $PATH`
   - printenv prints all environment variables
   - you can see path setup by `vim ~/.profile`
   - to add a folder to path: `export PATH="$filepath:$PATH"` ex adding folder named "new" located in Home directory: `PATH="$HOME/new:$PATH`

## Scripting

1. Aliases & customizations (.bashrc, .profile)
   - `~/.bashrc` is specific to bash and includes aliases and things specific to the bash shell.
   - aliases for certain commands can be put in the bottom of the .bashrc file, ex. `alias LabFiles='cd /home/ubuntu/ceg2350f24-rballentine25/f24LABS'`
   - `~/.profile` is stuff that applies to whole session, such as programs you want to start when you login and environment variable definitions. PATH is defined here
3. IO redirection (streams (standard input, output and error), <, >, >>, |, tee)
   - `stdin = 0` standard input
   - `stdout = 1` standard output
   - `stderr` standard error
   - REDIRECTION `command > outputfile` overwrites the output of the command to the output file.
     <br> see Week03/IOredirection slide 17 for how to write only certain output to files or to standard output/error
   - APPEND `command >> file` appends the output of the command to the file
   - INPUT REDIRECT ` command < input` uses the file or input source to the command as input
   - PIPING `command1 | command2` command2 uses the output of command1 as its input, ex `echo "hello world" | helloworld.txt` saves the text "hello world" to the file helloworld.txt
5. executing scripts (source, bash, ./, PATH)
   - to execute: need `#!/usr/bin/bash` at top of script
   - make file executable by changing permissions
   - now can run by using `bash filename`, `./filename`, or by putting the script in a file on the PATH, can run with just filename
7. Scripting languages: bash
   - variables: `var_name=value`
   - arguments, reading input:
        - `$#` for number of cmd line args
        - `$@` to list all cmd line args
        - 
   - printf vs echo: printf syntax: `printf "formatstring" arguments`, ex `printf "sum of %d and %d is %d" "$a" "$b" $((a+b))`
     <br> remember math expressions have to be inside double parens
   - conditionals (`test`):
     <br> strings: = and !=
     <br> integers: `-eq -ne -ge -le -gt -lt`
   - if
     ```
     if [[ condition ]]; then
        # code
     elif [[ condition ]]; then
        # code
     fi
     ```
   - for
     ```
     for fruit in apple banana orange; do
        # code
     done
     ```
     OR
     ```
     for (( i=0; i<100; i++ )); do
        # code
     done
     ```
   - while
     ```
     loopvar=0
     while [[ $loopvar -le 5 ]]; do
        # code
        (( loopvar++ ))
     done
     ```
   - getopts: all option args stored in $OPTARG.
     <br> the optionstring should be in format `:hf-r-
     where colon means error reporting will be silent, h
     doesnt require input but f and r do
     <br> __more notes in f24notes folder!!__ 
     ```
     while getopts "optionstring" varname; do
        case "$varname" in
        #) newvar=$OPTARG
           ;;
        #)
           ;;
        #)
           ;;
        \?) #catches any unknown option args
           ;;
        esac
     done

      shift $$(( OPTIND - 1 ))
     ```
   
   - case
    ```
    read inputname
    case $inputname in
      opt1) 
         # code
         ;;
      opt2)
         # code 
         ;;
      *) 
         # code: * is all other input that doesn't match given case options
         ;;
    esac
    ```
   
8. Regular expressions
   - [datacamp](https://www.datacamp.com/cheat-sheet/regular-expresso)
   - [regex101](https://regex101.com/)
   - remember to enable regex expressions in things with option flags!
10. grep (search), sed (find & replace), and awk (manipulate formatted data)
    - __GREP__ `grep [options] pattern [file]`
         - flags: -i (ignore case), -v (invert match, select non-matching lines), -r (search recursively)
         - grep outputs to standard output. must pipe or redirect (` grep "phrase" test.txt > output.txt`) to save. can also pipe counts like `grep "phrase" test.txt | wc -l`
      - __SED__: stream editor! `sed [options] 'command' [file]`
         - flags: -i (modify og file), -n (supress auto printing)
         - within command: `s/find/replace/g` to replace all instances of the find phrase with the replace phrase. s means substitute, g means global
      - __AWK__: scanning processing. `awk 'pattern { action }' [file]`
        - awk scans files for fields, which are default separated by a space. to change delimiter, use `-F "delim"`, ex `-F ","` for comma delimiter
        - can do things like ` awk '{ print $0 }' employee.txt` to print all fields in the file
        - or `awk '{ print $1, " ", $4}' employee.txt` will print columns 1 and 4 separated by a space
     

## Computer Hardware, Boot Process, and Data on Disks:

1. Computer Hardware:
   - CPU: central processing unit. includes the ALU (arithmetic logic unit), CU (control unit), registers, clock speed, and does all instruction execution. 
   - RAM: random access memory. volatile memory, as it loses all stored data when power is turned off. much faster than hard drives. provides temp storage for data/programs that the CPU is using. 
   - Motherboard: main circuit board of the device. houses the CPU and RAM
   - Disks (HDD, SSD, NVME):
        - HDD = hard disk drive. has a disk that is spun and read with an actuator arm
        - SSD: solid state drive. uses flash memory to store data
        - NVME: non volatile memory express. is actually a highspeed interface protocol for SSDs
   - GPU (discrete / dedicated vs integrated): graphics processing unit. specialied processor to accelerate rendering of images, etc.
        - integrated: built directly into CPU, shares RAM with CPU. more basic, found in laptops and budget systems.
        - discrete/dedicated: separate graphics card installed in a slot on the motherboard. has its own dedicated memory and processing resources
     

## Git (version control)

1. Git remote (servers) vs. clients (local)
2. Basic commands:
   - clone
   - add
   - commit
   - push
   - pull
   - status
3. __merge conflicts__ happen when you forget to pull before working on a local copy. steps to resolve merge conflict:
   * `git pull --rebase`
   * enter merge message then hit ctrl+x and enter to exit
