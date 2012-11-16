#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
   double num,sum=0.0;
   int c=0;
   printf("EOF is %d\n",EOF);
   
   printf("Enter number:");
   while(scanf("%lf",&num) !=EOF)
   {
     printf("You entered %f\n",num);
     sum+=num;c++;
   
   }
   printf(" sum is %f count is %d\n",sum,c);
   return 0;
   }