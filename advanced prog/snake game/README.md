# Snake Game in C

A terminal-based **Snake Game implemented in C** using the **ncurses** library.

The project demonstrates fundamental C programming and data-structure concepts including structures, enumerations, arrays, functions, random-number generation, keyboard input, game loops, collision detection, and state management.

---

## Table of Contents

* [Overview](#overview)
* [Features](#features)
* [Demo](#demo)
* [Requirements](#requirements)
* [Project Structure](#project-structure)
* [Installation](#installation)
* [Compilation](#compilation)
* [Running the Game](#running-the-game)
* [Game Controls](#game-controls)
* [How the Game Works](#how-the-game-works)
* [Program Architecture](#program-architecture)
* [Data Structures](#data-structures)
* [Game State](#game-state)
* [Snake Movement](#snake-movement)
* [Food Generation](#food-generation)
* [Collision Detection](#collision-detection)
* [Game Loop](#game-loop)
* [ncurses](#ncurses)
* [Compilation Error and Solution](#compilation-error-and-solution)
* [Building with Warnings](#building-with-warnings)
* [Debugging](#debugging)
* [Complexity Analysis](#complexity-analysis)
* [Possible Improvements](#possible-improvements)
* [Learning Objectives](#learning-objectives)
* [Concepts Practiced](#concepts-practiced)
* [Future Extensions](#future-extensions)
* [License](#license)

---

# Overview

This project implements the classic **Snake Game** in C and runs directly inside a Linux terminal.

The player controls a snake that moves continuously around a rectangular game board. The objective is to eat food, increase the snake's length, and obtain the highest possible score without hitting the walls or the snake's own body.

The game uses the `ncurses` library to provide:

* Real-time keyboard input
* Terminal screen manipulation
* Cursor control
* Screen refreshing
* Non-blocking input

---

# Features

* Terminal-based graphical interface
* Snake movement
* Food generation at random positions
* Snake growth
* Score tracking
* Wall collision detection
* Self-collision detection
* Arrow-key support
* WASD support
* Non-blocking keyboard input
* Configurable game speed
* Game-over screen
* Maximum snake-size protection

---

# Demo

The game board looks approximately like this:

```text
##########################################
#                                        #
#                                        #
#                  *                     #
#                                        #
#                   oooO                 #
#                                        #
#                                        #
#                                        #
##########################################

Score: 20 | W/A/S/D or Arrow Keys | Q: Quit
```

Where:

```text
O  = Snake head
o  = Snake body
*  = Food
#  = Game boundary
```

---

# Requirements

## Operating System

The project is primarily designed for Linux.

Tested environment:

```text
Ubuntu Linux
GCC
ncurses
```

It should also work on other Unix-like systems that provide `ncurses`.

---

## Required Software

### GCC

Check whether GCC is installed:

```bash
gcc --version
```

If GCC is not installed:

```bash
sudo apt update
sudo apt install gcc
```

### ncurses

The game uses the `ncurses` library.

Install the development package:

```bash
sudo apt update
sudo apt install libncurses-dev
```

Verify the library:

```bash
ldconfig -p | grep ncurses
```

---

# Project Structure

A minimal repository can contain:

```text
snake-game/
│
├── snake.c
├── README.md
└── .gitignore
```

A more advanced project structure could be:

```text
snake-game/
│
├── src/
│   └── snake.c
│
├── include/
│   └── snake.h
│
├── README.md
├── Makefile
└── .gitignore
```

For the current project, all implementation is contained in:

```text
snake.c
```

---

# Installation

Clone the repository:

```bash
git clone <repository-url>
```

Enter the project directory:

```bash
cd snake-game
```

Install the ncurses development package:

```bash
sudo apt update
sudo apt install libncurses-dev
```

---

# Compilation

Compile the program using:

```bash
gcc snake.c -o snake -lncurses
```

The important part is:

```text
-lncurses
```

This tells the linker to link the program against the ncurses library.

---

## Recommended Compilation

For development, use compiler warnings:

```bash
gcc -Wall -Wextra -O2 snake.c -o snake -lncurses
```

Explanation:

| Option      | Purpose                          |
| ----------- | -------------------------------- |
| `-Wall`     | Enables common compiler warnings |
| `-Wextra`   | Enables additional warnings      |
| `-O2`       | Enables compiler optimization    |
| `-o snake`  | Names the output executable      |
| `-lncurses` | Links against ncurses            |

---

# Running the Game

Run:

```bash
./snake
```

The terminal will switch into the ncurses display mode.

The snake will automatically start moving.

---

# Game Controls

| Key       | Action     |
| --------- | ---------- |
| `W` / `w` | Move Up    |
| `S` / `s` | Move Down  |
| `A` / `a` | Move Left  |
| `D` / `d` | Move Right |
| `↑`       | Move Up    |
| `↓`       | Move Down  |
| `←`       | Move Left  |
| `→`       | Move Right |
| `Q` / `q` | Quit       |

The snake cannot immediately reverse direction.

For example:

```text
RIGHT -> LEFT
```

is prevented because this would cause the snake to collide with itself immediately.

---

# How the Game Works

The game can be divided into the following stages:

```text
             +----------------+
             | Initialize     |
             | ncurses        |
             +-------+--------+
                     |
                     v
             +----------------+
             | Initialize     |
             | Game State     |
             +-------+--------+
                     |
                     v
             +----------------+
             | Draw Game      |
             +-------+--------+
                     |
                     v
             +----------------+
             | Read Keyboard  |
             +-------+--------+
                     |
                     v
             +----------------+
             | Move Snake     |
             +-------+--------+
                     |
                     v
             +----------------+
             | Collision?     |
             +-------+--------+
                Yes / \ No
                    /   \
                   v     v
            +---------+  +----------------+
            | Game    |  | Continue Loop  |
            | Over    |  +----------------+
            +---------+
```

The game continuously repeats:

```text
Input
  ↓
Update
  ↓
Collision detection
  ↓
Rendering
  ↓
Delay
  ↓
Input
```

---

# Program Architecture

The program is divided into several logical components.

## 1. Game Configuration

The board dimensions are defined using macros:

```c
#define WIDTH  40
#define HEIGHT 20
#define MAX_SNAKE_SIZE (WIDTH * HEIGHT)
```

This makes it easy to change the game-board size.

For example:

```c
#define WIDTH 60
#define HEIGHT 30
```

would create a larger game board.

---

## 2. Point Structure

The position of the snake and food is represented using:

```c
typedef struct {
    int x;
    int y;
} Point;
```

A `Point` represents a coordinate:

```text
(x, y)
```

For example:

```text
Point p;

p.x = 10;
p.y = 5;
```

represents:

```text
x = 10
y = 5
```

---

# Data Structures

## Snake Array

The snake is represented using an array:

```c
Point snake[MAX_SNAKE_SIZE];
```

Each element represents one segment of the snake.

For example:

```text
snake[0] -> Head
snake[1] -> Body
snake[2] -> Body
snake[3] -> Body
...
```

A snake of length 5 could look like:

```text
snake[0] = (20,10)
snake[1] = (19,10)
snake[2] = (18,10)
snake[3] = (17,10)
snake[4] = (16,10)
```

---

# Direction Enumeration

The snake's movement direction is represented using an enumeration:

```c
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;
```

This is preferable to using arbitrary integers such as:

```c
int direction = 3;
```

because:

```c
direction = RIGHT;
```

is more readable.

---

# Global Game State

The game maintains several important variables:

```c
Point snake[MAX_SNAKE_SIZE];
int snake_length;
Point food;
Direction direction;
int score;
int game_over;
```

Their purposes are:

| Variable       | Purpose                              |
| -------------- | ------------------------------------ |
| `snake[]`      | Stores snake coordinates             |
| `snake_length` | Current snake size                   |
| `food`         | Food coordinates                     |
| `direction`    | Current movement direction           |
| `score`        | Player score                         |
| `game_over`    | Indicates whether the game has ended |

---

# Snake Movement

The snake moves by creating a new head position.

For example, if the snake is moving right:

```text
Before:

oooO
   *

After:

oooO
```

The new head position is calculated using:

```c
switch (direction) {

case UP:
    new_head.y--;
    break;

case DOWN:
    new_head.y++;
    break;

case LEFT:
    new_head.x--;
    break;

case RIGHT:
    new_head.x++;
    break;
}
```

---

# Body Movement

The body follows the head.

Suppose the snake is:

```text
A B C D
      ^
     Head
```

After moving one position:

```text
  A B C D
        ^
       Head
```

This is implemented by shifting the array:

```c
for (int i = new_length - 1; i > 0; i--)
    snake[i] = snake[i - 1];
```

Then:

```c
snake[0] = new_head;
```

sets the new head.

---

# Food Generation

Food is generated randomly:

```c
food.x = rand() % WIDTH;
food.y = rand() % HEIGHT;
```

The random-number generator is initialized using:

```c
srand(time(NULL));
```

This prevents the same food sequence from occurring every time the program starts.

---

# Preventing Food From Appearing Inside the Snake

The generated food coordinate is compared against every snake segment.

Conceptually:

```text
Generate random position
        |
        v
Is position occupied?
     /       \
   Yes        No
    |          |
Generate      Use
again       position
```

This is implemented by checking:

```c
for (int i = 0; i < snake_length; i++) {

    if (snake[i].x == food.x &&
        snake[i].y == food.y) {

        occupied = 1;
        break;
    }
}
```

---

# Eating Food

The game checks whether the snake head is located at the food position:

```c
if (snake[0].x == food.x &&
    snake[0].y == food.y)
```

When food is eaten:

```c
snake_length++;
score += 10;
```

A new food location is then generated:

```c
generate_food();
```

---

# Collision Detection

There are two major types of collision.

## 1. Wall Collision

The game checks whether the head has moved outside the board:

```c
if (new_head.x < 0 ||
    new_head.x >= WIDTH ||
    new_head.y < 0 ||
    new_head.y >= HEIGHT)
```

If this condition is true:

```c
game_over = 1;
```

---

## 2. Self Collision

The head is compared against every body segment:

```c
for (int i = 1; i < snake_length; i++) {

    if (snake[0].x == snake[i].x &&
        snake[0].y == snake[i].y) {

        return 1;
    }
}
```

If the head occupies the same coordinate as a body segment, the game ends.

---

# Game Loop

The core of the game is the main loop:

```c
while (!game_over) {

    draw_game();

    handle_input();

    if (game_over)
        break;

    move_snake();

    usleep(100000);
}
```

This loop is responsible for continuously running the game.

---

## Game Loop Breakdown

### Step 1 — Render

```c
draw_game();
```

Displays:

* Border
* Snake
* Food
* Score

### Step 2 — Input

```c
handle_input();
```

Checks for keyboard input.

### Step 3 — Update

```c
move_snake();
```

Moves the snake.

### Step 4 — Collision

Checks:

* Wall collision
* Self collision

### Step 5 — Delay

```c
usleep(100000);
```

Controls the game speed.

`100000` microseconds equals:

```text
100 ms
```

Therefore, the game updates approximately:

```text
10 times per second
```

---

# ncurses

The project uses the Linux `ncurses` library.

Without ncurses, standard C terminal input normally waits for the user to press Enter.

Snake requires real-time input.

For example:

```c
getch();
```

allows the program to read a key press while the game is running.

---

## ncurses Initialization

The program starts ncurses using:

```c
initscr();
```

Other configuration calls include:

```c
noecho();
curs_set(FALSE);
keypad(stdscr, TRUE);
nodelay(stdscr, TRUE);
```

### `noecho()`

Prevents typed characters from appearing on the terminal.

### `curs_set(FALSE)`

Hides the terminal cursor.

### `keypad()`

Enables special keys such as arrow keys.

### `nodelay()`

Makes keyboard input non-blocking.

This is important because the snake must continue moving even when the user isn't pressing a key.

---

# ncurses Cleanup

At the end of the game:

```c
endwin();
```

restores the terminal to its normal state.

This is important because exiting an ncurses application without cleanup can leave the terminal in an unusual state.

---

# Compilation Error and Solution

A common mistake is compiling the program using:

```bash
gcc snake.c
```

This can produce errors such as:

```text
undefined reference to `initscr'
undefined reference to `mvprintw'
undefined reference to `wgetch'
undefined reference to `endwin'
```

The reason is that `ncurses.h` provides declarations for these functions, but the linker also needs the ncurses library.

Use:

```bash
gcc snake.c -o snake -lncurses
```

The `-lncurses` option links against the ncurses library.

---

# Compilation Pipeline

The compilation process can be visualized as:

```text
             snake.c
                |
                | GCC
                v
             snake.o
                |
                | Linker
                |
       +--------+---------+
       |                  |
    snake.o          libncurses
       |                  |
       +--------+---------+
                |
                v
             snake
```

Without `-lncurses`:

```text
snake.o
   |
   v
Linker
   |
   X
Undefined references
```

With:

```bash
-lncurses
```

the required ncurses functions are resolved.

---

# Building with Warnings

Use:

```bash
gcc -Wall -Wextra -O2 snake.c -o snake -lncurses
```

Warnings are particularly useful while learning C.

You can also enable additional warnings:

```bash
gcc -Wall -Wextra -Wpedantic -O2 snake.c -o snake -lncurses
```

---

# Debugging

Compile with debug information:

```bash
gcc -Wall -Wextra -g snake.c -o snake -lncurses
```

Run with GDB:

```bash
gdb ./snake
```

Useful GDB commands:

```text
break main
run
next
print score
print snake_length
continue
quit
```

---

# AddressSanitizer

AddressSanitizer can detect memory-related bugs.

Compile with:

```bash
gcc -Wall -Wextra -g \
    -fsanitize=address \
    snake.c -o snake \
    -lncurses
```

Run:

```bash
./snake
```

This is useful for detecting:

* Buffer overflows
* Invalid memory access
* Out-of-bounds array access
* Use-after-free bugs

---

# Complexity Analysis

Let:

```text
N = current snake length
```

## Movement

Moving the snake requires shifting its body:

```c
for (int i = new_length - 1; i > 0; i--)
```

Therefore:

```text
Time Complexity: O(N)
```

---

## Self Collision

The head is compared against every body segment:

```text
Time Complexity: O(N)
```

---

## Food Generation

Food generation checks whether the random position overlaps the snake:

```text
Time Complexity: O(N)
```

In the worst case, multiple random positions may need to be generated.

---

## Memory Complexity

The snake array has a maximum size:

```c
WIDTH * HEIGHT
```

Therefore:

```text
Space Complexity: O(WIDTH × HEIGHT)
```

For:

```text
WIDTH = 40
HEIGHT = 20
```

maximum capacity is:

```text
40 × 20 = 800
```

snake segments.

---

# Possible Improvements

The current implementation is intentionally simple and focuses on C fundamentals.

Several improvements can be made.

## 1. Increasing Difficulty

Increase snake speed as the score increases.

For example:

```text
Score 0-50     -> 150 ms
Score 50-100   -> 120 ms
Score 100-200  -> 90 ms
Score 200+     -> 60 ms
```

---

## 2. Pause Function

Add:

```text
P = Pause
```

The game could display:

```text
       PAUSED

Press P to continue
```

---

## 3. High Score

Store the highest score in a file:

```text
highscore.txt
```

At startup:

```text
High Score: 240
```

At game over:

```text
Score: 300
NEW HIGH SCORE!
```

---

## 4. Colored Graphics

ncurses supports colors.

The game could use different colors for:

```text
Snake head
Snake body
Food
Border
Score
```

---

## 5. Multiple Food Types

Different food items could provide different scores:

```text
*  = +10
$  = +25
@  = +50
```

---

## 6. Obstacles

Add obstacles to the board:

```text
########################
#                      #
#       ####           #
#                      #
#          *           #
#                      #
########################
```

The snake would need to avoid them.

---

## 7. Wrap-Around Mode

Instead of dying when hitting a wall:

```text
LEFT -> RIGHT
RIGHT -> LEFT
TOP -> BOTTOM
BOTTOM -> TOP
```

This creates a different game mode.

---

## 8. Modularize the Code

The current single-file implementation can eventually be divided into:

```text
snake.c
snake.h
game.c
game.h
input.c
input.h
render.c
render.h
```

This would make the project easier to maintain.

---

# Learning Objectives

This project is useful for practicing fundamental C programming concepts.

By completing this project, you practice:

* Variables
* Constants
* Macros
* Functions
* Arrays
* Structures
* Enumerations
* Pointers
* Conditional statements
* Loops
* `switch` statements
* Random-number generation
* Header files
* Libraries
* Compilation
* Linking
* Debugging
* Memory safety
* Basic algorithm design
* State machines
* Event loops

---

# C Concepts Practiced

## Structures

```c
typedef struct {
    int x;
    int y;
} Point;
```

Used to represent coordinates.

---

## Enumerations

```c
typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;
```

Used to represent movement state.

---

## Arrays

```c
Point snake[MAX_SNAKE_SIZE];
```

Used to store the snake body.

---

## Functions

The program separates functionality into functions such as:

```c
init_game()
generate_food()
draw_game()
handle_input()
move_snake()
check_self_collision()
```

This demonstrates modular programming.

---

# State Machine Perspective

The game can also be viewed as a simple state machine:

```text
             +---------+
             |  START  |
             +----+----+
                  |
                  v
             +---------+
        +--->| PLAYING |
        |    +----+----+
        |         |
        |         |
        |      Collision
        |         |
        |         v
        |    +---------+
        |    |  GAME   |
        |    |  OVER   |
        |    +---------+
        |
        +---- Restart
```

The major state is:

```text
PLAYING
```

and the game transitions to:

```text
GAME_OVER
```

when a collision or quit condition occurs.

---

# Future Extensions

The project can be progressively expanded into a more sophisticated C application.

### Beginner

* Add pause
* Add high score
* Add colors
* Change board size
* Change game speed

### Intermediate

* Add obstacles
* Add multiple food types
* Add levels
* Add persistent high scores
* Add configuration file
* Split source into multiple files
* Add Makefile

### Advanced

* Implement a linked-list-based snake
* Add replay functionality
* Add AI-controlled snake
* Add path-finding
* Add multiple snakes
* Add network multiplayer
* Separate game engine from rendering
* Create unit tests
* Add CI builds
* Package the application

---

# Example Makefile

A simple Makefile can be used to simplify compilation:

```makefile
CC = gcc
CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lncurses

TARGET = snake
SRC = snake.c

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
```

Then compile using:

```bash
make
```

Run:

```bash
make run
```

Clean:

```bash
make clean
```

---

# Recommended Repository Commands

Initialize Git:

```bash
git init
```

Add files:

```bash
git add snake.c README.md Makefile
```

Commit:

```bash
git commit -m "Add terminal Snake game in C"
```

Check status:

```bash
git status
```

View history:

```bash
git log --oneline
```

---

# Suggested `.gitignore`

Create:

```text
.gitignore
```

with:

```text
snake
*.o
*.out
```

This prevents generated binaries and object files from being committed.

---

# Project Goals

The primary goal of this project is not simply to create a playable Snake game.

It is to use a relatively small application to understand how multiple C concepts work together:

```text
C Language
    |
    +-- Data Structures
    |
    +-- Arrays
    |
    +-- Functions
    |
    +-- State Management
    |
    +-- Algorithms
    |
    +-- Input Handling
    |
    +-- Terminal I/O
    |
    +-- Library Linking
    |
    +-- Debugging
    |
    +-- Build System
```

This makes the project a useful stepping stone toward larger C programming and systems-programming projects.

---

# License

This project can be released under the MIT License.

```text
MIT License

Copyright (c) 2026

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files, to deal in the Software
without restriction, including without limitation the rights to use, copy,
modify, merge, publish, distribute, sublicense, and/or sell copies of the
Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
```

---

# Summary

This Snake Game demonstrates how a complete interactive application can be built using standard C programming techniques and a terminal UI library.

The project covers:

```text
Structures
    +
Arrays
    +
Enums
    +
Functions
    +
Random Numbers
    +
Keyboard Input
    +
Game Loop
    +
Collision Detection
    +
ncurses
    +
GCC
    +
Linking
    +
Debugging
    =
Complete C Application
```

The project provides a foundation for progressing from small C exercises such as **Tic-Tac-Toe** toward larger C/DSA and systems-programming projects.
