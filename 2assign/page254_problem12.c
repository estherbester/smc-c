
/*

 a. Write a C function that will input values into an array of type int. Have the array and the number of elements in the array passed as parameters to your function. Use a local pointer variable to traverse the array.

 b. Write a C function that will output the contents of an array of type int. Have the array and the number of elements in the array passed as parameters. Use a local pointer variable to traverse the array.
*/


#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

void fill_array(int * array, int size);
void print_array_contents(int * array, int size);


int main (void)
{
	int * input_values;
	int size;

	printf("How many integers do you wish to enter? ");
	scanf("%d", &size);

	// Allocate memory for the array
	input_values = malloc(size * sizeof(int));

	// Pass the array and number of elements as params, fill array.
	fill_array(input_values, size);

	// Pass array and number of elements to print the contents.
	print_array_contents(input_values, size);

}

// Given an array and the size of the array,
// fill the array with integer values
void fill_array(int * array, int size)
{
	int value,  // This will be the input value to put into array
		i;

	int * pointer = array;  // local pointer variable, assigned to address of array

	printf("\nEnter up to %d integers (hit Ctrl-D if done):\n", size);

	for (i=0; i<size; i++)
	{
		if (scanf("%d", &value) != EOF)
		{
			// Make sure we've got an integer
			*(++pointer) = value;
		}
		else
		{
			printf("You have not filled up the array! Padding the rest of the array with zeroes\n");
			break;
		}
	}
}

// Given an array and the number of elements in the array,
// print the values in the array.
void print_array_contents(int * array, int size)
{
	int i=0;
	int * pointer = array;  // local pointer variable

	// Output a comma-separated list of the array elements
	printf("\nNow printing array contents: ");
	while (++i < size)
	{
		printf("%d, ", *(++pointer));
	}

	// Print the last array item without a comma
	printf("%d\n", *(++pointer));

}
