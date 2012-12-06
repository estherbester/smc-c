/*
Page 248/Prob. 6
6. Write a menu-driven mini-statistics package. A user should be able to enter up to
200 items of float data.  The program should calculate the number of items in the data,
the mean, the standard deviation, the variance, the median, and the mode of the data.
A sample run follows.

The symbol <EOF> in the sample run below should be replaced with CTRL-Z or CTRL-D
or the end-of-file symbol on your system.

*/



#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 200

void print_menu(void);
int get_menu_input(void);
void exit_program(void);
void clear_buffer(void);
void display_user_data(double *);
void get_user_data(double *);

double get_data_sum(double *);
double calculate_highest(double *);
double calculate_lowest(double *);
double calculate_mean(double *);
double calculate_median(double *);
double calculate_mode(double *);
double calculate_variance(double *);
double calculate_std_dev(double *);

int main(void)
{

    // Our array can hold a max of 200 data items.
    double data[MAX_ITEMS];

    // Pointer which will keep track of array index at all times. Initialized to data[0]
    double * data_tracker = data;
    int choice = 3;  // Default to always uitting


    // We basically display the menut over and over until user exits.
    while (1)
    {
        print_menu();
        choice = get_menu_input();

        // now run the function represented by that choice
        switch (choice)
        {
            case 1:
                get_user_data(data);
                break;
            case 2:
                display_user_data(data);
                break;
            case 3:
                exit_program();
            default:
                printf("\nUnknown command. ");
                exit_program();
        }
    }

    return 0;
}

void exit_program(void)
{
    printf("Quitting now. Bye!\n");
    exit(0);
}

void print_menu (void)
{
    printf("\n");
    printf("========== MENU ==========\n");
    printf("Choose from the following:\n");
    printf("==========================\n");
    printf("1: Enter data.");
    printf("\n");
    printf("2: Display data:\n");
    printf("\tNumber of items\n\tHighest value\n\tLowest value\n\tMean\n\tMedian\n\tMode\n\tVariance\n\tStandard Deviation");
    printf("\n");
    printf("3: Quit.");
    printf("\n");

    printf("Your choice: ");
}

/*
    Gets user's input, returns {int} corresponding to command to run.
*/
int get_menu_input(void)
{
    int choice;

    scanf("%i", &choice);
    fflush(stdout);

    // If the user cancels, it's the same as quitting.
    if (choice == EOF) {
        choice = 3;
    }

    printf("You chose command: %i\n", choice);
    return choice;

}

// Get data
void get_user_data(double array[])
{
    int i = 0;
    double * local_pointer = array;
    double data_point;
    printf("Enter one data item at every prompt, pressing <Enter> after each data item for the next prompt.\n\nSignal with <Ctrl-D> when you are done with data input.\n");

    while (scanf("%lf", &data_point) != EOF && i < 200 )
    {
        *local_pointer = data_point;
    }
}

/*
    Given an array of floating point numbers, calculate the various stats and
    display them.
*/
void display_user_data(double * array)
{
    double  sum = 0,
            highest,
            lowest,
            mean,
            median,
            mode,
            variance,
            std_dev;
    char c;  // dummy character to keep the screen on the stats.

    sum = get_data_sum(array);
    highest = calculate_highest(array);
    lowest = calculate_lowest(array);
    mean = calculate_mean(array);
    median = calculate_median(array);
    mode = calculate_mode(array);
    variance = calculate_variance(array);
    std_dev = calculate_std_dev(array);

    printf("\n2. Display Data Stats:\n");
    printf("----------------------");
    printf("\n%10s\t%4.4lf","Sum:", sum);
    printf("\n%10s\t%4.4lf","Highest:", highest);
    printf("\n%10s\t%4.4lf","Lowest:", lowest);
    printf("\n%10s\t%4.4lf","Mean:", mean);
    printf("\n%10s\t%4.4lf","Median:", median);
    printf("\n%10s\t%4.4lf","Mode:", mode);
    printf("\n%10s\t%4.4lf","Variance:", variance);
    printf("\n%10s\t%4.4lf","Std_dev:", std_dev);
    printf("\n----------------------");
    printf("\n");
    printf("Press CTRL+Z to continue ");
    while (scanf("%c", &c) != EOF);
    printf("\n\n");

}

/*
    TODO:
    1. Given the array in params,
    2. Traverse the array and calculate the sums with their respective formulae
    3. Return the calculated values
*/
double get_data_sum(double * array)
{
    return array[0];
}

double calculate_highest(double * array)
{
    return array[0];
}

double calculate_lowest(double * array)
{
    return array[0];
}

double calculate_mean(double * array)
{
    return array[0];
}

double calculate_median(double * array)
{
    return array[0];
}

double calculate_mode(double * array)
{
    return array[0];
}

double calculate_variance(double * array)
{
    return array[0];
}

double calculate_std_dev(double * array)
{
    return array[0];
}


