#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char getGrade(double testValue){

	char grade = 'F';

	
	if (testValue >= 90.0)
		grade = 'A';
	else
	    {
		if (testValue >= 80.0)
      		grade = 'B';
		else 
		  {
		  if (testValue >= 70.0)
				grade = 'C';
          else
		     {
			 if (testValue >= 60.0)
			    grade = 'D';
			 else
			    grade = 'F';
			 }
		}	
	}
    return grade;

}



int main (void){

    double testValue = 90.0;

    printf("What did you get on your test? \n");
	scanf("%lf", &testValue);
	printf("Your test score: %lf\n", testValue);

	printf("Your grade is: %c\n", getGrade(testValue));
	
	return 0;
}