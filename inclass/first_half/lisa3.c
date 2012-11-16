#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void main(void)
{
  int i=1,nr;
  double rvalue, sum=0;
  
  printf("enter receipt:");
  scanf("%lf",&rvalue);
  while(rvalue !=0)
  {
   sum= sum + rvalue;
   printf("enter receipt:");
   scanf("%lf",&rvalue);
   i++;
  }
  printf("i is==>>%d\n",i);
  printf("Total is %f\n",sum); 
  printf("Average is %f\n",sum/(i-1)); 
 } 
  
  
  
  