/*

Write a program that accepts 20 double number. Compute the largest number, the smallest, and
Compute average of all 20 numbers.

*/


#include <stdio.h>


double calc_average(array_num)
{
    double sum = 0;
    int length = len(array_num);
    /*

    for num in num
        sum += num
    */

    return sum / length;

}


int main (void){
    array array_num;
    double num1, num2;
    double largest, smallest, average;

    /* do this twenty times
        printf('Enter number 1: ');
        scanf("%lf", &num1);
        push into array
    */


    // sort the numbers to get largest, smallest
    // largest =
    // smallest =
    average = calc_average(array_num);
    printf("The largest is: %lf\n", largest);
    printf("The smallest is: %lf\n", smallest);
    printf("The average is: %lf", average);

}
