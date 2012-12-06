#include <stdio.h>
#include <ctype.h>



int main (void)
{
    char * y;     // declaring an array for a string
    int i=0;
    y = "Sally";  // this is the string

    char * x[10]; // array of 10 names

//    x[0] = malloc(sizeof(y) * sizeof(char)) ;

    x[0] = y;

    printf("x** is: %c", **x);
    printf("\n");
    printf("*x[0] is: %c", *x[0]);
    printf("\n");

    printf("x[0][3] is: %c", x[0][3]);
    printf("\n");
    printf("(*x)[3] is: %c", (*x)[3]);
    printf("\n");

    printf("*x[3] is: %c", *x[3]);
    printf("\n");
    printf("\n");

   for (i=0; i<9; i++){
       printf("(*x)[%i] is:  %c, address: %p\t || *x[%i] is %p", i, (*x)[i], &((*x)[i]), i, &(*x[i]));
       printf("\n");
   }

   return 0;


}
