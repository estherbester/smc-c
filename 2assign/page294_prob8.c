/*
a.  Write a function in C that takes an array of char and a char ** expression as parameters. The array of type char would contain a string the possibly starts with a sequence of decimal digits. Have the function convert the sequence of decimal digits it finds to type int and return the converted value. Have the function set the contents of its second parameter (a char * value) to point to the first character in the array that was not converted. For example, if the function was called convert () and the call to convert () was
		intval = convert (array, & charptr);

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int convert(char * digit_string, char ** ptr);


int main (void)
{
	int intval=0;  // Eventually, the integer value of the number we find
	char * string;  // String we want
	char * curr = string;  // Eventually will be pointer to first char in string that is not a digit
	char * digit_string;
	char * newptr;
	printf("Enter a string: \n");

	scanf("%s", string);
	fflush(stdin);



	printf("%p", curr);

	return 0;

}



int convert(char * digit_string, char ** ptr)
{
	int intval=0;
	int length = strlen(digit_string);
	int places;

	// example: the number 352 would begin with length = 3
	// places = 10 ^ 3
	for (length; length>0; )
	{
		places = pow(10, length--);
		intval += **ptr * places ;
		ptr++;
	}
	return intval;

}

