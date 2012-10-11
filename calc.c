/*

Calculator

Esther Nam
CS 50 TuTh
Fall 2012

*/

#include <stdio.h>

#define QUITKEY1 'R'
#define QUITKEY2 'r'



double get_input(void);


int main (void){
    double  result = 0.0;
    char go_again='y';

    printf("Calculator is on.\n");

    do {
        result = get_input();
        printf("Final result: %lf\n Again? ", result);
        scanf("%c", &go_again);
    }
    while (go_again != 'n');
    printf("End of program. Bye!\n");
    // put everything in this funciton
    return 0;
}


double get_input(void){
    double  result = 0.0,
            num = 0.0;
    char operand;

    printf("Result = %lf\n", result);

    while (operand != 'R' && operand != 'r'){
        scanf("%c%lf", &operand, &num);

        switch (operand){
        case '+':
            result = result + num;break;
        case '-':
            result = result - num;break;
        case '*':
            result = result * num;break;
        case '/':
            result = result/num;break;
        default: // is there a fallback?
            printf("%c is an unknown operation.\n Re-enter your last line:", operand);
        printf("result %c %lf = %f\n", operand, num, result );
        }
    }
    return result;
}
