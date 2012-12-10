#include <stdio.h>
#include <ctype.h>
#include <string.h>



int main (void)
{
    char * y = "0123456789";     // declaring an array for a string
    int i=0;
    char * x = y;

    printf("\nFirst way x++: ");
    for (i=0;i<(int) sizeof(char) * strlen(y) ;i++)
    {

        printf("%c, ",*x++ );

    }
    printf("\nOther way: ++x ");
    x = y;
    for (i=0;i<(int) sizeof(char) * strlen(y) ;i++)
    {
        printf("%c, ",*(++x) );
    }
   return 0;


}
