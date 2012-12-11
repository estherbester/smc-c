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

#define EOF_KEYS "Ctrl-Z"
#define MAX_ITEMS 200

// Used to calculate the mode
struct frequency
{
    double * address;
    int count;
};

// Menu program functions
void run_program(double * array, double * data_tracker);
void print_menu(void);
void exit_program(void);
void get_user_data(double *, double *);
void display_user_data(double *, double * data_tracker);
void show_calculations(double array[], int array_length);

//void clear_buffer(void);

// Statistics functions
double get_data_sum(double * array, int length);
double calculate_mean(double sum, int length);
double calculate_median(double * array, int array_length);
double calculate_variance(double * array, int array_length, double mean);
double calculate_std_dev(double variance);
struct frequency * calculate_mode(double * array, int);
void print_mode(struct frequency mode_array[]);
// Deprecated
double calculate_highest(double * array, double * data_tracker);
double calculate_lowest(double * array, double * data_tracker);

// Helper functions
double * sort_array(double * array, int length);
void copy_array(double new_array_to_return[], double original_array[], int length);

// Used only for debugging
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
    char input[2];
    print_menu();

    fflush(stdout);
    // Get the user input as a string (we only want one char so this is safe)
    if (gets(input))
        choice = input[0]-'0';

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
            run_program(data, data_tracker);
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
    printf("Enter your choice: ");

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
    double data_point;

    printf("Enter one data item at every prompt, pressing <Enter> after each data item for the next prompt.\n");
    printf("\nSignal with <%s> when you are done with data input.\n", EOF_KEYS);

    // Make sure the data_tracker pointer is still within the bounds of the array
    while ((data_tracker - array) < MAX_ITEMS && (scanf("%lf", &data_point) != EOF))
    {
        // fill the array cell denoted by data_tracker pointer with the user's value
        *data_tracker++ = data_point;
    }
    run_program(array, data_tracker);
}


// Determine whether to display statistics, or handle when there
// has not been any data entered yet.
void display_user_data(double array[], double * data_tracker)
{
    int array_length = data_tracker - array;

    if (array_length == 0)
    {
        printf("\nData has not been entered!");
    }
    else
    {
        show_calculations(array, array_length);
    }
    run_program(array, data_tracker);

}


/*
    Given an array of floating point numbers, calculate the various stats and
    display them.
*/
void show_calculations(double array[], int array_length)
{
    double  sum = 0,
            highest,
            lowest,
            mean,
            median,
            variance,
            std_dev;
    double * sorted_array;
    struct frequency * mode;
    char c;  // dummy character to keep the screen on the stats.

    sum = get_data_sum(array, array_length);

    // Create a new array, which contains sorted values
    sorted_array = sort_array(array, array_length);

    // We can use the new, sorted array to find the next two data stats.
    lowest = sorted_array[0];
    highest = sorted_array[array_length-1];

    mean = calculate_mean(sum, array_length);
    median = calculate_median(sorted_array, array_length);
    mode = calculate_mode(sorted_array, array_length);
    variance = calculate_variance(array, array_length, mean);
    std_dev = calculate_std_dev(variance);

    printf("\n2. Display Data Stats:\n");
    printf("----------------------");
    printf("\n%10s\t%6.2lf","Sum:", sum);
    printf("\n%10s\t%6.2lf","Highest:", highest);
    printf("\n%10s\t%6.2lf","Lowest:", lowest);
    printf("\n%10s\t%6.2lf","Mean:", mean);
    printf("\n%10s\t%6.2lf","Median:", median);
    printf("\n%10s\t","Mode(s):");
    print_mode(mode);
    printf("\n%10s\t%6.2lf","Variance:", variance);
    printf("\n%10s\t%6.2lf","Std_dev:", std_dev);
    printf("\n----------------------");
    printf("\nNumber of items: %d\n", array_length);
    printf("\nPress <%s> to continue ", EOF_KEYS);
    printf("\n\n");
    fflush(stdout);
    while (scanf("%c", &c) != EOF);

}



 /*
     STATISTICS FUNCTIONS. The following functions follow this basic model:
     1. Given the array in params,
     2. Traverse the array and calculate the sums with their respective formulae
     3. Return the calculated values
 */

