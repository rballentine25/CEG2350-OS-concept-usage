## Lab 10

- Name: Rachael Ballentine
- Email: ballentine.7@wright.edu
- Date: 11/15/24

## Part 1 - Compilers

Your Operating System: `Windows 11 Home (64bit)`

Your AWS instance's Operation System: `Ubuntu 22.04.1 LTS`

- Java
   - How to install on your OS:
```
check if java is installed: run "java -version" in powershell
download installer from java.com for windows and run it. i could not
find an easy/straightforward way to download from powershell (bc powershell
is dumb)
```
   - How to install on OS on AWS: 
```
following instructions from ubuntu.com and geeksforgeeks.com:

sudo apt get-update
sudo apt install default-jdk
sudo apt install default-jre
java -version
```

- C++
   - How to install on your OS:
```
nothing is easy with windows/powershell... easiest to download VScode
and install MicrosoftC/C++ Extension and C/C++ Runner to compile
```
   - How to install on OS on AWS:
```
installing g++ compiler: following instructions from linuxconfig.org

sudo apt update
sudo apt install build-essential
g++ --version
``` 

- Python
   - How to install on your OS:
```
open Microsoft Store and install python from there
```
   - How to install on OS on AWS:
```
from instructions on phoenixnap.com:

sudo apt update
sudo apt install python3
python3 --version
``` 

Web based IDEs: 
` I said all Jdoodle because the layout is nice and its free forever`

- Java 
`Jdoodle: https://www.jdoodle.com/online-java-compiler`
- C++
`Jdoodle: https://www.jdoodle.com/online-compiler-c++`
- Python
`Jdoodle: https://www.jdoodle.com/python3-programming-online`

## Part 2 - Compiling

1. Method & command to get a copy of the source code files:
`open raw file for each file from GitHub and run "wget rawwebaddress" for each in the terminal`
2. Command(s) to install the C/C++ compiler on Ubuntu: 
```
sudo apt update
sudo apt install build-essential
```
3. Command(s) to confirm the installation of the C/C++ compiler on Ubuntu: 
```
g++ --version

if you get an error, its not installed
```
4. Command(s) to compile the source code into an executable program:
```
have to compile both main and utility.cpp for them to work

g++ main.cpp utility.cpp
```
5. Command(s) to execute the program:
```
compiling creates file a.out in working folder. to run:

./a.out
```

## Part 3 - Document

### Program User Guide

#### Program Description
```
TODO is a task tracking program. Users can add tasks, mark them as complete, 
remove tasks, and see the full list of tasks by using numbers 1-5 and giving
input for task names.
```
#### How to Build and Run Program
```
To compile the program, users must first install C++ compiler by running the following commands:
	sudo apt update
	sudo apt install build-essential
	g++ --version

After the compiler has been downloaded, the program can be compiled by running the following:
	g++ main.cpp utility.cpp

This will create a file named a.out in the working folder.
To run the program, run the following command:
	./a.out
```
#### How to Use Program
```
To use the program, read the output menu and choose the desired action. Enter the number
associated with that action in the command line and enter the task name when prompted.
```
### `git` `branch` Guide

Create a branch:

Change to branch:

Add branch to remote if created locally (GitHub):

Steps to `merge` changes to another branch (`main`):

Steps to resolve a `merge` conflict: 

## Part 4 - `makey makey`

Using `Makefile` to build executable:

Using `Makefile` to run program:

Using `Makefile` to remove compilation files, such as the executable: 

## Extra Credit - Ignore That

Remove this statement and the exclamation point from the line below so TAs can click to check for a working `.gitignore` file.  Test that the link works - if it doesn't, fix the pathing.

![`.gitignore` file in root of repository](../.gitignore)
