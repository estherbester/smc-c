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
void print_results(int wins, int losses, int wins_with_points, int lost_with_points);
int throw_for_points(int points);



/*

*/
int main (void)
{
    srand(time(NULL));


    int i,
        throw,
        second_throw,
        first_wins = 0,
        first_losses = 0,
        wins_with_points = 0,
        lost_with_points = 0;

    // i represents the round to be recorded
    for (i=0; i < MAX_THROWS; i++)
    {
        printf("\nRound %i: *** throwing dice *** ", i);
        printf("\nFirst throw:");

        throw = throw_dice();

        if (throw == 7 || throw == 11)
        {
            printf("\nYou threw %i - you won!", throw);
            first_wins++;
        }
        else if (throw == 2 || throw == 3 || throw == 12)
        {
            printf("\nYou threw %i - you lost!", throw);
            first_losses++;
        }
        else {
            printf("; you have to make %i points:", throw);

            // now we have to try to make points
            second_throw = throw_for_points(throw);

            if (second_throw == 1)
            {
                wins_with_points++;
            }
            else
            {
                lost_with_points++;
            }
        }
        printf("\n");
    }
    print_results(first_wins, first_losses, wins_with_points, lost_with_points);
    return 0;
}

/*
    Prints the final results after 100 throws
*/
void print_results(int wins, int losses, int wins_with_points, int lost_with_points)
{
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

    returns {int} the sum of the result
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
    param {int} points that we have to match
    returns {int} if we throw 7, return 0; otherwise, we made points! so return 1
*/
int throw_for_points(int points)
{

    int throw;

    do
    {
        throw = throw_dice();
        //printf(">> You threw %i", throw);

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