// Given the array values, calculate and return the running total.
double get_data_sum(double * array, int number_of_items)
{
    int i=0;
    double running_total = 0;
    for (i; i<number_of_items; i++)
    {
        running_total += array[i];
    }
    return running_total;
}


double calculate_mean(double sum, int number_of_items)
{
    return (double) sum/number_of_items;
}

/*
   Uses the sorted array to find the midpoint value of the data. If there is
   an even number of data points, we must return the mean of the two data points
   in the middle.
*/
double calculate_median(double * array, int array_length)
{
    int median_point = array_length/2;

    if (array_length % 2)  // evaluates to True if median_point is odd
        return array[median_point];
    else  // this means median_point is even
        return (double) (array[median_point]+array[median_point-1])/2;
}


/*
    To find the mode, we have to keep track of the frequency of every value in our array.
    We will traverse our data array, and create an array of pointers to help us record
    each time we encounter a new value

    To make things easier we will use the sorted array so that equal values appear in succession.

    (struct definition copied here for reference)
    struct frequency
    {
        double * address;
        int count;
    };

*/
struct frequency * calculate_mode(double * sorted_array, int array_length)
{
    // Potentially every number is a mode, e.g. if each number is unique!
    struct frequency * mode_array = malloc((sizeof(struct frequency)) * array_length);
    struct frequency * current_counter = mode_array;  // Start our tracker at the beginning

    int i=0,
        highest_frequency=0;

    // Initialize our tracker array, mode_array, with the first value from our params
    current_counter->address = sorted_array;
    current_counter->count=1;

    do
    {
        // If the current array value being tested matches the last item in our tracker array,
        // then increment that item's counter
        if (*(++sorted_array) == *(current_counter->address))
        {
            (current_counter->count)++;
        }
        else  // If it's a new value, create a new entry in the array,
              // populate it with the address of the current array value,
              // and start the counter again
        {
            current_counter++;
            current_counter->address = sorted_array;
            current_counter->count = 1;
        }

        if ((current_counter->count) > highest_frequency)
        {
            // New winner!  Put our tracker pointer back to the beginning of our
            // tracker array (we want to overwrite old value and start from zero)
            highest_frequency = current_counter->count;
            mode_array[0] = *current_counter;
        }
        i++;
    }
    while (i < array_length); // To make sure we traverse the entire data array.

    return mode_array;
}

void print_mode(struct frequency mode_array[])
{
    struct frequency * current_point = mode_array;

    // If all our data points are unique we don't want to print out all the numbers
    if (current_point->count > 1)
    {
        // Presumably the first item in our mode_array is the value that occurs
        // with the most frequency. Keep traversing our mode_array until we
        // get to a count that is lower than the highest mode count (in case we have
        // more than one mode).
        while (current_point->count >= mode_array->count)
        {
            printf("%6.2lf (%d occurrences) ", *(current_point->address), current_point->count);
            current_point++;
            if (current_point->address == mode_array->address)  // We've already shown it! This is leftovers
                break;
        }
    }
    else
    {
        printf("All unique numbers");
    }
}


/*
   To get variance:
   1. Subtract each data point from the mean
   2. Square each of the differences
   3. Calculate the sum of the squares
   4. Divide the sum of the squares by the number of items

   Return {double} variance
*/
double calculate_variance(double * array, int array_length, double mean)
{
    double sums_of_squares=0;
    int i;

    for (i=0;i<array_length;i++)
    {
        sums_of_squares += pow(array[i]-mean, 2);
    }

    return (double) sums_of_squares/array_length;
}


// Standard deviation is just the square root of the variance
double calculate_std_dev(double variance)
{
    return pow(variance, .5);
}


/*
    Returns a pointer to an array representing the sorted copy of the original array
*/
double * sort_array(double * array, int array_length)
{
    double * sorted_array;
    double temp;
    int i, j;

    // Allocate memory for the new array
    sorted_array = malloc(array_length * sizeof(double));

    // Here we copy the array
    copy_array(sorted_array, array, array_length);

    // Now we sort the values. I forget which sort this is called. We did in class.
    for (i=0; i < array_length-1; i++)
    {
        for (j=i+1; j<array_length; j++)
        {
            if (sorted_array[i] > sorted_array[j])
            {
                temp = sorted_array[i];
                sorted_array[i] = sorted_array[j];
                sorted_array[j] = temp;
            }
        }

    }

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

/*
The following two functions are deprecated because by sorting
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
