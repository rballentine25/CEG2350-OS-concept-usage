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
   - Explanation: 
2. `cat doesnotexist 2>> hush.txt`
   - Explanation: 
3. `cat nums.txt | sort -n >> all_nums.txt`
   - Explanation: 
4. `cat << "DONE" > here.txt`
   - Explanation: 
5. `ls -lt ~ | head`
   - Explanation: 
6. `history | grep ".md"`
   - Explanation: 

## Part 3

Verify that `roll` made it to your GitHub repository for this course and is in your `Lab03` folder.  No answers will be written here unless you would like to leave a note to the TAs

## Part 4 - Retrospective Answers

1. Where and when did it go wrong while working on your script tasks?
> Your reflection here
2. Was anything familiar working with a new language compared to one you are used to?
> Your reflection here
3. Did you write good `commit` messages that refer to what tasks were completed at each commit?  What would you improve?
> Your reflection here

## Part 5 Answers

1. PATH =
2. To set condition to `true`, I need to...
3. Command(s):
4. PATH =
   - Difference:
5. Command(s):
6. Commands & modification explanations: 
7. Script permission breakdown
   - User
      - must be:
      - has permissions to:
   - Group
      - must be:
      - has permissions to:
   - Other
      - has permissions to:

## Extra Credit

1. Note here *what* you did to the script for the extra credit.
