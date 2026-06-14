# C Programming - Loops and Control Statements

## Overview
- Loops are used in C programming to execute a block of code repeatedly until a specified condition is met.
- They help reduce code duplication and improve program efficiency.

### Topics Covered
* Loops in C
* `for` Loop
* `while` Loop
* `do...while` Loop
* `for` vs `while`
* Nested Loops
* Infinite Loops
* `break` Statement
* `continue` Statement
* `goto` Statement

# 1. Loops in C
- A loop allows a set of statements to execute repeatedly based on a condition.

## Benefits

* Reduces code repetition
* Improves readability
* Automates repetitive tasks
* Simplifies complex operations

## Types of Loops

| Loop Type    | Description                                          |
| ------------ | ---------------------------------------------------- |
| `for`        | Used when the number of iterations is known          |
| `while`      | Used when the number of iterations is unknown        |
| `do...while` | Executes at least once before checking the condition |

# 2. for Loop
- The `for` loop is commonly used when the number of iterations is known beforehand.

## Syntax

```c
for(initialization; condition; increment/decrement)
{
    // statements
}
```

## Flow

1. Initialization executes once.
2. Condition is checked.
3. Loop body executes if the condition is true.
4. Increment/Decrement executes.
5. Repeat until the condition becomes false.

## Example

```c
#include <stdio.h>

int main()
{
    for(int i = 1; i <= 5; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}
```

### Output

```text
1
2
3
4
5
```

---

# 3. while Loop
- The `while` loop executes as long as the condition remains true.

## Syntax

```c
while(condition)
{
    // statements
}
```

## Example

```c
#include <stdio.h>

int main()
{
    int i = 1;

    while(i <= 5)
    {
        printf("%d\n", i);
        i++;
    }

    return 0;
}
```

### Output

```text
1
2
3
4
5
```

# 4. do...while Loop
- The `do...while` loop executes the loop body first and checks the condition afterward.

## Key Feature
- The loop body executes at least once.

## Syntax

```c
do
{
    // statements
}
while(condition);
```

## Example

```c
#include <stdio.h>

int main()
{
    int i = 1;

    do
    {
        printf("%d\n", i);
        i++;
    }
    while(i <= 5);

    return 0;
}
```

### Output

```text
1
2
3
4
5
```

# 5. for Loop vs while Loop

| Feature             | for Loop           | while Loop               |
| ------------------- | ------------------ | ------------------------ |
| Initialization      | Inside loop syntax | Usually before loop      |
| Condition           | Inside loop syntax | Inside loop syntax       |
| Increment/Decrement | Inside loop syntax | Usually inside loop body |
| Best Use Case       | Known iterations   | Unknown iterations       |
| Readability         | More compact       | More flexible            |

## Example

### for Loop

```c
for(int i = 0; i < 10; i++)
{
    printf("%d\n", i);
}
```

### while Loop

```c
int i = 0;

while(i < 10)
{
    printf("%d\n", i);
    i++;
}
```

# 6. Nested Loops
- A loop inside another loop is called a nested loop.

## Syntax

```c
for(...)
{
    for(...)
    {
        // statements
    }
}
```

## Example

```c
#include <stdio.h>

int main()
{
    for(int row = 1; row <= 3; row++)
    {
        for(int col = 1; col <= 3; col++)
        {
            printf("* ");
        }

        printf("\n");
    }

    return 0;
}
```

### Output

```text
* * *
* * *
* * *
```

## Common Uses
* Pattern printing
* Matrix operations
* Searching multidimensional arrays

# 7. Infinite Loop
- An infinite loop never terminates because its condition always evaluates to true.

## Example Using while

```c
while(1)
{
    printf("Running...\n");
}
```

## Example Using for

```c
for(;;)
{
    printf("Running...\n");
}
```

## Applications

* Embedded Systems
* RTOS Tasks
* Device Drivers
* Event Handling Systems

# 8. break Statement
- The `break` statement immediately terminates the loop.

## Syntax

```c
break;
```

## Example

```c
#include <stdio.h>

int main()
{
    for(int i = 1; i <= 10; i++)
    {
        if(i == 5)
        {
            break;
        }

        printf("%d\n", i);
    }

    return 0;
}
```

### Output

```text
1
2
3
4
```

# 9. continue Statement
- The `continue` statement skips the current iteration and moves to the next iteration.

## Example

```c
#include <stdio.h>

int main()
{
    for(int i = 1; i <= 5; i++)
    {
        if(i == 3)
        {
            continue;
        }

        printf("%d\n", i);
    }

    return 0;
}
```

### Output

```text
1
2
4
5
```

# 10. goto Statement
- The `goto` statement transfers program control to a labeled statement.

## Syntax

```c
goto label;

/* code */

label:
    statement;
```

## Example

```c
#include <stdio.h>

int main()
{
    int i = 1;

start:

    printf("%d\n", i);
    i++;

    if(i <= 5)
    {
        goto start;
    }

    return 0;
}
```

### Output

```text
1
2
3
4
5
```

## Caution
* Excessive use of `goto` makes code difficult to read and maintain.
* Modern C programming generally prefers loops and functions instead.

---

# Summary

| Statement     | Purpose                     |
| ------------- | --------------------------- |
| `for`         | Fixed number of iterations  |
| `while`       | Condition-based looping     |
| `do...while`  | Executes at least once      |
| Nested Loop   | Loop inside another loop    |
| Infinite Loop | Runs forever                |
| `break`       | Exit loop immediately       |
| `continue`    | Skip current iteration      |
| `goto`        | Jump to a labeled statement |

# Best Practices

* Use `for` when the iteration count is known.
* Use `while` when termination depends on runtime conditions.
* Use `do...while` when at least one execution is required.
* Avoid unnecessary nested loops to improve performance.
* Use `break` and `continue` carefully.
* Avoid `goto` unless absolutely necessary.
* Ensure loop termination conditions are correct to prevent infinite loops.

