# Final Review for CEG 2350

# MIDTERM TOPICS
lab topics:
* Lab 1: not relevant (intro)
* Lab 2: steps to create ssh keypair and add to gitHub. git commands. chmod. create and switch between users
* Lab 3: ssh config file. piping/appending/overwriting (|, >, >>, <<). PATH. command line args
* Lab 4: task tracker bash script using command line args/loops/functions.
* Lab 5: sed, awk, and regex
* Lab 6: getopts
 
## Intro topics
1. How did the modern computer come to be?
2. Shells
   - Windows: powershell, cmd
   - Linux / Mac: bash, sh, zsh
3. Terminals:
   - MobaXTerm
   - WSL2
   - Any program that lets you interact with a shell
4. SSH
   - the command ssh
   - private key files (where go and what permissions)
   - public keys (go where)
5. Updates (Linux vs. Windows)
   - Linux - apt / package manager update request
   - Windows - click button

## Files, directories, and OS structure

1. OS structure in Linux (and Mac) vs Windows
2. Files vs directories
   - Commands: ls, cp, mkdir, rmdir, vim, mv, rm, cd, cat, touch, head/tail, less/more
3. Importance of names and extensions (file)
4. Ownership & sharing
   - rwx permissions in Linux (and Windows counterpart)
   - user vs. group vs. other
   - chmod, chown, chgrp, adduser, deluser
   - User types and groups
   - sudo & the root user
5. PATH vs path and environment variables

## Scripting

1. Aliases & customizations (.bashrc, .profile)
2. Commands: ~~diff~~, find, ~~file~~, wc, sort, uniq, whereis, which
3. IO redirection (<, >, |, streams (standard output and error) ~~tee~~)
4. executing scripts (source, ./, PATH)
5. Scripting languages: bash
   - variables
   - conditionals (`test`)
   - arguments
   - if
   - fori
   - while
   - getopts
   - case
6. Regular expressions
7. grep, sed, and awk

# FINAL TOPICS
lab topics:
* Lab 7: system hardware info, setting up VM
* Lab 8: DID NOT DO. filesystems and partition tables. creating a new partion, creating a filesystem, and mounting it. creating a virtual filesystem
* Lab 9: process control: using kill on process, moving background to foreground, tmux
* Lab 10: compilers, method for compiling cpp code in terminal, comments and userguide for c++ code, git branch, makefiles
* Lab 11: tar for zip files, sftp to download tar.gz files, extracting tar file and using apache2 for website, ssh keys (didn't do)
* Lab 12: linux network commands, network info for windows/aws, subnet translation, security groups
  
## DONE Computer Hardware, Boot Process, and Data on Disks:

1. Computer Hardware:
   - Von Neumann machine:   
	Control unit; instruction fetch, decode, and execution
	first version of the modern computer. allowed for stored 
	programs, which was the beginning of modern programming 
	languages. successor of the ENIAC computer.     
   - CPU:   
	central processing unit. operates in cycles measured by 
	clock speed. includes ALU, CU, registers. does all 
	instruction execution: fetch, decode, execute.
	Each CPU can have different number of cores which allows
	for multithreading. Cache size is also important. 
	ARM processors based on reduced instruction set computer
	architecture. used in things like smartphones, RPi
   - RAM:   
	random access volatile memory. stores data on short-term
	basis. 
   - Motherboard:  
	distributes electricity and facilitates comm etween CPU, RAM, etc.
	NORTHBRIDGE is data connections to CPU,RAM, PCle. 
	OUTHBRIDGE is data connection to BIOS, USB, SATA, and PCI bus 
	(where SATA = serial advanced technology attachment, and PCI = 
	peripheral component interconnect, connects internals like
        CPU, GPU, network cards)
   - Disks(HDD, SSD, NVME):  
	    * HDD is Hard Disk Drive: stored magnetically on disks. disks
	experience fragmentation over time. has a disk that is spun and 
	read with an actuator arm
	    * SSD is Solid State Drive. stores date on semi-conductor cells
	and uses NAND based flash memory (electrical charges). also has 
	built-in controller to manage storage/retreival, including 
	garbage collection. no moving parts, so fragmentation is not 
	as big an issue. also uses wear-leveling algorithms which by
	default means data is scattered throughout the drive (designed
	for fragmentation-like usage)
	    * NVME is non-volatime memory express. it is a protocol used on 
	SSDs and uses PCle (Peripheral component interconnect express)
	interface to improve read/write speeds
   - GPU:  
	discrete / dedicated vs integrated): graphics processing unit. 
	specialied processor to accelerate rendering of images, etc.
	    * integrated: built directly into CPU, shares RAM with CPU. more 
	basic, found in laptops and budget systems.
	    * discrete/dedicated: separate graphics card installed in a slot 
	on the motherboard. has its own dedicated memory and processing 
	resources

