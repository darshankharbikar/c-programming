## Decision Making in C
- Decision-making statements control the flow of execution based on conditions.
- They allow a program to choose between different actions depending on whether an expression evaluates to true or false. [web:132][web:139][web:141]

### Main Decision-Making Statements
- `if` statement.
- `if-else` statement.
- `if-else-if` ladder.
- Nested `if`.
- `switch` statement.
- Nested `switch`.
- `switch` with ranges or grouped cases. [web:132][web:139][web:137]

## if Statement
- The `if` statement executes a block only when the condition is true.
- It is the simplest decision-making construct in C and is used when you want to perform an action only under a specific condition. [web:132][web:133]

### Syntax
```c
if (condition) {
    // statements
}
```

### Example
```c
if (age >= 18) {
    printf("Adult\n");
}
```

## if-else Statement
- The `if-else` statement chooses between two alternative blocks.
- If the condition is true, the `if` block runs; otherwise, the `else` block runs. [web:132][web:133]

### Syntax
```c
if (condition) {
    // statements if true
} else {
    // statements if false
}
```

### Example
```c
if (age >= 18) {
    printf("Adult\n");
} else {
    printf("Minor\n");
}
```

## if-else-if Ladder
- The `if-else-if` ladder is used when multiple conditions must be checked in order.
- The first true condition executes, and the remaining conditions are skipped. [web:132][web:139][web:133]

### Syntax
```c
if (condition1) {
    // block 1
} else if (condition2) {
    // block 2
} else if (condition3) {
    // block 3
} else {
    // default block
}
```

### Example
```c
if (marks >= 90) {
    printf("A\n");
} else if (marks >= 75) {
    printf("B\n");
} else if (marks >= 60) {
    printf("C\n");
} else {
    printf("D\n");
}
```

## Nested if
- A nested `if` means an `if` statement inside another `if` statement.
- It is useful when a decision depends on more than one condition being satisfied in sequence. [web:132][web:136][web:138]

### Example
```c
if (age >= 18) {
    if (hasID) {
        printf("Allowed\n");
    }
}
```

## switch Statement
- The `switch` statement selects one block from many based on an expression value.
- It is especially useful when comparing one variable against many fixed values.
- `break` is commonly used to stop execution after a matching case. [web:134][web:137][web:140]

### Syntax
```c
switch (expression) {
    case value1:
        // statements
        break;
    case value2:
        // statements
        break;
    default:
        // statements
}
```

### Example
```c
switch (day) {
    case 1:
        printf("Monday\n");
        break;
    case 2:
        printf("Tuesday\n");
        break;
    default:
        printf("Invalid day\n");
}
```

## Nested switch
- A nested `switch` means a `switch` statement inside another `switch` or inside a case block.
- It is used when one selection depends on another selection after the first value is known. [web:135][web:137][web:140]

## switch with Ranges
- C `switch` normally matches exact case values, but range-like behavior can be simulated by grouping multiple case labels to one block.
- This is useful when several values should trigger the same action. [web:137][web:140]

### Example
```c
switch (grade) {
    case 'A':
    case 'B':
        printf("Good\n");
        break;
    case 'C':
        printf("Average\n");
        break;
    default:
        printf("Try again\n");
}
```

## Notes
- Use `if-else` and `if-else-if` when conditions are based on expressions or ranges.
- Use `switch` when comparing one variable against many fixed values.
- Always include `break` in `switch` cases unless fall-through is intended. [web:134][web:137][web:139]
