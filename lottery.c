#include <stdio.h>

/*
    Takes the user's guess and determines if it's the right number
	Returns higher or lower
*/
void lottery(int guess) {

    int guess1, guess2;
    // Generate the lottery number
    srand(time(NULL));
	int random_number1 = rand() % 9 + 1; 
	int random_number2 = rand() % 9 + 1; 

	// Show the lottery number 
	printf("Lottery number is: %d%d\n", random_number1, random_number2);
    printf("You guessed: %d\n", guess);
    //printf("You guessed: %d%d\n", guess1, guess2);	

	// Now for the conditionals
	if (guess1 == random_number1 && guess2 == random_number2){
		printf ("Perfect match - you win $10,000!");
	}
	else {
	    /* if the digits match; since we already checked the first condition 
		   we just need to check if the opposites match */
		if (guess2 == random_number1 && guess1 == random_number2){
		   printf("You got the two digits right -- win $5000!"); 
		}
		else 
		{
			/* if  one of hte digits matches */
			if (guess1 == random_number1 || guess1 == random_number2) {
			   printf("You matched one digit -- you win $1000!"); 
		}
			else
			{
				printf("Nice try but no dice");
			}
		}	
	}
	printf("\n");
}


int main(void) {
   int digits=0,
	   guess1=0, 
	   guess2=0; 
   char match;
	
	printf("Guess a two-digit number: ");
    // Use getchar to get both digits
	
	scanf("%d", &guess1);

    if (guess1 > 9 || guess2 > 9) {
	    printf ( "Invalid guess");   
	} else {
	lottery(guess1);
	}
	return 0;
}



/*
 a = first digit
 b = second digit

 if a==r1 and b==r2
 else 
    if a == r2 and b == r1
	else
	   if a ==r1 or a == r2
	   else
 
 
 */
