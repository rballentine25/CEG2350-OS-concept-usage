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

## Scripting

1. Aliases & customizations (.bashrc, .profile)
2. Commands: diff, find, ~~file~~, wc, sort, uniq, whereis, which
3. IO redirection (streams (standard input, output and error), <, >, >>, |, tee)
4. executing scripts (source, bash, ./, PATH)
5. Scripting languages: bash
   - variables
   - arguments, reading input
   - printf vs echo
   - conditionals (`test`)
   - if
   - for
   - while
   - getopts
   - case
6. Regular expressions
7. grep (search), sed (find & replace), and awk (manipulate formatted data)

## Computer Hardware, Boot Process, and Data on Disks:

1. Computer Hardware:
   - CPU
   - RAM
   - Motherboard
   - Disks (HDD, SSD, NVME)
   - GPU (discrete / dedicated vs integrated)

## Git (version control)

1. Git remote (servers) vs. clients (local)
2. Basic commands:
   - clone
   - add
   - commit
   - push
   - pull
   - status
3. merge conflicts
