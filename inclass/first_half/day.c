#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char getDay(int x);

int main()
{
  int day;char ch;
  
  printf("Enter 2 or 3 or 4>>>: ");
  scanf("%d",&day);
  ch=getDay(day);
  printf("The day is %c\n",ch);
  if(ch=='M')
    printf("The day is Monday\n");
  else if(ch=='T')
    printf("The day is Tuesday\n");
  else if(ch=='W')
    printf("The day is Wednesday\n");
  else
    printf("It was an Error\n");
  
  
  
  return 0;
 }
 char getDay(int x)
 {
   if(x==2)
    return 'M';
   else if(x==3)
    return 'T';
   else if (x==4)
    return 'W';
   else
    return 'E';
 }
 
 
 
 
 
 
 