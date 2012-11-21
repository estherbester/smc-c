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



void digit_check (int digit);

void main (int argc, char * argv[]){
	if (argc < 2) {
		printf("Please enter a credit card number");
		exit(1);
	}
	int valid;
	
	printf("\n");
	printf("You entered: %s", argv[1]);
	
	printf("\n");

    // Check length
	valid = validate_cc_length(argv[1]);
	if (valid == 0) {
		printf("Number is not the right length\n"); exit(1);
	}

    // Check type
	valid = validate_card_type(argv[1]);
	if (valid == 0) {
		printf("Number is not a valid credit card number\n"); exit(1);
	}

    // Check Luhn
    valid = run_luhn_algorithm(argv[1]);

    if (valid == 1)
        {printf("Card is valid!\n" );}
    else
        {printf("Card id not valid\n");}

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

    printf("\nNumber is %lu digits long\n", strlen(number));

	if (cc_length >= min_length && cc_length <= max_length)
	{
		valid = 1;
	}
	return valid;
}

/*
    Check the start of the credit card number and see if it matches
    any of the known credit card companies

*/
int validate_card_type(char * number)
{
    int valid = 0;

	if (number[0] == '4'            // Visa
	    || number[0] == '5'         // Mastercard
		|| number[0] == '6'         // Discover
		|| (number[0] == '3' && number[1] == '7'))  // Amex
	{
	 valid = 1;
	}
	return valid;
}

int run_luhn_algorithm(char * number)
{
    int valid = 0;
	int sum = 0;

	// step 1 and 2
	sum = double_every_other_digit(number);
	printf("Sum of Step 1 and 2: doubling digits: %i\n", sum);  
    
	// step 3
	sum += add_odd_digits(number);
	printf("Final sum after adding every odd digit: %i\n", sum);  

	// step 4
	if (sum % 10 == 0) 
	{
		valid = 1;
	}

    return valid;

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

        printf("%c", number[i]);
		digit = number[i] - '0';
        
        digit_check(number[i]);

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


void digit_check (int digit) {
    if (!isdigit(digit))
    {
			printf("\nCannot double digits: non-digit found: %i\n)", digit);
			exit(1);
    }
    
}


/*
    Luhn Algorithm Step 3: Add all digits in odd places from right to left
*/
int add_odd_digits (char * number)
{
    int sum = 0;
    int i;

    for (i = strlen(number); i > 0; i-=2)
    {
        digit_check(number[i]);
        sum += number[i];
    }

    return sum;
}

