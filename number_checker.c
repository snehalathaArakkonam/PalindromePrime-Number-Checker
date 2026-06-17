#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Function prototypes */
int checkPalindrome(int num);
int checkPrime(int num);
void displayMenu(void);

int main(void)
{
    int choice, number;
    int running = 1;

    while (running) {
        displayMenu();
        printf("Enter your choice: ");

        /* Validate that an integer was entered */
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n\n");
            /* Clear the invalid input from the buffer */
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (choice) {
        case 1: /* Palindrome only */
            printf("Enter an integer: ");
            scanf("%d", &number);
            if (checkPalindrome(number))
                printf("Result: %d is a Palindrome.\n\n", number);
            else
                printf("Result: %d is Not a Palindrome.\n\n", number);
            break;

        case 2: /* Prime only */
            printf("Enter an integer: ");
            scanf("%d", &number);
            if (checkPrime(number))
                printf("Result: %d is a Prime number.\n\n", number);
            else
                printf("Result: %d is Not a Prime number.\n\n", number);
            break;

        case 3: /* Both checks */
            printf("Enter an integer: ");
            scanf("%d", &number);

            if (checkPalindrome(number))
                printf("Palindrome Check: %d is a Palindrome.\n", number);
            else
                printf("Palindrome Check: %d is Not a Palindrome.\n", number);

            if (checkPrime(number))
                printf("Prime Check: %d is a Prime number.\n\n", number);
            else
                printf("Prime Check: %d is Not a Prime number.\n\n", number);
            break;

        case 4: /* Exit */
            printf("Exiting the program. Goodbye!\n");
            running = 0;
            break;

        default:
            printf("Invalid choice. Please select 1-4.\n\n");
            break;
        }
    }

    return 0;
}

/* Display the menu options */
void displayMenu(void)
{
    printf("========================================\n");
    printf("  Palindrome and Prime Number Checker\n");
    printf("========================================\n");
    printf("  1. Check Palindrome\n");
    printf("  2. Check Prime\n");
    printf("  3. Check Both\n");
    printf("  4. Exit\n");
    printf("----------------------------------------\n");
}

/*
 * Palindrome algorithm.
 * Negative numbers are handled by taking the absolute value,
 * so -121 is treated as 121.
 * Returns 1 if the number is a palindrome, 0 otherwise.
 */
int checkPalindrome(int num)
{
    int reverse = 0;
    int temp;

    /* Handle negative numbers using absolute value */
    num = abs(num);
    temp = num;

    /* Reverse the number using a while loop */
    while (temp > 0) {
        reverse = reverse * 10 + temp % 10;
        temp = temp / 10;
    }

    /* Compare original with reversed */
    if (reverse == num)
        return 1;
    else
        return 0;
}

/*
 * Prime algorithm (optimized).
 * Numbers less than 2 are not prime.
 * Checks divisibility from 2 up to sqrt(num) using a for loop.
 * Returns 1 if the number is prime, 0 otherwise.
 */
int checkPrime(int num)
{
    int i;
    int limit;

    /* Numbers less than 2 are not prime */
    if (num < 2)
        return 0;

    /* Optimization: only check divisors up to the square root of num */
    limit = (int) sqrt((double) num);

    for (i = 2; i <= limit; i++) {
        if (num % i == 0)
            return 0; /* Found a divisor, so it is not prime */
    }

    return 1; /* No divisors found, so it is prime */
}
