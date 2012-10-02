#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void main(void)
{
  int i,nr;
  double rvalue, sum=0;
  
  printf("How many receipt:");
  scanf("%d",&nr);
  printf("===>>>%d\n",nr);
  for(i=0; i < nr ; i++)
  {
    printf("Enter receipt#%d>>",i+1);
    scanf("%f",&rvalue);
    printf("===>%f\n",rvalue);
    sum=sum + rvalue;
  
  }
  printf("Total is %6.2f\n",sum);
  
  
  
  
  
  
  
  }
  
  
  