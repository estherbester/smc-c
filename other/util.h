#include <stdio.h>

/*  Given an integer, breaks out into digits in reverse order;
    i.e. 364 prints out "4 6 3 "
*/
void print_digits(int num){

    int digit = 0,

        counter = 0;

    do {

        digit = num%10; // that's the ones digit of what remains
        num = num/10;
        if (digit != num) {
                printf("\nDigit %d: %d", counter, digit);
                counter++;
        }
        else counter = 0; // reset the counter
    }
    while (counter != 0);
}



int main (void) {
    int intvar, intvar2=42,
        number = 23,
        number2 = 3030,
        number3 = 56783,
        number4 = 50783;
	printf("The addr of intvar is %p. \n", &intvar);
    printf("The answer to everything is at %p. \n", &intvar2);
	printf("\n Enter an integer value: " );
	scanf ( "%d", &intvar) ;
	printf("The value you entered was %d. \n", intvar);

    printf("\nNow printing %d: ", number);
    print_digits(number);
    printf("\nNow printing %d: ", number2);
    print_digits(number2);
    printf("\nNow printing %d: ", number3);
    print_digits(number3);

    printf("\nNow printing %d: ", number4);
    print_digits(number4);
    return 0;


}
