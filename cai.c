
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <libc.h>
//#include <math.h>
#include <ctype.h>

#define CORRECT1 "Very good!"
#define CORRECT2 "Excellent!"
#define CORRECT3 "Nice Work!"
#define CORRECT4 "Keep up the good work!"

#define INCORRECT1 "No. Please try again."
#define INCORRECT2 "Wrong. Try once more."
#define INCORRECT3 "Don't give up!"
#define INCORRECT4 "No. Keep trying."

int get_answer(int, int);
void print_positive_response(void);
void print_negative_response(void);


// generates two random numbers
int ask_question(void){

    int left = (rand() % 9) + 1,
        right = (rand() % 9) + 1,
        user_answer = 0;        ;

        do {
            user_answer = get_answer(left, right);

            if (user_answer != left * right){
                print_negative_response();
            }
        } while (user_answer != left * right);

        print_positive_response();

        // signals main() to stop asking more questions.
        return 1;
}

// Prints the question and waits for user input.
// Returns user input
int get_answer(int left, int right){
    int user_answer=0;

    printf("\nHow much is %d * %d? ", left, right);
    scanf("%d", &user_answer);
    return user_answer;
}


int main (void){
    // keep_going is a flag to continue asking questions.
    int keep_going=1;
    // for random numbers.s
    srand ( time(NULL) );

    printf("Time for some math! \n");

    while (keep_going != 0){
        keep_going = ask_question();
    }

    return 0;
}


void print_positive_response(void)
{
    int response = rand() % 4;

    switch (response)
    {
        case 0:
            printf(CORRECT1);
            break;
        case 1:
            printf(CORRECT2);
            break;
        case 2:
            printf(CORRECT3);
            break;
        case 3:
            printf(CORRECT4);
            break;
    }
}

void print_negative_response(void)
{
    int response = rand() % 4;

    switch (response)
    {
        case 0:
            printf(INCORRECT1);
            break;
        case 1:
            printf(INCORRECT2);
            break;
        case 2:
            printf(INCORRECT3);
            break;
        case 3:
            printf(INCORRECT4);
            break;
    }
}
