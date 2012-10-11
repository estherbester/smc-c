/*

Largest Int

Esther Nam
CS 50 TuTh
Fall 2012

Given a series of integers, with the last number in the sequence being 0, return the largest number and the frequency of the largest number.

*/

#include <stdio.h>

#define END_CHAR 0


// Given an integer, the running max, and the running max_count,
// determine whether the number is bigger than the current max.
void stat_number (int number, int * max, int * max_count)
{
    // If the number is greater than max, assign it to max and reset count to 1.
    if (number > *max) {
        *max = number;
        *max_count = 1;  // Need to reset the max_count to this new max.
    }

    // If the number is equal to max, increment count by 1.
    else {
        if (number == *max) {
            *max_count += 1;
        }
    }
}

int main (void)
{
    int max,
        max_count=0, // Initialize the max count
        number,
        initialized = 0;

     printf("Enter a series of numbers, whitespace-separated. Enter '0' as the last number: ");

     // User inputs numbers, which we read until they hit "Enter"
     while (scanf("%d", &number) != '\n') {

        // This block will only be evaluated the first time main() is processed.
        if (initialized == 0) {
            // The first number that is inputted is set to the max by default.
            max = number;
            initialized = 1;
        }

        // If the value is 0, we know to stop.
        if (number != END_CHAR) {
            stat_number(number, &max, &max_count);}
        else
        {
            break; // They signaled to stop! Quit the loop
        }
     }

     // Output the results: the max and the max_count
    printf("\nThe largest number is %d", max);
    printf("\nThe occurrence of the largest number is %d\n", max_count);

    return 0;
}
