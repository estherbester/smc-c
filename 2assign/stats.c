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

#define MAX_ITEMS 19

void print_menu(void);
void exit_program(void);
void clear_buffer(void);
void display_user_data(double *, double * data_tracker);
void get_user_data(double *, double *);
void clear_buffer(void);


double get_data_sum(double *, double *);
double calculate_highest(double * array, double * data_tracker);
double calculate_lowest(double * array, double * data_tracker);
double calculate_mean(double * array, double * data_tracker, double sum);
double calculate_median(double * array, double * data_tracker);
double calculate_mode(double * array, double * data_tracker);
double calculate_variance(double * array, double * data_tracker);
double calculate_std_dev(double * array, double * data_tracker);
void run_program(double * array, double * data_tracker);

double * sort_array(double * array, double * data_tracker);
void copy_array(double new_array_to_return[], double original_array[], int length);


void print_array(double * array, int length);



int main(void)
{
    // Our array can hold a max of 200 data items.
    double data[MAX_ITEMS];

    // Pointer which will keep track of array index at all times. Initialized to data[0]
    double * data_tracker = data;

    // Display the menu over and over until user exits.
    run_program(data, data_tracker);
    return 0;
}

void run_program(double * data, double * data_tracker)
{

    int choice;

    print_menu();
    scanf("%d", &choice);

    printf("You chose command: %d\n", choice);

    // now run the function represented by that choice
    switch (choice)
    {
        case 1:
            get_user_data(data, data_tracker);
            break;
        case 2:
            display_user_data(data, data_tracker);
            break;
        case 3:
            exit_program();
            break;  // we don't really need this
        default:
            printf("\nUnknown command. ");
            exit_program();
            break;  // we don't really need this
    }

}


void print_menu (void)
{
    printf("\n========== MENU ==========\n");
    printf("Choose from the following:\n");
    printf("==========================\n");
    printf("1: Enter data\n");
    printf("2: Display data:\n");
    printf("\tNumber of items\n\tHighest value\n\tLowest value\n\tMean\n\tMedian\n\tMode\n\tVariance\n\tStandard Deviation\n");
    printf("3: Quit.\n");

}


void exit_program(void)
{
    printf("Quitting now. Bye!\n");
    exit(0);
}


/*
    Given an array, fille the array with user-inputted float values
*/
void get_user_data(double array[], double * data_tracker)
{
    int i = 0;

    double data_point = 294.00;

    printf("Enter one data item at every prompt, pressing <Enter> after each data item for the next prompt.\n");
    printf("\nSignal with <Ctrl-D> when you are done with data input.\n");

    while (i < MAX_ITEMS )//&& scanf("%lf", &data_point) != EOF)
    {

        // DURING DEBUG
        data_point = data_point - 1.00;


        // fill the array cell denoted by data_tracker pointer with the user's value
        *data_tracker++ = data_point;
        i++;
    }
    run_program(array, data_tracker);
}

/*
    Given an array of floating point numbers, calculate the various stats and
    display them.
*/
void display_user_data(double array[], double * data_tracker)
{
    double  sum = 0,
            highest,
            lowest,
            mean,
            median,
            mode,
            variance,
            std_dev;
    double * sorted_array;
    char c;  // dummy character to keep the screen on the stats.

    sum = get_data_sum(array, data_tracker);

    // Create a new array, which contains sorted values
    sorted_array = sort_array(array, data_tracker);

    lowest = sorted_array[0];
    highest = sorted_array[data_tracker-array-1];

    mean = calculate_mean(array, data_tracker, sum);
    median = calculate_median(sorted_array, data_tracker);
    mode = calculate_mode(array, data_tracker);
    variance = calculate_variance(array, data_tracker);
    std_dev = calculate_std_dev(array, data_tracker);

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
    fflush(stdout);
    while (scanf("%c", &c) != EOF);

    printf("\n\n");

}

/*
    STAT FUNCTIONS. The following functions follow this basic model:
    1. Given the array in params,
    2. Traverse the array and calculate the sums with their respective formulae
    3. Return the calculated values
*/


// Calculate the running sum of all the items in the array
double get_data_sum(double * array, double * data_tracker)
{
    int i=0;
    double running_total = 0;
    int number_of_items = data_tracker - array;
    for (i; i<number_of_items; i++)
    {
        running_total += array[i];
    }
    printf("\nTotal number of items: %d\n", number_of_items);
    return running_total;
}

/* The following two functions are deprecated because by sorting
the array we can get the highest and lowest by calling the
last/first values of the sorted array, respectively.
*/
double calculate_highest(double * array, double * data_tracker)
{

    int i=0;
    // set default to the first number
    double current_highest = array[0];

    // Get the length of the array by subtracting the position of the last
    // data point by the first data point.
    int number_of_items = data_tracker - array;

    for (i; i<number_of_items; i++)
    {
        if (array[i] > current_highest)
            current_highest = array[i];  // Replace any higher values
    }
    return current_highest;
}

double calculate_lowest(double * array, double * data_tracker)
{
    int i=0;
    // set default to the first number
    double current_lowest = array[0];

    int number_of_items = data_tracker - array;
    for (i; i<number_of_items; i++)
    {
        if (array[i] < current_lowest)
            current_lowest = array[i];
    }

    return current_lowest;
}


double calculate_mean(double * array, double * data_tracker, double sum)
{
    int number_of_items = data_tracker - array;

    return (double) sum/number_of_items;
}


// Uses the sorted array to find the midpoint value of the data. If there is
// an even number of data points, we must return the mean of the two data points
// in the middle.
double calculate_median(double * array, double * data_tracker)
{
    int array_length = data_tracker - array;
    int median_point = array_length/2;

    print_array(array, data_tracker-array);

    if (array_length % 2)  // evaluates to True if median_point is odd
        return array[median_point];
    else
        return (double) (array[median_point]+array[median_point-1])/2;
}

double calculate_mode(double * array, double * data_tracker)
{
    return array[0];
}

double calculate_variance(double * array, double * data_tracker)
{
    return array[0];
}

double calculate_std_dev(double * array, double * data_tracker)
{
    return array[0];
}

/*
    Returns a pointer to an array representing the sorted copy of the original array
*/
double * sort_array(double * array, double * data_tracker)
{
    double * sorted_array;
    double temp;
    int number_of_items = data_tracker - array;
    int i, j;

    // Allocate memory for the new array
    sorted_array = malloc(number_of_items * sizeof(double));
    // Here we copy the array
    copy_array(sorted_array, array, number_of_items);

    // Now we sort the values. I forget which sort this is called. We did in class.
    for (i=0; i < number_of_items-1; i++)
    {
        for (j=i+1; j<number_of_items; j++)
        {
            if (sorted_array[i] > sorted_array[j])
            {
                temp = sorted_array[i];
                sorted_array[i] = sorted_array[j];
                sorted_array[j] = temp;
            }
        }

    }
/*
    printf("\nDEBUG:\n");
    printf("\nORIG:\n");
    print_array(array, number_of_items);
    printf("\nNEW:\n");
    print_array(sorted_array, number_of_items);
*/
    return sorted_array;
}


/*
    Given an array and the length of the array, copies the values into the new array
*/
void copy_array(double new_array_to_return[], double original_array[], int length)
{
    int i;

    for (i=0; i< length; i++)
    {
        new_array_to_return[i] = original_array[i];
    }

}


// For debugging
void print_array(double * array, int length)
{
    int i=0;
    while (i<length)
    {
        printf("%lf\n ", array[i]);
        i++;
    }
}
