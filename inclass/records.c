#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct xrec
{
	char name[11]; // extra char for the \0
	char ssn[12];
	char gender;
	double homework, quizzes, midterm, final;
	char grade;


};

void printStudent(struct xrec * a, int size);
void computeGrade(struct xrec * a, int size);

int main()
{
	struct xrec temp;
	struct xrec x[20];

	int size=0;
	FILE * infile;

    infile = fopen("data.txt", "r");  // creates pointer to first char in that file
	if (infile == NULL)
	{
		printf("File not found\n");
		exit(0);
	}

	while (fscanf(infile, "%10s %11c %c %lf %lf %lf %lf",
		   		temp.name, temp.ssn, &temp.gender, &temp.homework,
				&temp.quizzes, &temp.midterm, &temp.final) != EOF)
	{
		temp.name[10] = '\0';  // puts null char at the end
		temp.ssn[11] = '\0';
		x[size++] = temp;  // assigns record to the array
	}
	fclose(infile);
	computeGrade(x, size);
	printStudent(x, size);

	return 0;


}
void computeGrade(struct xrec * a, int size)
{
	int i;
	double total;

	for (i=0; i < size; i++)
	{
		total = a[i].homework * .4 + 10
				+ a[i].quizzes * .15
				+ a[i].midterm * .15
				+ a[i].final* .2;

		switch ((int) total/10)
		{
			case 9: ;
			case 10: a[i].grade = 'A';break;
			case 8: a[i].grade = 'B';break;
			case 7: a[i].grade = 'C';break;
			case 6: a[i].grade = 'D';break;
			default:
				a[i].grade = 'F';
		}
	}
}

// or 'struct xrec a[]
void printStudent(struct xrec * a, int size)
{
     int i;
	 for (i=0; i< size; i++)
	 {
	     printf("Name: %s\nSSN: %s\nGender: %c\nGrades: %4.2f, %4.2f, %4.2f, %4.2f\n",
				a[i].name,
				a[i].ssn,
				a[i].gender,
				a[i].homework, a[i].quizzes, a[i].midterm, a[i].final);
	     printf("Final grade: %c\n", a[i].grade);
	 }

}
