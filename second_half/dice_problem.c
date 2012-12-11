/*
    Craps game.

    Rules:
    - 7 or 11 on first throw = WIN
    - 2, 3, 12 on first throw = LOSE
    - Anything else: roll until you make_points
        - if you roll 7 before you make points, you LOSE
*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


#define MAX_THROWS 100

int throw_dice(void);
void validate_throw(int, int*);
int throw_for_points(int points);
void print_results(int * results );


/*
    Iterates through 100 rounds
*/
int main (void)
{
    srand(time(NULL));

    int i,
        throw,
    	results[4] = {0,0,0,0}; // array containing 4 values for each of the possible resultswhich should thus be initialized 
		
    // i represents the round to be recorded
    for (i=0; i < MAX_THROWS; i++)
    {
        printf("\nRound %i: *** throwing dice *** ", i);
        printf("\nFirst throw:");

        throw = throw_dice();
        validate_throw(throw, results);
        
        printf("\n");
    }
    print_results(results);
    return 0;
}

/* 
* Given the throw, prints the results of the throw and records the result in the 
* "results" array, which has values as follows:
*
*  results[0] - wins
*  results[1] - losses
*  results[2] - wins from making points
*  results[3] - losses from not making points
* 
*  @param {int} value of the throw
*  @param {pointer} to the array containing the results of which we are keeping track.
*/
void validate_throw(int throw, int * results) {

		int second_throw;
		
        if (throw == 7 || throw == 11)
        {
            printf("\nYou threw %i - you won!", throw);
            results[0]++; // increment the value of "Win on first throw"
        }
        else if (throw == 2 || throw == 3 || throw == 12)
        {
            printf("\nYou threw %i - you lost!", throw);
            results[1]++; // increment the value of "Losses on first throw"
        }
        else
		{
            printf("; you have to make %i points:", throw);

            // now we have to try to make points
            second_throw = throw_for_points(throw);

            if (second_throw == 1)
            {
				results[2]++; // increment the value of "Wins iwth points"
            }
            else
            {
				results[3]++; // increment the value of "Losses iwth points"
            }
        }
}


/*
    Prints the final results after all the throws

	@param {ptr} array containing the results of all the throws
*/
void print_results(int * results) 
{
	int wins = results[0], 
		losses = results[1],
		wins_with_points = results[2],
		lost_with_points = results[3];

    printf("\n==============");
    printf("\nFINAL RESULTS:");
    printf("\n==============");
    printf("\n");
    printf("Number of throws: %i\n", MAX_THROWS);
    printf("You won %i times on the first throw\n", wins);
    printf("You lost %i times on the first throw\n", losses);
    printf("You won with points %i times\n", wins_with_points);
    printf("You lost with points %i times\n", lost_with_points);
}


/*
    Prints the result of the dice throw

    @returns {int} the sum of the result
*/
int throw_dice(void)
{
    int die1, die2;

    die1 = rand() % 6 + 1;
    die2 = rand() % 6 + 1;
    printf("\nYou rolled a %i and %i", die1, die2);

    return die1 + die2;
}

/*
    Handles the second round of throws (to "make points")
	
    @param {int} points that we have to match
    @returns {int} if we throw 7, return 0; otherwise, we made points! so return 1
*/
int throw_for_points(int points)
{

    int throw;

    do
    {
        throw = throw_dice();

        if (throw == points){
            printf("\n>> You made points!");
            return 1; // we won!
        }
        else if (throw == 7)
        {
            printf("\n>> Sorry, you lose"); // we lost =(
        }
    } while (throw != 7);
    return 0;
}
