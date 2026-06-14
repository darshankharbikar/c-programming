## Operators in C
- Operators are symbols used to perform operations on one or more operands.
- C provides several categories of operators for arithmetic, comparison, logic, bit manipulation, assignment, and more. [web:112][web:118][web:121]

### Operator Categories
- Arithmetic operators.
- Unary operators.
- Relational operators.
- Logical operators.
- Bitwise operators.
- Assignment operators.
- Increment and decrement operators.
- Miscellaneous operators. [web:112][web:118][web:121]

## Arithmetic Operators
- Arithmetic operators are used for mathematical calculations.
- The main arithmetic operators in C are `+`, `-`, `*`, `/`, and `%`. Division returns the quotient, while modulus returns the remainder. [web:123][web:126][web:129]

### Example
```c
int a = 10, b = 3;
printf("%d\n", a + b);
printf("%d\n", a % b);
```

## Unary Operators
- Unary operators work on a single operand.
- Common unary operators include unary plus, unary minus, logical NOT `!`, and increment/decrement operators `++` and `--`. [web:112][web:115][web:113]

### Example
```c
int x = 5;
printf("%d\n", -x);
printf("%d\n", !x);
```

## Relational Operators
- Relational operators compare two values and return a truth value. The common relational operators are `<`, `>`, `<=`, `>=`, `==`, and `!=`. They are used in conditions and loops. [web:115][web:118][web:123]

### Example
```c
if (a > b) {
    printf("a is greater\n");
}
```

## Logical Operators
- Logical operators combine or negate conditions.
- The main logical operators are `&&`, `||`, and `!`.
- These operators are commonly used in control statements such as `if`, `while`, and `for`. [web:112][web:115][web:130]

### Example
```c
if (a > 0 && b > 0) {
    printf("Both are positive\n");
}
```

## Bitwise Operators
- Bitwise operators work on individual bits of integer values.
- Common bitwise operators include `&`, `|`, `^`, `~`, `<<`, and `>>`.
- These are often used in low-level programming, masking, and embedded systems. [web:118][web:121][web:127]

### Example
```c
int x = 5, y = 3;
printf("%d\n", x & y);
```

## Assignment Operators
- Assignment operators store a value in a variable.
- The basic assignment operator is `=`, and compound operators include `+=`, `-=`, `*=`, `/=`, and `%=`.
- These operators update the left-hand operand using the right-hand operand. [web:122][web:125][web:128]

### Example
```c
int x = 10;
x += 5;
x *= 2;
```

## Increment and Decrement Operators
- Increment and decrement operators change a value by 1. `++` increases a value, and `--` decreases a value.
- Each can be used as prefix or postfix, which changes when the update happens relative to expression evaluation. [web:113][web:116][web:119]

### Example
```c
int i = 5;
printf("%d\n", i++);
printf("%d\n", ++i);
```

## Operator Precedence
- Operator precedence determines the order in which operators are evaluated in an expression.
- Operators with higher precedence are evaluated first, and parentheses can be used to control grouping.
- In general, arithmetic operators are evaluated before relational, logical, and assignment operators. [web:114][web:117]

### Example
```c
int result = 2 + 3 * 4;   // 14, not 20
```

## Miscellaneous Operators
- C also includes a few other useful operators.
- The conditional operator `?:` is a ternary operator used for compact decision-making, and `sizeof` returns the size of
a type or variable in bytes. `,` is the comma operator, and `.` and `->` are used for structure and pointer member access. [web:112][web:117][web:121]

### Example
```c
int max = (a > b) ? a : b;
printf("%zu\n", sizeof(int));
```

## Notes
- Use parentheses when you want to make expression order explicit.
- Prefer clear expressions over overly compact chained operations.
- Be careful with prefix and postfix increment in the same expression. [web:113][web:117][web:119]
