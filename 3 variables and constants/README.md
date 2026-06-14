## Variables, Constants, and Linkage
- This section covers how C stores values, how fixed values are represented, and how visibility across files works.

### Variables in C
- Variables are named storage locations used to hold data that may change during program execution.
- They can be local, global, or static depending on where they are declared and how long they live.
- Global variables are declared outside functions and are visible across the program, while local variables
 exist only inside the block or function where they are declared. [web:81][web:83][web:84]

#### Variable Types
- Local variables.
- Global variables.
- Static variables.
- Function parameters. [web:81][web:84][web:92]

#### Example
```c
#include <stdio.h>

int g = 10;

int main() {
    int local = 5;
    printf("%d %d\n", g, local);
    return 0;
}
```

### Constants in C
- Constants are fixed values that do not change during program execution.
- C supports integer, floating-point, character, and string constants, and it also supports symbolic constants
   created with `#define` or enumeration values. [web:68][web:90][web:76]

#### Constant Types
- Integer constants.
- Floating-point constants.
- Character constants.
- String constants.
- Symbolic constants. [web:68][web:90]

#### Example
```c
#define PI 3.14

int main() {
    const int max = 100;
    return 0;
}
```

### Const Qualifier
- The `const` qualifier marks an object as read-only after initialization.
- It is commonly used to protect values from accidental modification and to make intent clear in code.
- In C, `const`-qualified identifiers have external linkage by default unless otherwise specified. [web:77][web:82][web:91]

#### Example
```c
const int limit = 50;
```

### Internal and External Linkage
- Linkage controls whether an identifier can be accessed from one file or across multiple files.
- `static` is used for internal linkage, which limits visibility to the current translation unit, while `extern` is used for
external linkage, which allows sharing across files. By default, globally scoped variables and functions have external linkage. [web:85][web:91][web:80]

#### Linkage Summary
| Linkage | Keyword | Visibility |
|---|---|---|
| Internal | `static` | Current file only |
| External | `extern` | Shared across files |
| Default global linkage | none | Program-wide for non-static globals and functions | [web:85][web:91][web:80]

#### Example
```c
static int fileOnly = 1;
extern int sharedValue;
```

### Notes
- Variables must be declared before use.
- Constants improve readability and prevent accidental changes.
- `const` and `static` serve different purposes: `const` controls mutability, while `static` controls linkage or lifetime 
depending on context. [web:77][web:85][web:92]
