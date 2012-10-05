/*

Largest Int


*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define END_CHAR 0
#define SEPARATOR ' '

void stat_number (int number, int * max, int * max_count)
{
    printf("Number is %d, max is %d\n", number, *max);
    if (number > *max) {
        *max = number;
        printf("New max is %d\n", *max);

    }
    else
    {
        if (number == *max)
            printf("Max is still %d\n", *max);

            { *max_count = number;}
    }

}

int main (void)
{
    int number = 1,  // initialize so that max and number go throguh the do-while loop once
        max=0,
        max_count=0,
        first_flag = 0;
    char input,
         series[] = "";

    printf("Enter a series of numbers separated by a space; enter 0 to finish: \n");

    input = getchar();

    if (input != SEPARATOR) {
        number = putchar(input);

        printf("Number: %d\n", number);

        if (first_flag == 0) { max = number; first_flag = 1;}

        //stat_number(number, &max, &max_count);

    }
    // If the input is not a space, then keep going
    // If the input is a space, process the number
    // If the char is 0, the end
    else {
        if(input == putchar('0')){
            printf("the end");
        }
        else {

        }
    }
    printf("Largest number is %d\n", max);
    printf("The occurrence of the largest number is %d\n", max_count);

    /*
     get the input:

     scanf string


     parse the input for integers:


     for each integer:
        if integer > max
            max = integer
        else
            if integer == max
                max_count++

    */

    return 0;
}
