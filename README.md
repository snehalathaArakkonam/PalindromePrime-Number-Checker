# Palindrome and Prime Number Checker

A command-line program written in **C** that checks whether an integer is a
**palindrome**, a **prime number**, or both. It runs in a continuous loop with a
menu-driven interface until the user chooses to exit.

This project demonstrates core programming concepts: **loops** (`for` and
`while`), **conditions** (`if-else`), **switch-case** selection, and classic
**algorithms** (number reversal and primality testing).

---

## Features

### Part A — Palindrome Checker
- Takes an integer as input.
- Reverses the number using a `while` loop.
- Compares the original number with its reversed value.
- Displays **"Palindrome"** or **"Not Palindrome"**.
- Handles negative numbers by using their **absolute value** (e.g. `-121` is
  treated as `121` and is therefore a palindrome).

### Part B — Prime Number Checker
- Takes an integer as input.
- Treats any number `< 2` as **not prime**.
- Uses a `for` loop to test for divisors.
- Checks divisibility with `if (num % i == 0)`.
- Displays **"Prime"** or **"Not Prime"**.
- **Optimized** to only check divisors up to `sqrt(num)` instead of `num / 2`.

### Part C — Menu System
- Menu options: `1. Palindrome`, `2. Prime`, `3. Both`, `4. Exit`.
- Uses a `switch-case` statement for selection.
- **Continuous mode**: keeps running until the user selects *Exit*.

---

## Algorithms Explained

### Palindrome Algorithm

A palindrome reads the same forwards and backwards. To check a number, we
reverse its digits and compare the result with the original.

```c
int reverse = 0, temp = num;
while (temp > 0) {
    reverse = reverse * 10 + temp % 10;  // append the last digit
    temp = temp / 10;                    // drop the last digit
}
if (reverse == num)  // Palindrome
```

**How it works** (using `121`):

| Step | `temp` | `temp % 10` (digit) | `reverse` |
|------|--------|---------------------|-----------|
| 1    | 121    | 1                   | 1         |
| 2    | 12     | 2                   | 12        |
| 3    | 1      | 1                   | 121       |
| End  | 0      | —                   | 121       |

Since `reverse (121) == num (121)`, the number is a **palindrome**.

Negative numbers are converted with `abs()` before reversal, so the sign does
not affect the result.

### Prime Algorithm

A prime number is a whole number greater than 1 whose only divisors are 1 and
itself.

```c
if (num < 2)              // Not Prime
int limit = sqrt(num);
for (i = 2; i <= limit; i++) {
    if (num % i == 0)     // divisor found -> Not Prime
        return 0;
}
return 1;                 // Prime
```

**Why check only up to `sqrt(num)`?**
If a number `n` has a divisor larger than its square root, the matching factor
must be smaller than the square root and would already have been found. So
testing up to `sqrt(num)` is sufficient and much faster for large numbers.

---

## Project Structure

```
.
├── number_checker.c   # Complete source code
├── README.md          # This file
└── Makefile           # Build instructions
```

---

## Build and Run

### Using the Makefile
```bash
make            # compile the program
./number_checker   # run it (Windows: number_checker.exe)
make clean      # remove the compiled binary
```

### Manual compilation
```bash
gcc number_checker.c -o number_checker -lm
```

> **Note:** the `-lm` flag links the math library, which is required for the
> `sqrt()` function used in the prime check.

---

## Test Cases

### Palindrome
| Input | Expected Output  |
|-------|------------------|
| 121   | Palindrome       |
| 123   | Not Palindrome   |
| 7     | Palindrome       |
| -121  | Palindrome (absolute value) |

### Prime
| Input | Expected Output |
|-------|-----------------|
| 7     | Prime           |
| 10    | Not Prime       |
| 1     | Not Prime       |
| 17    | Prime           |
| 2     | Prime           |

---

## Concepts Used
- **Loops:** `while` loop (number reversal), `for` loop (prime check).
- **Conditions:** `if-else` for comparisons and validation.
- **Switch-case:** menu selection.
- **Functions:** `checkPalindrome()`, `checkPrime()`, `displayMenu()`.
- **Algorithms:** digit reversal and optimized primality testing.
