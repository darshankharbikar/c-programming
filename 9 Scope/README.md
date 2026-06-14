# C Programming - Scope Rules and Variables

## Overview
- Variables in C have different scopes, lifetimes, and storage locations depending on where and how they are declared.
- Understanding scope rules is essential for writing maintainable and bug-free programs.

## Topics Covered

* Scope Rules
* Local Variables
* Global Variables
* Static Variables
* Variable Lifetime
* Storage Duration
* Visibility

---

# 1. Scope Rules in C
- Scope determines where a variable can be accessed within a program.

## Types of Scope

| Scope Type     | Description                         |
| -------------- | ----------------------------------- |
| Block Scope    | Accessible only within a block `{}` |
| Function Scope | Accessible throughout a function    |
| File Scope     | Accessible throughout a source file |
| Global Scope   | Accessible from multiple functions  |

---

# 2. Local Variables
- A local variable is declared inside a function or block.

## Characteristics

* Accessible only within its block.
* Created when the block begins execution.
* Destroyed when the block exits.
* Stored in stack memory (typically).

## Example

```c
#include <stdio.h>

int main()
{
    int x = 10;

    printf("%d\n", x);

    return 0;
}
```

## Visibility

```text
main()
{
    int x = 10;   <-- Visible only inside main()
}
```

---

# 3. Block Scope
- Variables declared inside a block are visible only within that block.

## Example

```c
#include <stdio.h>

int main()
{
    int x = 10;

    {
        int y = 20;

        printf("x = %d\n", x);
        printf("y = %d\n", y);
    }

    return 0;
}
```

## Invalid Access

```c
#include <stdio.h>

int main()
{
    {
        int y = 20;
    }

    printf("%d\n", y); // Error

    return 0;
}
```

---

# 4. Variable Shadowing
- A local variable can hide another variable with the same name.

## Example

```c
#include <stdio.h>

int x = 100;

int main()
{
    int x = 50;

    printf("%d\n", x);

    return 0;
}
```

## Output

```text
50
```
- The local variable hides the global variable.

---

# 5. Global Variables
- A global variable is declared outside all functions.

## Characteristics

* Accessible from all functions in the same file.
* Created before program execution begins.
* Exists until the program terminates.
* Stored in data or BSS segments.

## Example

```c
#include <stdio.h>

int count = 100;

void display()
{
    printf("%d\n", count);
}

int main()
{
    display();

    printf("%d\n", count);

    return 0;
}
```

## Output

```text
100
100
```

---

# 6. Global Variable Memory Layout

```text
+----------------------+
|      Stack           |
+----------------------+
|       Heap           |
+----------------------+
|       BSS            |
| Uninitialized Global |
+----------------------+
|      Data            |
| Initialized Global   |
+----------------------+
|      Text            |
+----------------------+
```

## Example

```c
int global_var = 10;      // Data section
int global_count;         // BSS section
```

---

# 7. Static Variables
- A static variable retains its value between function calls.

## Characteristics

* Initialized only once.
* Lifetime is entire program execution.
* Scope remains local if declared inside a function.
* Stored in Data/BSS segment.

## Example

```c
#include <stdio.h>

void counter()
{
    static int count = 0;

    count++;

    printf("%d\n", count);
}

int main()
{
    counter();
    counter();
    counter();

    return 0;
}
```

## Output

```text
1
2
3
```

---

# 8. Ordinary Local Variable vs Static Local Variable

## Ordinary Local Variable

```c
void test()
{
    int count = 0;

    count++;

    printf("%d\n", count);
}
```

Output:

```text
1
1
1
```
- Variable is recreated every function call.

---

## Static Local Variable

```c
void test()
{
    static int count = 0;

    count++;

    printf("%d\n", count);
}
```

Output:

```text
1
2
3
```
- Variable persists across function calls.

---

# 9. Static Global Variable
- A global variable declared with `static` becomes visible only within the current source file.

## Example

```c
static int device_count = 5;
```

## Benefits

* Prevents accidental access from other files.
* Improves encapsulation.
* Reduces namespace conflicts.

---

# 10. Lifetime vs Scope

## Scope

Defines where a variable can be accessed.

## Lifetime
- Defines how long a variable exists in memory.

### Example

```c
void test()
{
    static int x = 0;
}
```

| Property | Value             |
| -------- | ----------------- |
| Scope    | Local to function |
| Lifetime | Entire program    |

---

# 11. Storage Duration Summary

| Variable Type          | Scope               | Lifetime           |
| ---------------------- | ------------------- | ------------------ |
| Local Variable         | Block               | Function execution |
| Global Variable        | Entire file/program | Entire program     |
| Static Local Variable  | Block               | Entire program     |
| Static Global Variable | Current file        | Entire program     |

---

# 12. Embedded Systems Perspective

## Global Variables

Commonly used for:

* Device status
* Shared resources
* System state information

Example:

```c
volatile int uart_rx_count;
```

---

## Static Variables

Commonly used for:

* Driver private data
* State machines
* Persistent counters

Example:

```c
static uint32_t rx_packets;
```

---

## Static Global Variables
- Widely used in Linux Device Drivers.

Example:

```c
static struct device_data dev;
```

Benefits:

* Hides internal implementation details.
* Prevents symbol conflicts.
* Improves module encapsulation.

---

# Summary

| Variable Type | Accessible From     | Lifetime         |
| ------------- | ------------------- | ---------------- |
| Local         | Current Block       | Until Block Ends |
| Global        | Entire Program/File | Entire Program   |
| Static Local  | Current Function    | Entire Program   |
| Static Global | Current Source File | Entire Program   |

---

# Best Practices

* Prefer local variables whenever possible.
* Minimize usage of global variables.
* Use `static` globals to limit visibility to a source file.
* Use static local variables only when persistence is required.
* Avoid excessive global state in large projects.
* Use meaningful names to avoid variable shadowing.
* In embedded systems, mark hardware-shared variables as `volatile` when required.
* Keep module-private data as `static` in driver development.

