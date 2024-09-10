## Lab 02
// completed: 1, 2, 3, 
// in progress: 4
// not done: 5, 6

- Name: Rachael Ballentine
- Email: ballentine.7@wright.edu

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
    - Means: 
5. `chmod -R ug+w share`
    - Means: recursively give users and groups permission to write on the directory "share"

## Part 4 Answers

1. Command to create new user:
   <br>
   ```
   sudo adduser USERNAME
   (may need to add --force-badname after adduser)
   ```
    or
    ```
   adduser USERNAME
   sudo!!
   ```
   
3. Path to user's home directory: 
4. Evaluate if `ubuntu` can add files to user's home directory:
5. Command to switch to user:
<br>
```
sudo su USERNAME
```
7. Command(s) to go to user's home directory:
8. Evaluate if user can add files to user's home directory:
9. Command to switch to `ubuntu`:
10. Command to return to `ubuntu` home directory: 

## Part 5 Answers

For each, write the command used or answer the question posed.

1. Command to create group named `crew`:
2. Command(s) to add `ubuntu` & user to group `crew`:
3. Command to modify `share` to have group ownership of `crew`:
4. Command to switch to user:
5. Command to add file to `share`: 
6. Evaluate why these steps allowed the above action:

## Part 6 Answers

For each, write the command used or answer the question posed.

1. Command to create file using `sudo`: 
2. Evaluate (in plain text) the permission of the file: 
3. Provide a method to edit the file without modifying permissions: 
4. Command(s) to modify permissions:
