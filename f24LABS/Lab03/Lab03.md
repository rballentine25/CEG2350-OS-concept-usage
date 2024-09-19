## Lab 03

- Name: Rachael
- Email: ballentine.7@wright.edu
- Date: 9/18/24

## Part 1 Answers

1. `ssh` command before configuring `config` file: ```ssh -i ceg2350key.pem ubuntu@52.73.170.36```
3. HostName: 52.73.170.36
4. User: ubuntu
5. IdentityFile: /home/rballentine/ceg2350key.pem
6. `~/.ssh/config` contents:

```
Host 2350
        HostName 52.73.170.36
        User ubuntu
        IdentityFile ~/ceg2350key.pem
        Port 22
```

6. `ssh` command after configuring an entry in the `config` file: ``` ssh 2350 ```

## Part 2 Answers

1. `printenv HOME > thishouse`
   - Explanation: `printenv` prints values of environment variables. in this case, prints the value of `HOME` variable (path to the HOME directory) to a file named `thishouse`, so the file now contains `/home/rballentine`
2. `cat doesnotexist 2>> hush.txt`
   - Explanation: `cat` prints a file to standard output. `2>>` appends (not replace) only error output to the indicated file. this line redirects and appends the error output of `doesnotexist` to the file `hush.txt`. 
3. `cat nums.txt | sort -n >> all_nums.txt`
   - Explanation: ```|``` is pipe, which means that output from the first command (`cat nums.txt`) will be passed as input to the next command. `sort -n` sorts lines of text files, in this case numerically as indicated by the flag. this output is appended to the file `all_num.txt` because of the `>>` operator, so that the file now contains the sorted values entered in `nums.txt`
4. `cat << "DONE" > here.txt` 
   - Explanation: `<<` takes in user input until the delimiter is reached, which here is `DONE`. the output from `cat` is then redirected to the file `here.txt`, so the file contains the user input
5. `ls -lt ~ | head`
   - Explanation: `ls` lists directory contents. `-lt` flags mean use long listing format (`l`) and sort by time, newest first (`t`). The tilda is shorthand for the home directory. `| head` is asking for the first 10 lines (`head`) of the last command, so the result of this line is the first 10 lines of the files in the home directory is outputted to console, ordered by time. 
6. `history | grep ".md"`
   - Explanation: `history` lists recent commands to the console. `grep ".md"` searches for patterns in the given input, here looking for `".md"`. the result is that all recent commands that include the phrase ".md" are listed to the console

## Part 3

Verify that `roll` made it to your GitHub repository for this course and is in your `Lab03` folder.  No answers will be written here unless you would like to leave a note to the TAs

## Part 4 - Retrospective Answers

1. Where and when did it go wrong while working on your script tasks?
> When writing the first if conditionals, I was trying to check not equal and I wrote `-nq` instead of `-ne` and couldn't figure out why I was getting an error message for a while. then later in part 6 I was trying to use a newline character (`\n`) and it wasn't showing up in echo, so I tried `/n` and that did something else weird. I had to look up the echo flags and use `-e` to get the newline char to show, but I was stuck on that for a while. I'm sure there was other stuff but I don't rememebr
2. Was anything familiar working with a new language compared to one you are used to?
> I mean the basic concepts are still the same but there are a lot of differences between bash and what i'm used to, which is mostly java/python/matlab. i don't like that variables and conditionals don't work without correct spacing
3. Did you write good `commit` messages that refer to what tasks were completed at each commit?  What would you improve?
> i just named them "finished part 3.#". i would be more descriptive if i weren't specifically only committing when certain pre-outlined tasks were completed 

## Part 5 Answers

1. PATH = `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin`
2. To set condition to `true`, I need to...
   ` create a directory named bin if there isn't already one and move the file to that bin`
3. Command(s): 
```
cd ~
mkdir bin
```
4. PATH = `/home/ubuntu/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin`
   - Difference: `theres now a path to the new bin I created at the beginning of the PATH variable`
5. Command(s):
```
pwd bin
cd ceg2350f24-rballentine25/f24LABS/Lab03/
cp roll /home/ubuntu/bin/
```
or to do symbolic link (it wouldn't let me make a hard link)
```
pwd roll
cd ~
cd bin
ln -s /home/ubuntu/ceg2350f24-rballentine25/f24LABS/Lab03/roll roll
```
6. Commands & modification explanations: `chmod 711` so that all can execute from wherever
7. Script permission breakdown
   - User
      - must be: ` ? i dont understand the question`
      - has permissions to: `read, write, execute`
   - Group
      - must be:
      - has permissions to: `execute`
   - Other
      - has permissions to: `execute`

## Extra Credit

1. Note here *what* you did to the script for the extra credit.
