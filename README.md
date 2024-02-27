
# get_next_line

## Introduction
This project aims to implement a function called `get_next_line` that reads a line from a file descriptor. It is part of the curriculum at the 42 NETWORK's.

## Description
The `get_next_line` function reads a line from a file descriptor, one line at a time, until the end of the file is reached. It allocates memory as necessary and returns the line read from the file descriptor, excluding the newline character. The function is designed to be used in conjunction with other projects that require reading input from files line by line.

## Features
- Reads a line from a file descriptor
- Handles multiple file descriptors simultaneously
- Dynamic memory allocation to accommodate lines of varying lengths
- Compatible with both UNIX and MacOS environments

## Getting Started
To use the `get_next_line` function in your project, simply include the `get_next_line.h` header file and compile your code with the `get_next_line.c` source file. Make sure to also compile with the `get_next_line_utils.c` source file, which contains utility functions needed for the implementation.

### Prerequisites
Before using the `get_next_line` function, make sure you have the following prerequisites installed:

- C compiler (e.g., GCC, Clang)
- Standard C libraries
- [Any other specific libraries or dependencies required]

Additionally, ensure that your development environment is compatible with the functions and system calls used in the implementation.
