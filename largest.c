/*

Largest Int


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define END_CHAR 0
#define SEPARATOR ' '


// Given an integer, the running max, and the running max_count, determine
// whether the number is bigger than the current max.
void stat_number (int number, int * max, int * max_count)
{
    // If the number is greater than max, assign it to max and reset count to 1.
    if (number > *max) {
        *max = number;
        *max_count = 1;  // Need to reset the max_count to this new max.
    }
    else // If the number is equal to max, increment count by 1.
    {
        if (number == *max)
        {
            *max_count += 1;
        }
    }

}

int main (void)
{
    int max,
        max_count=0, // Initialize the max count
        number;


     printf("Enter a series of one-digit numbers, space-separated. Enter '0' as the last number: ");

     // User inputs numbers, which we read one character at a time until they hit "Enter"
     while ((number=getchar()) != '\n'){
        // 0 is the last digit so we know to stop.
        if (number != END_CHAR)
        {
            // Discount spaces
            if (number != SEPARATOR)
            {
                stat_number(number, &max, &max_count);
            }
        }

     }

     // Output the results: the max and the max_count
    printf("\nThe largest number is ");
    putchar(max);

    printf("\n");
    printf("The occurrence of the largest number is %d\n", max_count);

    return 0;
}
