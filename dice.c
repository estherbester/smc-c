
#include <stdio.h>
#include <stdlib.h>
#include <libc.h>
#include <math.h>
#include <string.h>

#define DIE_SIZE 6
#define MAX_THROWS 1000


int throw_dice(void) {

    int throw;

    srand ( time(NULL) );

    throw = rand() % DIE_SIZE;

    return throw;

}

void reset_throw_count(int * throw_count_array) {

    int i;

    for (i=0; i< DIE_SIZE; i++){
        throw_count_array[i] = 0;
    }


}

void print_results(int * rolls){

    int i;

    printf ("Die was thrown %d times. \n", MAX_THROWS);
    for (i=0; i< DIE_SIZE; i++){
        printf ("%d was thrown: %d times \n", i+1, rolls[i]);
    }


}

int main (void)
{

    int num_throws, throw, rolls[DIE_SIZE];

    reset_throw_count(rolls);

    for (num_throws=0; num_throws < MAX_THROWS; num_throws++)
    {
        throw = throw_dice();
        printf("%d", throw);
        rolls[throw] += 1 ;
    }

    print_results(rolls);

    return 0;
}


