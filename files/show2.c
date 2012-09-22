#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  char ch; int num;
  printf("Enter a number:");
  scanf("%d",&num);
  printf("You just entered %d\n",num);
  printf("enter a Character:");
 /* fflush(stdin);
  scanf("%c",&ch);scanf("%c",&ch);*/
  scanf(" %c",&ch);
  
  printf("You just entered %c\n",ch);
  printf("XXXXXXXXXXXXXXXXXX");
  return 0;
  }