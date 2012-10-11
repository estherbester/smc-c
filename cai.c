/*****

Computer-Assisted Instruction

Esther Nam
CS 50 TuTh
Fall 2012


*/


#include <stdio.h>
#include <libc.h>
#include <ctype.h>

#define CORRECT1 "Very good!"
#define CORRECT2 "Excellent!"
#define CORRECT3 "Nice Work!"
#define CORRECT4 "Keep up the good work!"

#define INCORRECT1 "No. Please try again."
#define INCORRECT2 "Wrong. Try once more."
#define INCORRECT3 "Don't give up!"
#define INCORRECT4 "No. Keep trying."

int generate_question(void);
int ask_question(int, int);
void print_positive_response(void);
void print_negative_response(void);


/*
Generates two random numbers, then calls "ask_question" and gets back user input.
Tests user input, repeating the question if input is incorrect, or,
if the user answers correctly, asking a new question.
*/
int generate_question(void){

    int left = (rand() % 9) + 1,
        right = (rand() % 9) + 1,
        user_answer = 0;        ;

        do {
            user_answer = ask_question(left, right);

            // Signals main() to stop
            if (user_answer == -1) {
                printf("\nGoodbye!\n");
                return 0;
            }

            if (user_answer != left * right)
                print_negative_response();


        } while (user_answer != left * right);  // While user incorrect, ask and get response.

        // When correct response is given, give praise.
        print_positive_response();

        // Signals main() to continue asking more questions.
        return 1;
}

// Prints the question and waits for user input.
// Returns user input, or stop signal (-1)
int ask_question(int left, int right){
    int user_answer=0;

    printf("\nHow much is %d * %d? ", left, right);

    if (scanf("%d", &user_answer) != EOF)
        return user_answer;
    else
        return -1;
}


int main (void){
    // keep_going is a flag to continue asking questions.
    int keep_going=1;

    // For randomizing numbers.
    srand ( time(NULL) );

    printf("Time for some math! Hit Ctrl-D to quit.\n");

    while (keep_going != 0){
        keep_going = generate_question();
    }

    return 0;
}

/* Prints a randomized response for correct answers */
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

/* Prints a randomized response for incorrect answers */
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
