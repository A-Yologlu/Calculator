#include <stdio.h>
#include "functions.h"
#include <stdbool.h>
#include <math.h>

/// Asks the user to enter a valid operator, and returns the operator.
/// Valid operators are: +, -, *, /, ^ (exponentiation)
/// If the user enters an invalid operator, the user is asked again until a valid operator is entered.
/// @return The operator entered by the user.
char read_operator(void) {
    char operator;
    while (true) {
        printf("Please enter an operator: ");
        scanf(" %c", &operator);
        if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '^') {
            return operator;
        } else {
            printf("Invalid choice! Try again.\n");
        }
    }
}


/// Returns the result of applying the given operator to the given numbers.
/// @param number1 The first number.
/// @param number2 The second number.
/// @param operator The operator.
/// @return The result of applying the operator to the two numbers.
float apply_operator(float number1, float number2, char operator) {
    if (operator == '+') {
        return number1 + number2;
    } else if (operator == '-') {
        return number1 - number2;
    } else if (operator == '*') {
        return number1 * number2;
    } else if (operator == '/') {
        return number1 / number2;
    } else {
        return pow(number1, number2);
    }
}

/// Asks the user whether they want to perform another calculation, and returns true if the user wants to perform another calculation, and false otherwise.
/// @return true if the user wants to perform another calculation, and false otherwise.
bool perform_another_calculation(void) {
    char answer;
    while (true) {
        printf("Would you like to perform another calculation? (y/n): ");
        scanf(" %c", &answer);
        if (answer == 'y') {
            return true;
        } else if (answer == 'n') {
            return false;
        } else {
            printf("Invalid input! Please choose 'y' or 'n' : ");
        }
    }

}

/// This is the executeable program :
int main(void) {

    do {
        float number1, number2;

        printf("Please enter the first number: ");
        scanf(" %f", &number1);
        printf("Please enter the second number: ");
        scanf(" %f", &number2);

        char operator = read_operator();
        float result = apply_operator(number1, number2, operator);

        printf("%.4f %c %.4f = %.4f\n", number1, operator, number2, result);

    } while (perform_another_calculation());

    printf("Goodbye!\n");

    return 0;
}