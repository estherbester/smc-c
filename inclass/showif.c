#include <stdio.h>

void main(void)
{
   int a ;
   printf("enter an integer:");
   scanf("%d",&a);
   printf("you entered %d\n",a);
   if( a > 100)
    printf("%d is > 100\n",a);
   else
    if(a < 100)
     printf("%d is < 100\n",a);
	else
	 printf("%d is 100\n",a);
	
}