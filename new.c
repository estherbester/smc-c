#include <stdio.h>

int main (void) {
    int intvar, intvar2=42;
	printf("The addr of intvar is %p. \n", &intvar);
    printf("The answer to everything is at %p. \n", &intvar2);
	printf("\n Enter an integer value: " );
	scanf ( "%d", &intvar) ;
	printf("The value you entered was %d. \n", intvar);
	return 0;


}
