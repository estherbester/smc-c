/*

Project Credit Card

TODO: document

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


void validate_cc_length(char * number);
void validate_card_type(char * number);
int run_luhn_algorithm(char * number);
int double_every_even_digit (char * number);
int sum_two_digits(int number);
int add_odd_digits (char * number);
void check_digits (char * number);
int char_to_int(char character);
void debug(int error_code, char * message);



/*
    Gets credit card input from command line

    Validates length, digit, and credit card type. If any of these checks fails, program exits.

    Validates legitimacy of number using Luhn algorithm.
*/
void main (int argc, char * argv[])
{
	if (argc < 2) {
		debug(1, "Please enter a credit card number");
	}

    int valid = 1; // Set a default of 1 which presents card as "invalid"
    char * cc_number = argv[1];

	printf("You entered: %s", cc_number);

    // Check length of credit card number
    validate_cc_length(cc_number);

    // Check that each character inputted is a digit
    check_digits(cc_number);

    // Check number type
	validate_card_type(argv[1]);

    // Check Luhn which gives us the checksum % 10
    valid = run_luhn_algorithm(argv[1]);

    if (valid == 0)
        { debug(0, "Card is valid!" ); }
    else
        { debug(0, "Card is not valid. You are trying to commit fraud!!!"); }

}


/*
    Check the length of the credit card number entered.
    Must be between 13-16 characters

    param {char *} Credit card number as n-digit string
*/
void validate_cc_length(char * number)
{
    int min_length = 13,
   	    max_length = 16,
	    cc_length = strlen(number);
    char error_msg[50];

    sprintf(error_msg, "Number is %lu digits long", strlen(number));
    debug(0, error_msg);

    // Number must have more digits than the minimum, fewer than the maximum
	if (cc_length < min_length || cc_length > max_length)
    {
		debug(1, "Number is not the right length");
    }
}


/*
    Check the start of the credit card number and see if it matches
    any of the known credit card companies

    param {char *} Credit card number as n-digit string
*/
void validate_card_type(char * number)
{
    int card_type,
        first_number = char_to_int(number[0]);

    char * types[] = { "Visa",
                       "Mastercard",
                       "Discover",
                       "American Express" },
            debug_msg[50];

    switch (first_number)
    {
        case 4:
            card_type = 0;
            break;
        case 5:
            card_type = 1;
            break;
        case 6:
            card_type = 2;
            break;
        // AmEx cards must begin with "37"
        case 3:
            if (number[1] == '7')
            {
                card_type = 3;
            }
            else
            {
                debug(1, "Number does not begin with valid prefix");
            }
            break;
        default:
            debug(1, "Number does not begin with a valid digit");
	}
    sprintf(debug_msg, "Your card: %s.\n", types[card_type]);
    debug(0, debug_msg);
}


/*
    This function calls each step of the Luhn Algorithm.

    param {string} Credit card number
    return {int} The result of the Luhn checksum % 10

*/
int run_luhn_algorithm(char * number)
{
    int valid = 0,
        sum = 0;

    char debug_msg[50];

	// Run Steps 1 and 2 of the Luhn Algorithm
	sum += double_every_even_digit(number);

	// Run Step 3
	sum += add_odd_digits(number);

    sprintf(debug_msg, "Final sum after adding every odd-position digit: %i\n", sum);
    debug(0, debug_msg);

    // Run Step 4
    return sum % 10;

}


/*
    This function returns the sum of the doubled value of every other digit.
    If the doubled digit is a two-digit number, find the sum of each digit.

    param {string} Credit card number
    return {int} Sum of every other digit, doubled.
*/
int double_every_even_digit (char * number)
{
	int i,
        digit,
        doubled_digit,
        sum = 0;

	for (i = strlen(number)-2; i >= 0; i-=2)
	{
		digit = char_to_int(number[i]);

		doubled_digit = digit * 2;

		// if doubling gives us a 2-digit number we have to break it down;
        // since the double_digit will never be greater than 18 we'll just do this.
		sum += sum_two_digits(doubled_digit);  // add the ones digit
	}
	return sum;
}


/*
    Given a two-digit number, return the sum of its digits

*/
int sum_two_digits(int number)
{
    int sum = 0,
        ones_digit = 0;

    ones_digit = number % 10;

    sum += ones_digit;
    sum += (number - ones_digit)/10;

    return sum;

}


/*
    Luhn Algorithm Step 3: Add all digits in odd places from right to left

    param {string} credit card number
    return {int} sum of the odd digits

*/
int add_odd_digits (char * number)
{
    int i, sum = 0;

    for (i = strlen(number)-1; i >= 0; i-=2)
    {
        sum += char_to_int(number[i]);
    }

    return sum;
}


/*
    Given a string, check each character in the string to see if it is a digit
*/
void check_digits (char * number)
{
    int i = 0;

    while (number[i] != '\0')
    {
        if (!isdigit(number[i]))
        {
            debug(1, "Invalid card number: non-digit found");
        }
        i++;
    }
}


/*
     Given a char representing a numeral, return the number value of the char
*/
int char_to_int(char character)
{
    if (character >= '0' && character <= '9' )
    {
        return character - '0';
    }
    else
    {
        debug(1, "Invalid character given");
    }
}

/*
    Called when any errors are raised in the program.

    param {int} Error code -- 1 makes you exit. Anything else does nothing.
    param {char *} Error message

*/

void debug(int error_code, char * message)
{
    printf("\n");
    switch (error_code)
    {
        case 1:
        {
            printf("Error: %s. Exiting now.", message);
            exit(1);
        }
        case 0:
        {
            printf("%s", message);
            break;
        }
    }
    printf("\n");

}
