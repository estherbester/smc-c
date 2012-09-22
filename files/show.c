#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


void doIf( int b);

int main(void)
{
  int a;
  printf("Enter a number:");
  scanf("%d",&a);
  printf("======>>>%d\n",a);
  doIf( a );
  

  
  return 0;
}
void doIf(int b)
{
 
if( b > 100)
    printf("%d is greater than 100\n",b);
  else if( b < 100)
	 printf("%d is less than  100\n",b);
  else
	printf("%d is   100\n",b);
}






