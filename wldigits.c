/*

Esther Nam
CS 50 TuTh
Fall 2012

The purpose of the following program is to count the whitespace, the digits, the uppercase alphabetics and lowercase alphabetics in the input. There are bugs in the program. FIX IT
*/

#include <stdio.h>


int count_whitespace(int iochar)
{
    int numwhites = 0;

    if ((iochar==' ')||(iochar=='\t')||(iochar=='\n'))
    {
        numwhites = 1;
    }
    return numwhites;
}

void print_summary( int numwhites, int numdigits, int numlower, int numupper)
{
    printf("%d white characters, \n%d digits, \n", numwhites, numdigits);
    printf("%d lowercase have been converted to ", numlower);
    printf("uppercase and \n %d uppercase.\n", numupper);

    printf("\n\n");


}

int main(void)
{
    int iochar,
        numdigits=0,
        numlower=0,
        numupper=0,
        numwhites=0;

    printf("Please enter a phrase:\n\n");

    while((iochar=getchar())!=EOF)
    {
        // FIX: changed assignment to equality for each of the three conditionals.
        if ((iochar==' ')||(iochar=='\t')||(iochar=='\n'))
        {
            numwhites += count_whitespace(iochar);
            putchar(iochar);
        }
        else
           if((iochar>='0') && (iochar<='9'))
           {
            numdigits++;
            putchar(iochar);
            }
           else
              if(('a'<=iochar) && (iochar<='z'))
              {
               numlower++;
               putchar(iochar-32);
               }
              else
                if(('A'<=iochar)&&(iochar<='Z'))
                {
                 numupper++;
                 putchar(iochar);
                }
                else
                  putchar(iochar);
    }

    // FIX: Broke out the print statements into their own function.
    print_summary(numwhites, numdigits, numlower, numupper);

    return 0;
}

/*
Execute the program in its present form using input for which it is easy to predict the output.
Analyze the program from the output obtained through the testing and tentatively make some changes.
Retest it until you are sure that the bugs are out.
Rewrite the program in more structured way. It should have more than one function.
*/
