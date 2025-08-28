/*
 ============================================================================
 File: calculator.c
 Description: A simple command-line calculator in C.
 This program takes a mathematical expression as three command-line
 arguments and prints the result.
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h> // Required for atof()
#include <string.h> // Required for strcmp()

// --- Main Function ---
// The program starts execution here.
// argc (argument count) is the number of strings on the command line.
// argv (argument vector) is an array of pointers to these strings.
int main(int argc, char *argv[]) {

    // --- 1. Argument Validation ---
    // We expect exactly 4 arguments:
    // argv[0]: The program name (e.g., "./calculator")
    // argv[1]: The first number (e.g., "10")
    // argv[2]: The operator (e.g., "+")
    // argv[3]: The second number (e.g., "5")
    if (argc != 4) {
        printf("Error: Incorrect usage.\n");
        printf("Usage: ./calculator <number1> <operator> <number2>\n");
        printf("Example: ./calculator 10 + 5\n");
        return 1; // Return a non-zero value to indicate an error
    }

    // --- 2. Parsing Arguments ---
    // Convert the string arguments to floating-point numbers.
    // atof() ("ASCII to float") handles both integers and decimals.
    double num1 = atof(argv[1]);
    char* operator = argv[2];
    double num2 = atof(argv[3]);
    double result;

    // --- 3. Performing Calculation ---
    // We check the operator string to decide which calculation to perform.
    // A switch statement is not ideal for strings in C, so we use if-else if.

    if (strcmp(operator, "+") == 0) {
        // Addition
        result = num1 + num2;
    } else if (strcmp(operator, "-") == 0) {
        // Subtraction
        result = num1 - num2;
    } else if (strcmp(operator, "*") == 0) {
        // Multiplication
        result = num1 * num2;
    } else if (strcmp(operator, "/") == 0) {
        // Division
        // We must check for division by zero, which is an invalid operation.
        if (num2 == 0) {
            printf("Error: Division by zero is not allowed.\n");
            return 1; // Exit with an error
        }
        result = num1 / num2;
    } else {
        // Handle unsupported operators
        printf("Error: Invalid operator '%s'.\n", operator);
        printf("Supported operators are: +, -, *, /\n");
        return 1; // Exit with an error
    }

    // --- 4. Displaying the Result ---
    // Print the final result to the console.
    // %g is used to print floating-point numbers neatly (it removes trailing zeros).
    printf("Result: %g %s %g = %g\n", num1, operator, num2, result);

    return 0; // Return 0 to indicate successful execution
}
