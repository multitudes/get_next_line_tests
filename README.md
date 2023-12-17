# get_next_line_tests


A small suite of tests for the "get next line" project at 42 written in C.

## The project

> This project is about programming a function that returns a line read from a file descriptor.

This should be easy enough. Unfortunately, it involves a buffer. The function will actually read line by line, we do not know how long the file will be and/ or it will ever end.  
It is important to visualize this function on acting on a stream of chars. we will read at most BUFFER_SIZE chars and if there is no newline we will read again and keep the previous read chars. Until we get a line and we return what we previously read. We know about our bufffer size but we dont know how long our line will be.  
Also if the new line is in the middle of a buffer we will need to store the extra remaining chars somewhere until we read the another line.  
There is a lot of undiscovered complexity in a seemingky simple project.

### file descriptors
To read the file we use file descriptors (often abbreviated as "fd"), a non-negative integer that uniquely identifies an open file or input/output resource within a process.  
In Unix-like operating systems, everything is treated as a file, including regular files, directories, sockets, pipes, and devices and a file descriptor is a way to represent and interact with these files and resources.  
In Unix-like systems, three standard file descriptors are commonly used:
stdin (standard input): File descriptor 0
stdout (standard output): File descriptor 1
stderr (standard error): File descriptor 2
These are associated with the keyboard and display and are automatically available to all processes.  
When a file is opened, the operating system assigns a file descriptor to that open instance. This file descriptor is then used to read from or write to the file.  
Closing a file involves releasing the associated file descriptor, freeing up system resources.  
File descriptors are represented by non-negative integers. The integer value serves as an index or identifier within the process.  

The tests will use invalid file descriptions like '-1' or a file descriptor from a recently closed file or a file descriptor with a value which is not corresponding to a file opened by the system. In these cases the test checks for a return value of (null).

Also it will check that the memory allocated is properly freed.

The tests should be run with different sizes of BUFFER_SIZE. I did not find a better way yet than rerun the makefile with different values of BUFFER_SIZE in this way:
```
make BUFFER_SIZE=1000
```

## Usage
No installation needed. 
Just download the repo and copy it in your project folder. Compile your library first with its own makefile. Then cd into the test folder cloned from GitHub and run `make` again. The output should be similar to this one below:

```c
➜ make
gcc -Wall -Wextra -Werror -I../ -c ../get_next_line.c -o ../get_next_line.o
gcc -Wall -Wextra -Werror -I../ -c ../get_next_line_utils.c -o ../get_next_line_utils.o
gcc -Wall -Wextra -Werror -I../ -c get_next_line_tests.c -o get_next_line_tests.o
gcc -Wall -Wextra -Werror -I../ ../get_next_line.o ../get_next_line_utils.o get_next_line_tests.o -o get_next_line_tests
sh ./runtests.sh
Running unit tests:
----
RUNNING: ./get_next_line_tests
======= TESTing invalid fd ==========
** fd = 1000 - buffer size 10
+++++++++++++++++++++++
next line is |(null)|
+++++++++++++++++++++++
** fd = -1 - buffer size 10
+++++++++++++++++++++++
next line is |(null)|
+++++++++++++++++++++++
ALL TESTS PASSED
Tests run: 1
get_next_line_tests PASS

```

Other commands are available like `make clean` and even `make valgrind` (on a Linux system). 

The scripts will create a test log file with the debugging output of the tests. 

To work you need to be in a subdirectory of your libft project.
Also it assumes that the name of your library is printflibft.a. (this can be changed in the Makefile manually)

## Acknoledgements
For my project I adapted code from the debugging and test tools found in Zed Shaw "learn C the hard way" book and tutorial! Thank you Zed! I especially like the way to send the debugging messages to a log file. I also ran [francinette](https://github.com/xicodomingues/francinette) and [gnlTester](https://github.com/Tripouille/gnlTester) and looked up what they are testing for inspiration. Another reason to do my testing is to learn more about testing in general. My tests are written in C and should be easy to debug. Sometimes especially on my mac some tests done by the other tester would not give correct answers.

## Bugs and suggestions
They are always welcome. Please file under issues. :)

