#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  int i;
  srand(time(NULL));
  
   for(i=0; i < 100; i++)
     printf(" =======>>>%d\n",rand()%6 +1);
 return 0;
 }