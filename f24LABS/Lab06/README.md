## Lab 06

- Name: Rachael Ballentine
- Email: ballentine.7@wright.edu
- Date: 10/11/24

## Part 2 - Retrospective

1. 
```
getopts is a tool to take in and deal with script-defined arguments. it uses a while loop within the bash script to define
the desired options and deal with the input given to those arguments. arguments are passed on the command line when calling
the sscript.
```
2.
```
I had to look up a few more resources to understand how to use the getopts while loop, but my case statement was really
simple so it wasn't too bad. I got stuck on using sed to change the filename for a while, but reading through the resources
helped and I just kept messing with my script until it worked. 
```
3. 
```
I think it would be more useful if it could locate all the files with matching regex within a directory and change them
all, like how sed functions for a script.
```

## Part 3 - namechange Usage Guide
--------

## namechange

Namechange is a script that can be used to easily (in one step) rename any file that follows bad naming convention or was misnamed. Namechange takes in the filename, the undesired phrase, and a phrase to replace the bad one. 

### *running the script*
To obtain the script, use `wget` to pull the [raw file](https://raw.githubusercontent.com/WSU-kduncan/ceg2350f24-rballentine25/refs/heads/main/f24LABS/Lab06/namechange?token=GHSAT0AAAAAACXA7TQRHDKGQXCLE3YTTGCYZYJH67A).  

Running the file:
1. run `bash namechange -h` in the directory containing the namechange script to display the help guide.
2. please note that to use the script to change a file name, the file must be in the same directory as the script.
3. namechange takes the following arguments (in this order): the 'bad' phrase to find, the phrase to replace with, and the filename. The syntax to enter these arguments is:
   ```
   bash namechange -f "PHRASE TO FIND" -r "REPLACEMENT PHRASE" filename
   ```
4. -f and -r flags must be used as shown above. if invalid flags are given or if not all arguments are given, the script will print the help guide.
5. Regex expressions are recognized for the find phrase but NOT for the replace phrase. 

### *examples*
__output is shown with each example.__  

To rename a file named "spaces are bad.txt" to "spaces_are_bad.txt": 
```
$ bash namechange -f " " -r "_" "spaces are bad.txt"
file "spaces are bad.txt" recognized.
Renamed "spaces are bad.txt" to "spaces_are_bad.txt"
```

To rename a file that contains multiple instances of the letter o to two o's separated by a hyphen:
```
$ bash namechange -f "o{3,}" -r "o-o" helloooooooooooohio.txt
file "helloooooooooooohio.txt" recognized.
Renamed "helloooooooooooohio.txt" to "hello-ohio.txt"
```

