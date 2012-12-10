/*
a.  Write a function in C that takes an array of char and a char ** expression as parameters.
The array of type char would contain a string the possibly starts with a sequence of decimal digits.

 Have the function convert the sequence of decimal digits it finds to type int and return the converted value.

 Have the function set the contents of its second parameter (a char * value) to point to the first character in the array that was not converted.
 For example, if the function was called convert () and the call to convert () was
		intval = convert (array, & charptr);

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char * get_digits_from_string(char *, char **);
int convert(char * digit_string);
void clear_buffer(void);


int main (void)
{
	int intval=0;  // Eventually, the integer value of the number we find

	char string[200];  // String we want

	char ** curr = &string;  // Pointer to first char in string that is not a digit, initialized to beginnign of string

	char * digit_string;  // We will extract the digits from the string we get and save it here to convert.

	printf("Enter a string: \n");

	scanf("%s", string);

	digit_string = get_digits_from_string(string, curr);

	intval = convert(digit_string);

	printf("Number value is %d.\n", intval);

	printf("The rest of the string is %s", *curr);
	return 0;

}


char * get_digits_from_string(char * string, char ** curr)
{
	int length = strlen(string);

	char * digit_string = malloc(length * sizeof(char));

	char * digit_counter = digit_string;

	// make a new string until the last digit value
	while (isdigit(*(string)))
	{
		*(digit_counter++) = *string++;
	}

	digit_counter='\0'; // terminate our new string

	// Move pointer to the beginning of the non-digit part of the string
	* curr = digit_counter++;

	return digit_string;

}

int convert(char * digit_string)
{
	// example: the number 352 would begin with length = 3
	// places = 10 ^ 3
	int intvalue = 0,
		digit,
		num_digits = strlen(digit_string);

	char * current_char = digit_string;

	while (num_digits > 0)
	{
		digit = *current_char++ - '0';

		intvalue += digit * pow(10, --num_digits);
	}

	return intvalue;

}

void clear_buffer(void)
{
	while (getchar() != '\n');
}
