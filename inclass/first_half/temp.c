#include <stdio.h>

int main(void)
{
  int centigrade;
  double fah;
  printf("Enter Centigrade:");
  scanf("%d",&centigrade);
  
  
  
  fah= 1.8 * centigrade + 32.0;
  
  printf("%d in centigrade is %f in Fah\n",
  centigrade,fah);
  return 0;
  }
  
  