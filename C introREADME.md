# C Programming Tutorial - Complete Guide
> A comprehensive beginner-to-advanced guide to learning C programming from TutorialsPoint

## Overview
- C is a **general-purpose programming language** known for its efficiency and flexibility.
- It serves as the foundation for many modern programming languages and is widely used in system programming, operating systems, embedded systems, and application development.

### Key Points:
- **General-purpose** and mid-level programming language
- **Efficient** and fast execution
- Suitable for **system programming** (OS, compilers)
- Foundation for languages like Java, Python, JavaScript

## Features

C programming language offers several distinctive features:

| Feature | Description |
|---------|-------------|
| **Structured Language** | Code can be split into functions/blocks for better organization |
| **Fast Execution** | Efficient compilation and execution speed |
| **Mid-Level Language** | Combines assembly language capabilities with high-level features |
| **Rich Library** | Extensive built-in functions for complex programs |
| **Pointers** | Direct memory access for powerful data manipulation |
| **Recursion** | Functions can call themselves for code reusability |
| **Portability** | Programs run on different systems with minimal changes |
| **Extensible** | Easily adds new features to existing programs |

## History

- C was created by **Dennis M. Ritchie** at **Bell Laboratories** (AT&T Labs) in **1972**.

### Historical Timeline:
- **1972**: C developed by Dennis Ritchie at Bell Labs
- **Purpose**: Initially created for developing the **UNIX operating system**
- **Evolution**: Derived from BCPL and B programming languages
- **Impact**: Became the foundation for countless modern languages (Java, PHP, JavaScript)

Dennis Ritchie is recognized as the **founder of the C language**.

## Standards
- C has evolved through several standardized versions:

| Standard | Year | Name |
|----------|------|------|
| C89/C90 | 1989/1990 | ANSI C / ISO C (first standard) |
| C99 | 1999 | ISO/IEC 9899:1999 |
| C11 | 2011 | ISO/IEC 9899:2011 |
| C17 | 2018 | ISO/IEC 9899:2018 (current standard) |

**C17** is the current standard, introducing technical corrections and clarifications without new language features.

## Environment Setup

- To start programming in C, you need:

### Required Tools:
1. **Text Editor** (Notepad, VS Code, etc.)
2. **C Compiler** (GCC recommended)

### GCC Compiler Installation:

**Windows:**
- Download MinGW from sourceforge.net
- Install `mingw32-base` and `mingw32-gcc-g++` packages
- Add MinGW's bin directory to PATH environment variable

**Linux:**
```bash
sudo apt-get install gcc
```

**macOS:**
```bash
xcode-select --install
```

### Verify Installation:
```bash
gcc --version
```

## Program Structure

- A basic C program follows this structure:

```c
#include <stdio.h>

// Global declarations

int main() {
    // Local declarations
    // Statements
    return 0;
}
```

### Key Components:
- **`#include <stdio.h>`**: Header file for input/output functions
- **`int main()`**: Main function where execution starts
- **Return 0**: Indicates successful program execution

## Hello World

- The classic first program in C:

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}
```

### Output:
Hello, World!


This program demonstrates:
- Including the standard I/O library
- Using `printf()` to output text
- Adding a newline character `\n`

---

## Compilation Process

C programs go through **4 stages** before becoming executable:

| Stage | Tool | Input | Output |
|-------|------|-------|--------|
| 1. Preprocessing | Preprocessor | `.c` file | `.i` file |
| 2. Compilation | Compiler | `.i` file | `.s` (assembly) |
| 3. Assembly | Assembler | `.s` file | `.o` (object) |
| 4. Linking | Linker | `.o` files | Executable |

### GCC Commands:
```bash
gcc -E program.c      # Preprocessing only
gcc -S program.i      # Compilation to assembly
gcc -c program.s      # Assembly to object file
gcc program.o         # Linking to executable
```

---

## Comments

C supports two types of comments:

### Single-Line Comments
```c
// This is a single-line comment
printf("Hello"); // Comment after code
```

### Multi-Line Comments
```c
/*
 * This is a multi-line comment
 * Can span multiple lines
 */
