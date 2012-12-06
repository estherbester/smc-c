
/*

 a. Write a C function that will input values into an array of type int. Have the array and the number of elements in the array passed as parameters to your function. Use a local pointer variable to traverse the array.

 b. Write a C function that will output the contents of an array of type int. Have the array and the number of elements in the array passed as parameters. Use a local pointer variable to traverse the array.
*/


#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void fill_array(int * array, int size);
void print_array_contents(int * array, int size);

int main (void)
{
	int * input_values;
	int size;

	printf("How many integers do you wish to enter? ");
	scanf("%d", &size);

	input_values = malloc(size * sizeof(int) + 1);

	// Pass the array and number of elements as params
	fill_array(input_values, size);

	print_array_contents(input_values, size);

}

// Given an array and the size of the array, fill the array with integer values
void fill_array(int * array, int size)
{
	int value,  // assign the address of array to pointer n
		i=0;

	int * pointer = array;  // local pointer variable, assigned to address of array

	printf("\nEnter up to %d integers. Hit Ctrl-D if done.\n", size);

	for (i; i<size; i++)
	{
		if (scanf("%d", &value) != EOF)
		{
			*pointer = value;
		}
		else
		{
			*pointer = '\0';
		}
		pointer++;
	}
}

// Given an array and the number of elements in the array, print the values in
// the array.
void print_array_contents(int * array, int size)
{
	int i=0; // counter for size
	int * pointer = array;  // local pointer variable

	printf("\nNow printing array contents:");
	while (i < size)
	{
		if (*pointer != '\0')
			printf("\n%d", *pointer);
		i++;
		pointer++;
	}
	printf("\n");
}
