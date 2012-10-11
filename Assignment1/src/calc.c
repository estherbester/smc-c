/*

Calculator

Esther Nam
CS 50 TuTh
Fall 2012

Turn on the calculator;
Enter a series of operations.
To finish, enter "R" or "r"
Calculator will return result and then start again.
*/

#include <stdio.h>

double get_input(void);
void clear_buffer(void);
double make_calculation(char, double, double );


int main (void){
    double result = 0.0; // Initialize result.
    int go_again = 'y';  // Flag to determine whether to keep running calculator

    printf("Calculator is on! \n");
    printf("Enter an operator and the number like this: +5.0\n");
    printf("Enter 'R' to quit.\n");

    do {
        printf("\nCalculator is clear.\n");

        // Start calculator, which will eventually return the ultimate result.
        result = get_input();
        clear_buffer();

        printf("\nFinal result: %.2lf\n", result);

        // Ask if user wants to go another round.
        printf("\nAgain? (y/n):");

        go_again = getchar();
        clear_buffer(); // I'm sure there's a better way to get clean input

    } while (go_again != 'n');  // User can enter anything but 'n' to keep going =P

    printf("Calculator is off. Bye!\n");
    return 0;
}

/*
Gets input from the user, calls the make_calculation function and prints result
Returns the overall result.
*/
double get_input(void){
    char operand;

    double  result = 0.0,
            num = 0.0;

    do {
        printf("Result = %.2lf\n", result);

        // Get the operator or quit command from the user.
        operand = getchar();

        if (operand == 'r' || operand == 'R')
            // Leave the loop!
            return result;

        // Now get the number from the user
        scanf("%lf", &num);
        clear_buffer();

        result = make_calculation(operand, num, result);
        printf("\nresult %c %.2lf = %.2lf\n", operand, num, result );

    } while (1);  // This loop runs until the user hits "R"

}


// Uses switch to determine which arithmetic operation to run.
// Returns the result of the operation.
double make_calculation(char operand, double num, double result) {
    // if we recognize the operand, run the desired operation
    switch (operand){
            case '+':
                return result + num;
            case '-':
                return result - num;
            case '*':
                return result * num;
            case '/':
                return result/num;
            default:
                printf("%c is an unknown operation.\n Re-enter your last line:", operand);
                return result; // No change
    }
}


// To clear the input buffer
void clear_buffer(void)
{
    while(getchar() != '\n');
}
