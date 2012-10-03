/*

Esther Nam
CS 50 TuTh
Fall 2012

Lottery
Generates a two digit lottery number, asks user to guess a two-digit number.
1.  If the user matches the lottery in exact order , the awards is $10,000.
2.  If the user input matches the lottery, the awards is $3,000.
3.  If one digit in the user input matches a digit in the lottery, the awards is $1,000.

*/


#include <stdio.h>
#include <libc.h>

#define EXACT_MATCH "$10,000"
#define BOTH_MATCH "$3,000"
#define ONE_MATCH "$1,000"


void lottery(int);

void check_prize(int, int, int);


int main(void) {
   int guess=0;

	printf("Guess a two-digit number: ");
	scanf("%d", &guess);

    // Make sure the guess is a two-digit number
    if (guess > 99 || guess < 10) {
	    printf( "Invalid guess! \n");
	}
    else
    {
	    lottery(guess);
	}
	return 0;
}

/* Generate the random number and prints the guess and the lottery numbers */
void lottery(int guess) {

    int random_number1,
        random_number2;

    // Generate the lottery number
    srand(time(NULL));
    random_number1 = rand() % 9 + 1;
    random_number2 = rand() % 9 + 1;

    // Show the lottery number
    printf("You guessed: %d\n", guess);
    printf("Lottery number is: %d%d\n", random_number1, random_number2);

    check_prize(guess, random_number1, random_number2);
}

/* Print the result of the lottery */
void check_prize(int guess, int random_number1, int random_number2)
{

   int digit1 = guess/10, // get the first digit from the guess
       digit2 = guess%10; // get the second digit from the guess

    // Now to check each digit
    if (digit1 == random_number1 && digit2 == random_number2){
        printf ("Perfect match - you win %s!!", EXACT_MATCH);
    }
    else {

        /* Since we already checked the first condition
           we just need to check if the opposites match */
        if (digit2 == random_number1 && digit1 == random_number2){
           printf("You got both digits right, though not in order - you win %s", BOTH_MATCH);
        }
        else
        {
            /* If one of the digits matches */
            if (digit1 == random_number1 ||
                digit1 == random_number2 ||
                digit2 == random_number1 ||
                digit2 == random_number2)
            {
                printf("You matched one digit -- you win %s!", ONE_MATCH);
            }
            else
            {
                printf("Nice try but no dice");
            }
        }
    }
    printf("\n");
}

