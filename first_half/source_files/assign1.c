/*
Assignment 1

Esther Nam
CS 50 TuTh
Fall 2012

Returns letter grade if given a test score percentage
*/

#include <stdio.h>

/*
   Parameter: a double representing the percentage
 			  grade that the user inputted.
   Returns char representing letter grade
*/
char getGrade(double testValue){
	// The default grade is an F
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
    // Initialize test score with 0
    double testValue = 0.00;

    printf("What did you get on your test? \n");
	scanf("%lf", &testValue);

	// Only call getGrade if we have a valid test score
	if (testValue < 0.00 || testValue < 100.0) {
		printf("Your test score: %lf\n", testValue);
		printf("Your grade is: %c\n", getGrade(testValue));
	}
    else
	{
	    printf("That is not a valid test score\n");
	}
	return 0;
}
