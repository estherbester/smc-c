
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libc.h>
#include <math.h>
#define SEPARATOR '-'


// generates two random numbers and poses question. returns the answer.
int ask_math_question(void){

    int left = (rand() % 9) + 1,
        right = (rand() % 9) + 1;

    printf("\nHow much is %d * %d? ", left, right);
    return left * right;
}



int main (void){
    // for random numbers.s
    srand ( time(NULL) );
    int answer, user_answer;

    printf("Time for some math! \n");

    do {
        answer = ask_math_question();
        scanf("%d", &user_answer);
        if (user_answer == answer){
            printf("\n Very Good!!");
        }
        else
        {
            printf("\n No. Please try again. ");

        }
    } while (answer != EOF);


    return 0;
}