```

**Purpose**: Comments explain code logic and are ignored by the compiler.

---

## Basic Syntax

### Data Types:
| Type | Description | Example |
|------|-------------|---------|
| `int` | Integer | `int age = 25;` |
| `float` | Floating-point | `float price = 9.99;` |
| `double` | Double precision | `double large = 1.23e10;` |
| `char` | Character | `char grade = 'A';` |

### Operators:
- **Arithmetic**: `+`, `-`, `*`, `/`, `%`
- **Relational**: `==`, `!=`, `>`, `<`, `>=`, `<=`
- **Logical**: `&&`, `||`, `!`
- **Assignment**: `=`, `+=`, `-=`, `*=`, `/=`

### Variables:
```c
int number = 10;
float price = 19.99;
char letter = 'A';
```

---

## User Input

Use `scanf()` to read user input:

```c
#include <stdio.h>

int main() {
    int number;
    
    printf("Enter a number: ");
    scanf("%d", &number);
    
    printf("You entered: %d\n", number);
    return 0;
}
```

### Common scanf Format Specifiers:
- `%d` - Integer
- `%f` - Float
- `%lf` - Double
- `%c` - Character
- `%s` - String

**Important**: Use `&` (address operator) before variable name in `scanf()`.

## Printf Function

`printf()` outputs formatted text to the console:

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    printf("Number: %d\n", 42);
    printf("Float: %f\n", 3.14);
    return 0;
}
```

### Key Features:
- Prints strings, variables, and formatted output
- `\n` adds a newline
- Uses format specifiers for variables

## Format Specifiers

Format specifiers control how data is displayed:

| Specifier | Data Type | Example Output |
|-----------|-----------|----------------|
| `%d` | int | `42` |
| `%f` | float | `3.141593` |
| `%.2f` | float | `3.14` (2 decimal places) |
| `%lf` | double | `1.234567890123` |
| `%c` | char | `A` |
| `%s` | string | `Hello` |
| `%p` | pointer | `0x7fff5fbff6c4` |
| `%x` | int (hex) | `2a` |

### Usage Example:
```c
int age = 25;
float price = 19.99;

printf("Age: %d, Price: %.2f\n", age, price);
// Output: Age: 25, Price: 19.99
```

## Resources

### Official TutorialsPoint C Programming Links:
1. [C Programming Index](https://www.tutorialspoint.com/cprogramming/index.htm)
2. [C Overview](https://www.tutorialspoint.com/cprogramming/c_overview.htm)
3. [C Features](https://www.tutorialspoint.com/cprogramming/c_features.htm)
4. [C History](https://www.tutorialspoint.com/cprogramming/c_history.htm)
5. [C Standards](https://www.tutorialspoint.com/cprogramming/c_standards.htm)
6. [Environment Setup](https://www.tutorialspoint.com/cprogramming/c_environment_setup.htm)
7. [Program Structure](https://www.tutorialspoint.com/cprogramming/c_program_structure.htm)
8. [Hello World](https://www.tutorialspoint.com/cprogramming/c_hello_world.htm)
9. [Compilation Process](https://www.tutorialspoint.com/cprogramming/c_compilation_process.htm)
10. [Comments](https://www.tutorialspoint.com/cprogramming/c_comments.htm)
11. [Basic Syntax](https://www.tutorialspoint.com/cprogramming/c_basic_syntax.htm)
12. [User Input](https://www.tutorialspoint.com/cprogramming/c_user_input.htm)
13. [Printf Function](https://www.tutorialspoint.com/cprogramming/c_printf_function.htm)
14. [Format Specifiers](https://www.tutorialspoint.com/cprogramming/c_format_specifiers.htm)

### Additional Resources:
- [GeeksforGeeks C Tutorial](https://www.geeksforgeeks.org/c/c-programming-language/)
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [W3Schools C Programming](https://www.w3schools.com/c/)

---

## Quick Start

```bash
# 1. Create a C file
echo '#include <stdio.h>
int main() {
    printf("Hello, World!\n");
    return 0;
}' > hello.c

# 2. Compile
gcc hello.c -o hello

# 3. Run
./hello
```

---

**License**: This README is based on TutorialsPoint's free C programming tutorial content.

**Last Updated**: June 2026