2. Booting of OS
   - Power on self-test (POST):   
	triggered by BIOS/UEFI. tests and initializes CPI, RAM, etc etc to
	make sure all important components are connected and working. used
	to beep to tell you whether it was successful. 
   - BIOS vs UEFI  
	    * BIOS = Basic Input Output System. stored on a read-only memory
	(ROM) chip, which meant originally it could not be updated.
	16bit mode, MBR for bootloader, max 2.2TB harddrive support. only
	keystrokes on boot page, no mouse
	    * UEFI = Unified Extensible Firmware Interface. 
	32 or 64bit mode, GPT, 4.9b TB harddrive, 
	allows network booting/remote diagnostics, and secure boot. allows
	GUI for configuration (including mouse support)
   - Boot loaders: NTLDR, GRUB  
	Bootloader task include loading filesystem drivers, read config 
	file for OS, run supporting modules,display OS menu(if applicable)
	and load the selected OS 
	    * NTLDR  
	default bootloader for Windows NT, 2000, XP. list of OSs stored
	in BOOT.INI partition. needs helper program to detect hardware
	    * GRUB  
	popular bootloader for linux. boot settings stored in grub.cfg
	file or menu.lst. modular bootloader (can load additional mods 
	from disk)
	    * BOOTMGR   
	new windows bootloader, used on windows 11. OS list is read from 
	BCD file in BOOT directory. self-contained (no helper programs)
   - kernel vs OS  
	    * OS:   system software which provides gui interface for users to           interact with the system, defines file organization, manages              memory and device drivers, and translates user input into                 commands the hardware can understand. OS is like a management             team, which takes in input from the client and passes it off to           the correct department  
	    * kernel is the intermediary between the system hardware and soft	ware. it helps to scale/standardize the system hardware to match 
	what the OS expects. it also manages system resources by doing 
	stuff like memory management, CPU task scheduling, device 
	management, recieves service requests from processes. gets loaded 
	into RAM by the bootloader and just stays there. is the core/brain
	of the OS: it recieves the translated user instructions from the
	OS, then gives orders to the hardware to carry out tasks
	    * types of kernel: monolithic kernel and microkernel	  
   - OTHER TERMS:
	    * cold booting: first time start/power on after shutdown
	    * hot boot: reboot or wake from sleep

3. Virtual memory
   - What is it and how does it work  
	virtual memory uses a portion of the disk drive to emulate RAM in
	order to increase the capacity of main memory. this allows the 
	system to handle processes that require more memory than what
	is actually available in RAM. memory that is not being used is 
	"swapped" into external storage and is assigned a memory address 
	even tho its not stored in RAM. there are two types of virtual 
	memory: paging and segmenting
	    * paging divides the memory into fixed size blocks that are 
	passed between RAM and external storage. MMU uses a page table to
	keep track of which virtual (external storage) pages map to wich
	physical pages in RAM. when RAM is full, currently unused pages
	are swapped out with one that is being called by the program

