#include <stdio.h>
void printTree(int n);
void convert(void);
int add(int a, int b);

void main(void)
{  int x,y;

   x=5; y= 10;
   printTree(10);
   
   convert();
  printf("Total is %d\n",add(add(1,6),add(8,7)));
  
}
int add(int a, int b)
{ 
   int sum;
  
 
  sum = a + b;
  return sum;
}





void convert(void)
{ 
  int centigrade;
  double fah;
  
  printf("Enter centigrade:");
  scanf("%d",&centigrade);
  
  fah = 1.8 * centigrade + 32;
  printf("\n\n\n%d in cetigrade is %f in Fahreheite\n\n\n"
  ,centigrade,fah);
  


}

void printTree(int n)
{
  int i;
 for(i=0; i < n; i++)
 { 
 printf("       @\n");
 printf("      @@@\n");
 printf("     @@@@@\n");
 printf("    @@@@@@@\n");
 
 printf("      | |\n");
}

}







