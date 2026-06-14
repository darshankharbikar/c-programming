# C Programming: Tokens, Keywords, and Identifiers
- A concise learning guide based on TutorialsPoint topics for C tokens, keywords, and identifiers.

## Table of Contents
- [Tokens in C](#tokens-in-c)
- [Keywords in C](#keywords-in-c)
- [Identifiers in C](#identifiers-in-c)
- [Quick Examples](#quick-examples)
- [Reference Links](#reference-links)

## Tokens in C
- Tokens are the smallest meaningful units in a C program.
- C programs are built from these basic elements, which the compiler recognizes while reading source code.
- Common token categories include keywords, identifiers, constants, strings, operators, and punctuators. [web:61][web:64]

### Token Types
- Keywords
- Identifiers
- Constants
- Strings
- Operators
- Punctuators or special symbols [web:61][web:64]

## Keywords in C
- Keywords are reserved words with predefined meanings in C.
- They cannot be used as variable names, function names, or any other identifiers.
- Standard C includes 32 reserved keywords such as `auto`, `break`, `case`, `char`, `const`, and `continue`. [web:61][web:59][web:72]

### Examples of Keywords
```c
int
return
if
while
for
switch
```

### Notes
- Keywords are case-sensitive.
- Keywords define the structure and behavior of C programs.
- They are reserved by the language and cannot be redefined for custom use. [web:61][web:59]

## Identifiers in C
- Identifiers are user-defined names used for variables, functions, arrays, and other program elements.
- They must start with a letter or underscore and may contain letters, digits, and underscores after that.
- Identifiers are case-sensitive and must not match any keyword. [web:60][web:61][web:66]

### Rules for Identifiers
- Must begin with a letter or underscore.
- Can contain only letters, digits, and underscores.
- Must not be a keyword.
- Must not contain spaces or special characters.
- Are case-sensitive. [web:60][web:61][web:66]

### Good Naming Practice
- Use meaningful names like `totalMarks` or `student_count`.
- Prefer consistent naming for variables and functions.
- Avoid names that are too short or unclear. [web:60][web:63]

## Quick Examples

```c
#include <stdio.h>

int main() {
    int age = 20;          // keyword: int, identifier: age
    float price = 99.5;    // keyword: float, identifier: price
    printf("%d %.1f\n", age, price);
    return 0;              // keyword: return
}
```

### What this shows
- `int`, `float`, and `return` are keywords.
- `main`, `age`, and `price` are identifiers.
- `99.5` is a constant.
- `printf` is a function name used as an identifier in the program context. [web:61][web:64]

## Reference Links

- [C Tokens](https://www.tutorialspoint.com/cprogramming/c_tokens.htm)
- [C Keywords](https://www.tutorialspoint.com/cprogramming/c_keywords.htm)
- [C Identifiers](https://www.tutorialspoint.com/cprogramming/c_identifiers.htm)

## Summary
- Understanding tokens, keywords, and identifiers is essential for reading and writing valid C programs.
- Tokens are the building blocks, keywords are reserved words, and identifiers are the names you define yourself. [web:61][web:60]