4. Disks
   - MBR vs GPT  
	both primary partition tables which hold the system bootloader. 
	decide where each partitions start/end and which are bootable
	    * MBR: Master Boot Record
	4 primary partitions, 2TB disk size cap. holds partition table
	and bootloader in same partition. used by BIOS
	    * GPT: GUID Partition Table
	128 partitions; each gets a unique identifier (GUID). bootloader 
	is sored in EFI partition (where boot files are stored for uefi
	systems). includes a MBR in first partition for backwards
	compatability
   - fragmentation:   
	happens in older disks when there is not enough memory on a 
	storage device to store a file in one continuous memory block. 
	instead, the file is broken up across several non-continous blocks
	which means it takes the system much longer to access the file 
	(has to find all the scattered parts first). this is due to how 
	memory is allocated/deallocated over time as smaller files are 
	created and deleted file fragmentation is resolved by zoning 
	memory or preallocating memory

5. BOOT PROCESS
   - CPU powers on and provides instruction to run BIOS/UEFI
   - BIOS/UEFI runs POST and if successful, loads the bootloader
   - bootloader loads the filesystem drivers, reads config file, and loads     the kernel into RAM
   - kernel takes control and starts processes to load and run OS, including starting init (systemd) 

## DONE Git (version control)

1. Git remote (servers) vs. clients (local)
2. Basic commands:
   - clone: clone a repo into local server
   - add: stage a file for commit
   - commit: save staged files to the local repo
   - push: uploads changes saved to local repo to remote repo
   - pull: downloads changes from remote repo and automatically merges them into your local repo
     - fetch: downloads changes from a remote repo and stores them in your local repo, but DOES NOT MERGE THEM
     - merge: combines two branches into one branch. to use, have to switch to main branch using checkout then merge
   - branch: used by itself, will list all branches in the repo. with a name, will create a new branch. to rename, use <newname> -m <oldname>
   - checkout: switch to a different branch


## Virtual Machines

1. Set of resources virtually "defined"
2. Resource allocation managed by hypervisor
    * hypervisor: separates physical resources from virtual 
	environments. hypervisors can sit directly on top of OS (type 2, 
	client/hosted) or installed directly onto hardware (type 1, bare
	metal). they take your system's physical resources and divide them
	amongst virtual environments.
4. Can install an operating system to a disk using an iso (machine image)
5. What can you do in a virtual machine?

## DONE Devices, Filesystems, Data Storage

1. Devices  
   Devices refers to a physical or virtual hardware component that 
interacts with the computer system. devices are classified based on how 
they interact with the OS and applications. can be divided into hardware 
and virtual; input, output, storage, or communication. two main types
are block and virtual, where the difference is how they transfer data.
managed by device drivers.
    * block - SSD, HDD, NVME, CD, USB  
	block devices store and transfer data in fixed size blocks and 
	allow random access to data.
    * character - /dev/null, /dev/zero, /dev/random  
	character devices transfer data as a continuous stream of bytes
	without fixed size. printers, mice, keyboards, all char devices
3. Storing data on a disk
   - partitions:  
	partition is a division of a storage device into independant sections. each section can act as its own disk with its own filesystem. need at least one partition to separate data from kernel. basically just chunks of block devices
4. Filesystems
   - a filesystem establishes the structure and logic rules used to manage groups of data and their names. 
   - journaling   
	 journaling filesystems keep a log of actions to be performed just before actually performing them. ext4 and NTFS both do this. the data log is stored in a file called a journal, which in linux can be accessed with "journalctl" command
   - Windows: vfat, ntfs
   - Linux: ext4
   - Apple: HFS+
   - Special: swap
5. Inodes  
an inode is a datastructure that stores METADATA about a file/directory, including file type, size, ownership, permissions, timestamps, and pointers to actual data blocks. 
   - hard links:  
	direct reference to inode data. multiple hard links to same inode will point to the same data. changes made via one hard link re immediately reflected in other links (like a shallow copy)
   - soft links:  
	link points to another inode by storing pathname, not to the actual data? removing the symbo link has no effect, but deleting the data will cause a broken link. can span across filesystems.	
   - cp vs mv:  
	    * cp creates new inode for copied file
	    * mv keeps the same inode on same filesystem
