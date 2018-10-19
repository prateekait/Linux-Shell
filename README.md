# Linux-Shell
# C/C++ implementation of a custom linux shell

# INTRODUCTION :
The command shell is the interface between the user and the OS in the linux.As computer engineers, it is imperative for us to understand how the shell works.Here you will find insight into the internals of Linux shell commands and how the shell executes them in turn making you further inquisitive of the internal of an OS.

# DESCRIPTION :
 Its a C program which will act like a mini command shell.It will have a prompt and will accept the following command and execute programs themselves and accept command line arguments.The shell will load these commands through the combination of fork+exec functions and execute them :-

(a) mypwd   : Print the present working directory to STDOUT.

(b) mymkdir : Creates a directory
              Sample Inputs :
                Single directory     : mymkdir dir1
                Multiple directories : mymkdir dir1 dir2 dir2/dir3
                Absolute Path        : mymkdir /rootpath/subdir/subdir2
              
(c) mycd    : Change current working directory (CWD) to specified directory.

(d) myrm    : Remove directory or a file.If directory is to be removed, the files inside the directory must be deleted prior               to deletion of the directory.
              Sample Inputs :
                Remove file(s)                      : myrm file1 file2 file3
                Remove empty directory              : myrm -d dir2
                Remove a directory and its contents : myrm-r dir2
                
(e) mymv : Move a file/Directory from one location to another. Delete the orginal directory after moving the contents.
           Sample Inputs:
            mymv sourceDirectory targetDirectory
            mymv sourceFile targetFile
(f) myps : List all processes for the current user without regards to the present terminal.
           Options:
            -a List all processes running on the system.
(g) myls : List the directory contents. Output should be same as ls -l on a linux shell.

(h) mytail : Print the last 'n' lines of the input file
             Options:
              <N> Number of lines from end to print
              <filename> Filename of input file.
             Sample Input:
                mytail -10 file1.txt
              
The above given programs need to be programmed with standard C functions for UNIX. All the commands should be able to handle absolute and relative path as well as combination about wherever applicable as in a real shell interface. The shell will work as follows: 
1. Show prompt and wait for user input. 
2. On receiving the input the shell should fork a child process
   a.) Sample Input:  [/home/user]myshell mymkdir /home/user/newDir 
3. In the child process call exec family functions to load a program corresponding to the input command.
      
