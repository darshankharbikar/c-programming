## Data Types and Type Handling
- This section explains how C stores different kinds of values and how expressions are converted during computation.

### Data Types in C
- C provides basic data types such as `int`, `char`, `float`, `double`, and `void`.
- These types define what kind of values a variable can store and how much memory is typically used.
- The choice of data type affects precision, range, and performance. [web:96][web:93][web:98]

#### Common Data Types
| Type | Description |
|---|---|
| `int` | Stores whole numbers. |
| `char` | Stores a single character. |
| `float` | Stores decimal values with single precision. |
| `double` | Stores decimal values with double precision. |
| `void` | Represents absence of a value or type. | [web:96][web:98]

### Literals in C
- A literal is a fixed value written directly in source code. C supports integer literals, floating-point literals, character literals, and string literals.
- Literals are often used when initializing variables or passing constant values to functions. [web:94][web:99][web:73]

#### Example
```c
int a = 10;
float b = 3.5;
char c = 'A';
char *s = "Hello";
```

### Escape Sequences
- Escape sequences are special character combinations that begin with a backslash.
- They are used in strings and character constants to represent non-printable characters or special formatting.
- Common examples include `\n` for new line, `\t` for tab, and `\\` for a literal backslash. [web:95][web:97][web:100]

#### Common Escape Sequences
- `\n` new line.
- `\t` horizontal tab.
- `\\` backslash.
- `\"` double quote.
- `\'` single quote. [web:95][web:100]

### Booleans in C
- Boolean values represent truth values, usually `true` or `false`.
- In modern C, boolean support is available through `stdbool.h`, 
which defines `bool`, `true`, and `false`. A value of `0` is false, and
nonzero values are treated as true in conditional expressions. [web:102][web:105][web:111]

#### Example
```c
#include <stdbool.h>

bool isReady = true;
```

### Integer Promotions
- Integer promotions are conversion rules that automatically convert smaller integer types to `int` or `unsigned int` before many arithmetic operations.
- This helps the compiler perform calculations consistently and safely across different integer sizes.
- These promotions are part of the usual arithmetic conversions. [web:103][web:106][web:109]

### Character Arithmetic
- Characters in C are stored as numeric codes, so arithmetic can be performed on them. For example, adding `1` to `'A'` typically yields `'B'` because character values behave like integer codes. This makes character arithmetic useful in loops and simple encoding tasks. [web:96][web:101][web:93]

#### Example
```c
char ch = 'A';
printf("%c\n", ch + 1);
```

### Type Conversion
- Type conversion happens when C changes a value from one data type to another.
- Implicit conversion occurs automatically, while explicit conversion is controlled by the programmer.
- Conversions are common in assignments and mixed-type expressions. [web:104][web:107][web:110]

### Type Casting
- Type casting is the explicit conversion of a value to a different type using a cast operator.
- It is useful when you want to force a specific interpretation of a value, such as converting a floating-point expression to an integer.
- Casting should be used carefully because it can lose precision. [web:104][web:107][web:110]

#### Example
```c
int x = (int)3.14;
```

### Notes
- Use the correct data type for the value range you need.
- Prefer `double` when more precision is required.
- Use `const` for values that should not change, and casting only when necessary. [web:96][web:77][web:110]
  
