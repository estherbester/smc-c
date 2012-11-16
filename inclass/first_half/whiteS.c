#include <stdio.h>

int main(void)
{
    int iochar, numdigits=0, numlower=0, numupper=0, numwhites=0;

	printf("Please enter a phrase:\n\n");
	
    while((iochar=getchar())!=EOF) 
	{
        if ((iochar=='\n')||(iochar==' ')||(iochar=='\t'))
		{
            numwhites++;
            putchar(iochar);
        }
        else 
		   if((iochar>='0')&&(iochar<='9')) 
		   {
            numdigits++;
            putchar(iochar);
            }
           else 
		      if(('a'<=iochar)&&(iochar<='z')) 
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
	
    printf("%d white characters, %d digits, ",numwhites,numdigits);
    printf("%d lowercase have been converted to ",numlower);
    printf("uppercase and %d uppercase.\n",numupper);
	
	printf("\n\n");
	
	return 0;
	}
