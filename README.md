# get_next_line_tests


A small suite of tests for the "get next line" project at 42 written in C.

## The project


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
For my project I adapted code from the debugging and test tools found in Zed Shaw "learn C the hard way" book and tutorial! Thank you Zed! I especially like the way to send the debugging messages to a log file. 

## Bugs and suggestions
They are always welcome. Please file under issues. :)

