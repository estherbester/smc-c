/*

Project Credit Card

Use Luhn algorithm to check the validity of certain credit card numbers.

1. get input
2. validate type
3. validate length
4. validate start character
5. run Luhn algorithm
6. print result: valid or invalid?

*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



int main (int argc, char * argv[]){
	if (argc < 2) {
		printf("Please enter a credit card number");
		exit(1);
	}
	int valid;
	
	printf("\n");
	printf("You entered: %s", argv[1]);
	
	printf("\n");

	valid = validate_cc_length(argv[1]);
	if (valid == 0) {
		printf("Number is not the right length\n"); exit(1);
	}
	valid = validate_card_type(argv[1]);
	if (valid == 0) {
		printf("Number is not a valid credit card number\n"); exit(1);
	}
}


/*
    Check the length of the credit card number entered.
    Must be between 13-16 characters
*/

int validate_cc_length(char * number)
{
    int min_length = 13, 
   	    max_length = 16,
	    cc_length = strlen(number),
	    valid = 0;

	if (cc_length >= min_length && cc_length <= max_length)
	{
		valid = 1;
	}
	return valid;
}

int validate_card_type(char * number)
{
    int valid = 0;

	if (number[0] == '4' 
	    || number[0] == '5'
		|| number[0] == '6' 
		|| (number[0] == '3' && number[1] == '7')) 
	{
	 valid = 1;
	}
	return valid;
}

int run_luhn_algorithm(char * number)
{
    int valid;
	int sum = 0;
	// step 1
	sum = double_every_other_digit(number);
	printf(sum);  
	// step 2
//	sum += add_odd_digits(number);

	// final check
/*	if (sum % 10 == 0) 
	{
		valid = 1;
	}

return valid;
*/
}

void print_error_message(){

}


int double_every_other_digit (char * number)
{
	int sum = 0;
	int i;
	int digit, double_digit;
	for (i = strlen(number); i > 0; i-=2)
	{
		digit = number[i] - '0';
		if (!isdigit(digit))
		{
			printf("Value wrong (double every other digit failed)");
			exit(1);
		}

		double_digit = digit * 2;

		// if doubling gives us a 2-digit number we have to break it down  
		if (double_digit > 9)
		{
		    sum += double_digit/10;  // add the first digit in our 2-digit number
			sum += double_digit%10;  // add the ones digit
		}
		else
		{
			sum += double_digit;
		}
		
	}
	return sum;
}

int add_odd_digits (char * number)
{


}

