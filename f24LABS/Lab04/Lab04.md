## Lab 04

- Name: Rachael Ballentine
- Email: ballentine.7@wright.edu
- Date: 9/27/24

## Part 1 - Task Tracker

Verify that `tt` made it to your GitHub repository for this course and is in your `Lab04` folder.  No answers will be written here unless you would like to leave a note to the TAs

## Part 2 - Sample Runs
### User Guide  
------
## Task Tracker User Guide
### Name 
`tt` is a task tracker capable of adding, completing, clearing, and keeping track of a list of tasks  
tt can also be accessed by using the `tasktracker` hard link
### Usage
`bash tt [ACTION] [TASK DESCRIPTION]`  
`tasktracker [ACTION] [TASK DESCRIPTION]`  
*An action must be given for the script to run.*  

### Available Actions
`add` - add a new task to the task list  
`complete` - mark a task as complete and remove from task list  
`view` - print all tasks on the task list  
`clear` - remove all tasks from task list (delete list)  
`help` - print the file user guide  
        
### Author
Written by Rachael Ballentine.  

------  

### Sample runs

Example of using `add` task
```
# with command line args:
ubuntu@ip-10-0-0-25:~/ceg2350f24-rballentine25/f24LABS/Lab04$ bash tt add "be a silly goose"
task 'be a silly goose' was added to task list.

# without command line args:
ubuntu@ip-10-0-0-25:~/ceg2350f24-rballentine25/f24LABS/Lab04$ bash tt add
Please provide a task description: do silly goose things
task 'do silly goose things' was added to task list.
```

Example of using `complete` task
```
ubuntu@ip-10-0-0-25:~/ceg2350f24-rballentine25/f24LABS/Lab04$ bash tt complete "be a silly goose"
task 'be a silly goose' marked as completed and removed from task list.
```

Example of using `view` tasks
```
ubuntu@ip-10-0-0-25:~/ceg2350f24-rballentine25/f24LABS/Lab04$ bash tt view
All current tasks:
- do silly goose things
```

Example of using `clear` tasks
```
# selecting NO to clear:
ubuntu@ip-10-0-0-25:~/ceg2350f24-rballentine25/f24LABS/Lab04$ bash tt clear
Do you really want to clear your task list? Did you actually do everything... [Y/N]: N
Yeah didn't think so

# selecting YES to clear:
ubuntu@ip-10-0-0-25:~/ceg2350f24-rballentine25/f24LABS/Lab04$ bash tt clear
Do you really want to clear your task list? Did you actually do everything... [Y/N]: Y
All tasks removed.
```

Example of using `help`
```
ubuntu@ip-10-0-0-25:~/ceg2350f24-rballentine25/f24LABS/Lab04$ bash tt help
---------------------- TASK TRACKER USER GUIDE -----------------------
NAME
        tt - is a task tracker capable of adding, completing, clearing, and keeping track of a list of tasks
USAGE
        bash tt [ACTION] [TASK DESCRIPTION]
        An action must be given for the script to run.

AVAILABLE ACTIONS
        add        add a new task to the task list
        complete   mark a task as complete and remove from task list
        view       print all tasks on the task list
        clear      remove all tasks from task list (delete list)
        help       print the file user guide

AUTHOR
        Written by Rachael Ballentine.
```

## Part 3 - PATH for all

- Chosen PATH directory:  `/usr/games`
- Link preference (hard or symbolic): `hard`
   - Justification of preference for this use case:
  `Symbolic links break if the original file is moved or deleted. I would rather use a hard link so I don't have to worry about this, and so that I have a backup of the file on the filesystem. `
- Command to create link:
```
# from the folder that the original tt file was located:
sudo ln tt /usr/games/tasktracker
 ```
- Notes about permissions modified: `no additional modifications were needed, since I'd already run 'chmod a+x' on the original tt file`
- How you tested that you can run `tt` from anywhere on filesystem: `went home using cd~ and ran from there, also ran from random other folders within my cloned repo`
- How you tested that other users can run `tt`: `logged into user named 'sally' from lecture notes? previous lab? idk. sally could run tasktracker from home directory and /usr/bin`

## Extra Credit

N/A
