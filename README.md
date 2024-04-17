#### Word Search Solver

## Overview

This program is designed to solve word search puzzles. It reads a word search grid and a list of words to find within that grid from text files, performs the search, and outputs the coordinates of the end of each word found.

## Features

- Reads word search grid and word list from text files.
- Searches for each word in the grid horizontally, vertically, and diagonally both backwards and forwards.
- Outputs the coordinates of the end of each word found.

## Usage

### Compilation

Before running the program, compile it using a C++ compiler. For example:

```bash
g++ main.cpp -o word_search
```

or simply type:

```bash
make all
```

### Execution

To run the program, execute the compiled binary and provide the required command-line arguments:

```bash
./word_search <grid_file> <word_list_file> [test_case]
```

- `<grid_file>`: Path to the text file containing the word search grid.
- `<word_list_file>`: Path to the text file containing the list of words to search for.
- `[test_case]` (optional): Specify a test case to run. Available test cases are `testAbc`, `testAnimal`, and `testAfrica`. If specified, the program will compare the coordinates of found words against the expected coordinates for the chosen test case.

### Word List Format

The word list file should contain one word per line. Words should be listed without spaces between characters.

Example:

```
cat
dog
elephant
```

## Input Files

### Grid File

The grid file should contain the word search grid in the following format:

```
ABCDEF
GHIJKL
MNOPQR
STUVWX
YZABCD
```

Each character represents a cell in the grid.

### Word List File

The word list file should contain a list of words to search for in the grid, with one word per line.

## Output

The program will output the coordinates of the end of each word found in the grid in the format `row,column`.

## Testing

You can run predefined test cases by specifying the test case name as the third command-line argument.

## Dependencies

- C++ standard library
