
#include <stdio.h>


#define DIE_SIZE 6
#define MAX_THROWS 10000


void stat_the_array(int * rolls);

int throw_dice(void);

void reset_throw_count(int * throw_count_array) {

    int i;

    for (i=0; i< DIE_SIZE; i++){
        throw_count_array[i] = 0;
    }

}

void print_results(int * rolls){

    int i;

    printf ("\nDie was thrown %d times. \n", MAX_THROWS);
    for (i=0; i< DIE_SIZE; i++){
        printf ("%d was thrown: %d times \n", i+1, rolls[i]);
    }
    printf("\n\n==INFO==\n");
    stat_the_array(rolls);
}

void stat_the_array(int rolls[]){
    printf("Array size of sizeof(*rolls): %lu\n", sizeof(*rolls));
    printf("Array size of sizeof(rolls): %lu\n", sizeof(rolls));
    printf("Array size of sizeof*(rolls): %lu\n", sizeof*(rolls));
    printf("Rolled 1: %d times\n", rolls[0]);
    //printf("Array size of sizeof(*rolls): %lu\n", sizeof(*rolls));
}

int main (void)
{

    int num_throws, throw, rolls[DIE_SIZE];

    srand ( time(NULL) );
    reset_throw_count(rolls);

    for (num_throws=0; num_throws < MAX_THROWS; num_throws++)
    {
        throw = rand() % DIE_SIZE;
        rolls[throw] += 1 ;
    }

    print_results(rolls);

    return 0;
}


int throw_dice(void)
{

    int throw;

    srand ( time(NULL) );

    throw = rand() % DIE_SIZE;

    return throw;

}
