# SPLab3: C Pointers



# Building and Running the Program

This is a C Pointers Program implemented in C. This guide will walk you through the process of building and running the program.

## Prerequisites

Before you can build and run the program, you need to have a C compiler installed on your system. The GNU Compiler Collection (GCC) is a popular choice and is available on most systems.

## Building the Program

First, ensure all source code files are located in the same directory. 
Then, open your terminal or command prompt, navigate to this directory, and execute the following command to compile the program:

```bash
gcc -o main basicstats
```

Feel free to replace main with any name you prefer for the executable.


### Compilation
After compilation, run the program by providing a data file as a command-line argument:

```bash
./main input.txt
```

Feel free to replace "input.txt" with any file you prefer for the input.

### Program
It will compute the mean (average), mode, geometric mean, harmonic mean, median (the middle value), and the standard deviation of the set of values and print them out.
