/*
Esther Nam

Get 20 double numbers
Write a program that accepts 20 double number. Compute the largest number, the smallest, and
Compute average of all 20 numbers.

*/

#include <stdio.h>

#define NUMBER_OF_NUMBERS 20


double get_number(void);

int main (void) {
    int i=0;
    double number,
           largest,
           smallest,
           total_sum = 0,
           average = 0;

    for (i=0; i < NUMBER_OF_NUMBERS; i++)
    {
        number = get_number();
        // The first time around, we will set the largest and smallest to the first number we get.
        if (i==0) {
            largest = number;
            smallest = number;
        }
        else
        {

            if (number > largest) {
                largest = number; // re-assign "largest" to this new, bigger number
            }
            if (number < smallest) {
                smallest = number; // re-assign smallest to this tinier number
            }
            total_sum += number; // keep a running sum of all the numbers
        }
    }

    // Sort the numbers to get largest, smallest
    average = (float) total_sum / NUMBER_OF_NUMBERS ;
    printf("\nYou entered %d numbers:\n", NUMBER_OF_NUMBERS);
    printf("\tThe largest is: %lf\n", largest);
    printf("\tThe smallest is: %lf\n", smallest);
    printf("\tThe average is: %lf\n", average);
}

/* Fetches user input */
double get_number(void)
{
    double number = 0;

    printf("Enter a positive number (of type double): ");
    scanf("%lf", &number);

    return number;
}
