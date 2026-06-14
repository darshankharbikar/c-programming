# C Programming - Functions

## Overview
- Functions are reusable blocks of code used to perform a specific task.
- They help divide a program into smaller, manageable, and reusable parts.

## Topics Covered

* Functions in C
* Function Prototype
* `main()` Function
* Call by Value
* Call by Reference
* Nested Functions
* Variadic Functions
* User-Defined Functions
* Callback Functions
* `return` Statement
* Recursion
* Predefined Identifier `__func__`

# 1. Functions in C
- A function is a block of code that performs a specific task.

## Benefits
* Code reusability
* Better readability
* Easy debugging
* Modular programming
* Reduces code duplication

## Basic Syntax

```c
return_type function_name(parameter_list)
{
    // function body
}
```

## Example

```c
#include <stdio.h>

void display()
{
    printf("Hello from function\n");
}

int main()
{
    display();
    return 0;
}
```

---

# 2. Function Prototype
- A function prototype tells the compiler about the function before it is used.

## Syntax

```c
return_type function_name(parameter_list);
```

## Example

```c
#include <stdio.h>

int add(int, int);

int main()
{
    int result = add(10, 20);
    printf("Result = %d\n", result);
    return 0;
}

int add(int a, int b)
{
    return a + b;
}
```

---

# 3. main() Function
- The `main()` function is the entry point of every C program.

## Common Forms

```c
int main()
{
    return 0;
}
```

```c
int main(int argc, char *argv[])
{
    return 0;
}
```

## Example

```c
#include <stdio.h>

int main()
{
    printf("Program starts from main function\n");
    return 0;
}
```

---

# 4. Function Call by Value
- In call by value, a copy of the variable is passed to the function.
- Changes made inside the function do not affect the original variable.

## Example

```c
#include <stdio.h>

void change(int x)
{
    x = 50;
}

int main()
{
    int a = 10;

    change(a);

    printf("a = %d\n", a);

    return 0;
}
```

## Output

```text
a = 10
```

---

# 5. Function Call by Reference
- In call by reference, the address of a variable is passed to the function.
- Changes made inside the function affect the original variable.

## Example

```c
#include <stdio.h>

void change(int *x)
{
    *x = 50;
}

int main()
{
    int a = 10;

    change(&a);

    printf("a = %d\n", a);

    return 0;
}
```

## Output

```text
a = 50
```

---

# 6. Nested Functions
- Standard C does not support defining one function inside another function.
- Some compilers, such as GCC, may support nested functions as an extension.

## Example

```c
#include <stdio.h>

void outer()
{
    printf("Outer function\n");

    // Nested functions are not supported in standard C
}

int main()
{
    outer();
    return 0;
}
```

# 7. Variadic Functions
- A variadic function can accept a variable number of arguments.
- The header file `<stdarg.h>` is used for variadic functions.

## Example

```c
#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
    va_list args;
    int total = 0;

    va_start(args, count);

    for(int i = 0; i < count; i++)
    {
        total += va_arg(args, int);
    }

    va_end(args);

    return total;
}

int main()
{
    printf("Sum = %d\n", sum(3, 10, 20, 30));
    return 0;
}
```

# 8. User-Defined Functions
- User-defined functions are functions created by the programmer.

## Example

```c
#include <stdio.h>

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    int result = multiply(5, 4);

    printf("Result = %d\n", result);

    return 0;
}
```

---

# 9. Callback Function
- A callback function is a function passed as an argument to another function.
- It is commonly used in event handling, driver programming, and system-level programming.

## Example

```c
#include <stdio.h>

void greet()
{
    printf("Hello from callback function\n");
}

void execute(void (*callback)())
{
    callback();
}

int main()
{
    execute(greet);
    return 0;
}
```

# 10. return Statement
- The `return` statement is used to return a value from a function or terminate function execution.

## Example

```c
#include <stdio.h>

int square(int x)
{
    return x * x;
}

int main()
{
    int result = square(5);

    printf("Square = %d\n", result);

    return 0;
}
```

# 11. Recursion
- Recursion is a technique where a function calls itself.
- A recursive function must have a base condition to stop recursion.

## Example

```c
#include <stdio.h>

int factorial(int n)
{
    if(n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    printf("Factorial = %d\n", factorial(5));
    return 0;
}
```

## Output

```text
Factorial = 120
```

# 12. Predefined Identifier **func**
- `__func__` is a predefined identifier that stores the name of the current function.

## Example

```c
#include <stdio.h>

void test()
{
    printf("Current function: %s\n", __func__);
}

int main()
{
    test();
    return 0;
}
```

## Output

```text
Current function: test
```

# Summary

| Topic                 | Description                          |
| --------------------- | ------------------------------------ |
| Function              | Reusable block of code               |
| Function Prototype    | Function declaration before use      |
| `main()`              | Entry point of C program             |
| Call by Value         | Passes copy of variable              |
| Call by Reference     | Passes address of variable           |
| Variadic Function     | Accepts variable number of arguments |
| User-Defined Function | Function created by programmer       |
| Callback Function     | Function passed as argument          |
| `return`              | Returns value from function          |
| Recursion             | Function calling itself              |
| `__func__`            | Stores current function name         |

# Best Practices

* Use meaningful function names.
* Keep each function focused on one task.
* Declare function prototypes before using functions.
* Use `void` when a function does not return a value.
* Use pointers carefully when passing by reference.
* Always define a base condition in recursive functions.
* Avoid excessive recursion if stack usage is a concern.
* Prefer modular functions for large programs.
* Use callback functions where flexible behavior is required.

