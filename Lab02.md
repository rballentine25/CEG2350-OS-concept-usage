## Lab 02
- Name: Rachael Ballentine
- Email: ballentine.7@wright.edu
// date: 9/10/24

## Part 1 Answers

1. Command & steps to create an SSH key pair
```
1. in WSL: ssh-keygen -t ed25519
2. choose where to save the key files (enter for default, or path for new file)
3. enter a password (or don't)
```

3. Steps to add public key to GitHub profile:
```
1. in WSL: cat .ssh/id_ed25519.pub
2. copy contents of id_ed25519.pub (the public key)
3. open GitHub and go to settings -> ssh keys -> create new keypair
4. create a title and paste contents of id_ed25519.pub (public key)
5. save
```

3. git command to clone repository: 
```
git clone git@github.com:WSU-kduncan/ceg2350f24-rballentine25.git
```

## Part 2 Answers

The answers for this section are to help you record what steps  
are needed to create a file locally (in your cloned repo)  
and push them (sync) with GitHub.  Only `git` commands are 
valid answers

1. git command to view the status of the repository:
   <br> ``` "git status" ```
3. git command example to add a file for tracking:
   <br> ``` "git add filename.txt" ``` for an individual file or ``` "git add ." ```to add all 
5. git command to commit changes:
   <br> ``` git commit -m "COMMIT MESSAGE" ```
7. git command to sync local commits with GitHub:
   <br> ``` git push ```
9. git command to sync commits on GitHub to `clone`d repository:
   <br> ``` git pull ```

## Part 3 Answers

1. `chmod u+r bubbles.txt`
    - Means: give user permission to read bubbles.txt
2. `chmod u=rw,g-w,o-x banana.cabana`
    - Means: give user exclusive permission to read and write, remove group permission to write, remove others permission to execute on file banana.cabana 
3. `chmod a=w snow.md`
    - Means: give all (user, groups, and other) exclusive permission to write on snow.md (all groups are allowed to write, but not read or execute)
4. `chmod 751 program`
    - Means: for the file "program", give users permission to read, write, and execute. give groups permissions to read and execute. give others permission to (only) execute. permissions would read:
    ```- rwx r-x --x ```
5. `chmod -R ug+w share`
    - Means: recursively give users and groups permission to write on the directory "share"

## Part 4 Answers

1. Command to create new user: ``` sudo adduser USERNAME ``` 
2. Path to user's home directory: ``` /home/rballentine ```
3. Evaluate if `ubuntu` can add files to user's home directory: no, because the user's home directory is owned by the user, and permissions for groups and others are set to read and execute (group) or execute only (others)
4. Command to switch to user: ``` sudo su rballentine ```
5. Command(s) to go to user's home directory: ``` cd /home/rballentine ```
6. Evaluate if user can add files to user's home directory: yes, the user can add files to their own directory. this is because the user owns the directory, and the permissions are set to read, write, execute for the user
7. Command to switch to `ubuntu`: ```exit```
8. Command to return to `ubuntu` home directory: ``` cd /home/ubuntu```

## Part 5 Answers

For each, write the command used or answer the question posed.

1. Command to create group named `crew`: ``` sudo addgroup crew```
2. Command(s) to add `ubuntu` & user to group `crew`: 
<br>
```
sudo usermod –aG crew ubuntu
sudo usermod -aG crew rballentine
```
3. Command to modify `share` to have group ownership of `crew`: ``` sudo chgrp crew . ```
4. Command to switch to user: ``` su rballentine ```
5. Command to add file to `share`: ``` touch carrots.txt ```
6. Evaluate why these steps allowed the above action: this was successful because groups were given permissions to read, write, and execute. the file that rballentine made is owned by that user though, so unless the I specifically gave the group crew access to that file, then rballentine would still be the only one able to access it even though it is inside the folder with group permissions

## Part 6 Answers

For each, write the command used or answer the question posed.

1. Command to create file using `sudo`: ``` sudo touch /home/ubuntu/sudowho.txt```
2. Evaluate (in plain text) the permission of the file: user has read and write permissions, but not execute. groups and others have exclusive read permissions
3. Provide a method to edit the file without modifying permissions: ``` sudo vim sudowho.txt ```
4. Command(s) to modify permissions: ``` sudo chown ubuntu:crew sudowho.txt```
