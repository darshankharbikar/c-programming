# Tic-Tac-Toe in C

A simple **two-player Tic-Tac-Toe game written in C** for the terminal/command line.

The project demonstrates fundamental C programming concepts such as arrays, functions, loops, conditional statements, input validation, and basic game logic.

## Features

* 3 × 3 Tic-Tac-Toe board
* Two-player gameplay
* Player `X` and Player `O`
* Position selection using numbers `1-9`
* Input validation
* Detection of:

  * Row wins
  * Column wins
  * Diagonal wins
  * Draws
* Prevents players from selecting an occupied position
* Replay option after the game ends
* Runs entirely in the terminal

## Board Layout

At the beginning of the game, the board is displayed as:

```text
     |     |     
  1  |  2  |  3
_____|_____|_____
     |     |     
  4  |  5  |  6
_____|_____|_____
     |     |     
  7  |  8  |  9
     |     |     
```

Players enter the number corresponding to the position where they want to place their mark.

For example:

```text
Player X's turn
Enter position (1-9): 5
```

The selected position is then replaced with `X` or `O`.

## Requirements

You need:

* A C compiler
* Terminal/command prompt

Recommended:

* GCC
* Linux, macOS, or Windows

Check whether GCC is installed:

```bash
gcc --version
```

## Project Structure

```text
tic-tac-toe/
│
├── tic_tac_toe.c
└── README.md
```

## Compilation

Using GCC:

```bash
gcc tic_tac_toe.c -o tic-tac-toe
```

### Recommended compiler flags

```text
-Wall
-Wextra
-std=c11
```

These flags enable useful compiler warnings and ensure the program is compiled using the C11 standard.

## Running the Program

Linux/macOS:

```bash
./tic-tac-toe
```

Windows:

```cmd
tic-tac-toe.exe
```

## Example Gameplay

```text
===== TIC TAC TOE =====

     |     |     
  1  |  2  |  3
_____|_____|_____
     |     |     
  4  |  5  |  6
_____|_____|_____
     |     |     
  7  |  8  |  9
     |     |     

Player X's turn
Enter position (1-9): 1

Player O's turn
Enter position (1-9): 5

Player X's turn
Enter position (1-9): 2

Player O's turn
Enter position (1-9): 8

Player X's turn
Enter position (1-9): 3
```

The final board:

```text
     |     |     
  X  |  X  |  X
_____|_____|_____
     |     |     
  4  |  O  |  6
_____|_____|_____
     |     |     
  7  |  O  |  9
     |     |     

Player X wins!
```

## Program Architecture

The program is divided into several functions:

```text
main()
  │
  ├── initializeBoard()
  │
  ├── displayBoard()
  │
  ├── makeMove()
  │
  ├── checkWin()
  │
  ├── checkDraw()
  │
  └── clearInputBuffer()
```

### `initializeBoard()`

Initializes the board with positions `1` through `9`.

```c
void initializeBoard(char board[3][3]);
```

### `displayBoard()`

Displays the current state of the game board.

```c
void displayBoard(char board[3][3]);
```

### `makeMove()`

Reads the player's position, validates it, and places the player's mark.

```c
int makeMove(char board[3][3], char player);
```

### `checkWin()`

Checks whether the specified player has completed:

* Any row
* Any column
* Main diagonal
* Opposite diagonal

```c
int checkWin(char board[3][3], char player);
```

### `checkDraw()`

Checks whether all nine positions are occupied without a winner.

```c
int checkDraw(char board[3][3]);
```

### `clearInputBuffer()`

Removes unwanted characters remaining in the standard input buffer.

```c
void clearInputBuffer(void);
```

## Win Detection

There are **8 possible winning combinations**:

```text
Rows:

1 2 3
4 5 6
7 8 9

Columns:

1 4 7
2 5 8
3 6 9

Diagonals:

1 5 9
3 5 7
```

For example:

```text
X | X | X
---------
O | O | 6
---------
7 | 8 | 9
```

The first row contains three `X` marks, so Player X wins.

## Important C Concepts

### 1. Two-Dimensional Array

The board is represented using:

```c
char board[3][3];
```

This provides a simple representation of the 3 × 3 game board.

### 2. Array Index Calculation

The user's position from `1-9` is converted into a row and column:

```c
row = (position - 1) / 3;
col = (position - 1) % 3;
```

For example:

```text
Position 5

row = (5 - 1) / 3 = 1
col = (5 - 1) % 3 = 1
```

Therefore position `5` corresponds to:

```text
board[1][1]
```

### 3. Function-Based Design

Game operations are separated into individual functions rather than putting all logic inside `main()`.

This makes the program easier to:

* Read
* Debug
* Test
* Maintain
* Extend

## Input Validation

The program checks for:

* Non-numeric input
* Position outside `1-9`
* Already occupied positions

Example:

```text
Player X's turn
Enter position (1-9): 12

Invalid position. Choose 1-9.
```

If a player selects an occupied position:

```text
Position already occupied. Choose another.
```

## Learning Objectives

After implementing this project, you should understand:

* C arrays
* Two-dimensional arrays
* Functions
* Function parameters
* Return values
* Loops
* Conditional statements
* Character handling
* Standard input/output
* Input validation
* Basic algorithm design
* Modular C programming

## Possible Improvements

The current implementation is intentionally simple. It can be extended significantly.

### Level 1 — Code Improvements

* Replace magic numbers with constants
* Improve input handling
* Separate declarations into a header file
* Separate implementation into multiple `.c` files

Example:

```text
tic-tac-toe/
├── main.c
├── game.c
├── game.h
└── README.md
```

### Level 2 — Gameplay Improvements

Add:

* Player names
* Score tracking
* Multiple rounds
* Starting-player selection
* Better terminal UI
* Colored output

Example:

```text
Player X: 3 wins
Player O: 2 wins
Draws:    1
```

### Level 3 — Computer Player

Implement:

```text
Human vs Computer
```

The computer can initially select random available positions.

### Level 4 — Unbeatable AI

Implement the **Minimax algorithm**.

Architecture:

```text
             Tic-Tac-Toe
                  │
        ┌─────────┴─────────┐
        │                   │
      Human              Computer
        │                   │
      Input              Minimax
                            │
                     Evaluate moves
                            │
                     Select best move
```

With Minimax, the computer can play optimally and cannot be defeated.

## Future Project Structure

A more advanced version could look like:

```text
tic-tac-toe/
│
├── include/
│   └── game.h
│
├── src/
│   ├── main.c
│   ├── game.c
│   └── ai.c
│
├── tests/
│   └── test_game.c
│
├── Makefile
└── README.md
```

This structure is closer to how larger C projects are organized.

## License

This project is provided for educational and learning purposes.