6. File locks: idk what this is but im not looking it up
7. Commands:
    * df: disk free, displays amount of disk space available on mounted filesystems. -h for human readable, -T for type of filesystem
    * du: estimate disk space used by files/directories. -h for human readable, -s for summary of size
    * mkfs: make file system. ERASES ALL DATA ON PARTITION
    * gdisk: tool for managing GUID partitions
    * fdisk: tool for managing MBR partitions
    * parted: more advanced tool for managing partition tables
    * stat: displays metadata about a file or directory
    * mount and unmount: mount and unmount filesystems. have to specifiy path not just name
9. OTHER:
   - MiB = mebibyte, unit of digital info storage. = 2^20 bytes  
differs from regular decimal system as it is base 2 not 10
   - MOUNTING filesystems:
	    * pick a file system (should match OS)
	    * choose mount point (choose partition to be known as root OS). /mnt/ is a common safe playground. m
	    * create a block device for the partition/filesystem to be mounted 
	    * mount using:  
	"mount -t <type> <device> <mountpoint>"    
	    * setup username and password
	
## Processes

1. init process / kernel level vs user level processes
2. Processes
   - parent vs child
   - System calls & kill signals
   - Fork & exec
   - wait & exit
   - zombie and orphan process states
3. Service units & service control
   - systemctl & journalctl
   - format of a service file
   - creating new service units / managing existing service units
      - stop, start, restart, enable, disable
4. Process scheduling & priorities
5. ~~Thread vs Fork~~
6. ~~CPU & kernel memory management~~
   - page faults (minor & major)
   - virtual memory
7. ~~Single CPU multi-tasking & context switching~~
8. ~~Multiple CPUs and SMP (Symmetric multiprocessing)~~
8. Commands: kill, ps, top, nice, bg, fg, jobs, screen, tmux

## Command line programming

1. Interpreted language
   - python
   - bash
2. Compiled languages
   - c / c++
     - compilation steps
       - pre-processor
       - compiler
       - assembler
       - linker
     - `gcc`/ `g++` and compilation options
     - Linux ELF (Executable & Linkable Format)
     - Windows EXE
   - java
     - compile in java compiler
     - run in JVM
3. Makefiles
   - make
   - targets
   - dependencies
   - actions
4. ~~Memory handling in programming~~
   - size of memory - Bits (1), bytes (8 bits), word (16, 32, or 64 bits)
   - stack vs. heap
6. Libraries & dynamic linking (loads and links the shared libraries needed by an executable when it is executed)
7. Overview of command line debugging
8. ~~Install from source w/ make or installation scripts~~
9. Compression (including `tar` & `gzip`)
10. Commands: make, which, whereis, python, gcc, java, javac, ~~ldd~~, ~~strace~~

## Networking

1. OSI model and TCP / IP model of networking
   - application
     - light here, scope will be what was praciticed in lab.  Additional reading recommended   
     - HTTP
     - HTTPS
       - Certificate Authorities & browser trust
     - SSH
       - private / public key pairs, ~~`config` & `authorized_keys` files~~
     - SFTP
   - transport
     - ports
     - UDP
     - TCP
   - network / internet
     - IP addresses (v4 and v6)
     - DNS to resolve IP addresses
     - subnets
     - routes
     - NAT
   - data / link
     - MAC
     - NIC
   - physical
2. Ports vs sockets
   - Application opens a socket which is connected to a port
3. Pieces of a network
   - hosts (devices)
   - routers
   - switches
   - ISPs
4. Firewalls
   - inbound / INPUT / ingress
   - outbound / OUTPUT / egress
   - ~~whitelist vs blacklist & default allow vs deny~~
   - common sense rules & trusted networks
5. Commands: ip, route, arp, iptables, ping, curl, wget
   - Useful, not on exam: tcpdump, nmap
