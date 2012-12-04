// Now we are using linked lists we can have as many as we want

#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct xrec
{
	struct xrec * prev;
	char name[11]; // extra char for the \0
	char ssn[12];
	char gender;
	double homework, quizzes, midterm, final;
	char grade;
	struct xrec * next;  // the only kind of struct you can have here: pointer to a struct
};


void printStudent(struct xrec *);
void computeGrade(struct xrec *);
struct xrec * addToList(struct xrec *, struct xrec);
struct xrec * read_data_file(FILE * infile);


int main(void)
{
	struct xrec * first = NULL;
	FILE * infile;

    infile = fopen("data.txt", "r");  // creates pointer to first char in that file
	if (infile == NULL)
	{
		printf("File not found\n");
		exit(0);
	}

	first = read_data_file(infile);

	fclose(infile);

	computeGrade(first);
	printStudent(first);

	return 0;
}


struct xrec * read_data_file(FILE * infile)
{
	struct xrec temp, * first;


	while (fscanf(infile, "%10s %11c %c %lf %lf %lf %lf",
		   		temp.name, temp.ssn, &temp.gender, &temp.homework,
				&temp.quizzes, &temp.midterm, &temp.final) != EOF)
	{
		temp.name[10] = '\0';   // putts null char at the end of
		temp.ssn[11] = '\0';	// these strings

		first = addToList(first, temp);
	}
	return first;

}



struct xrec * addToList(struct xrec * list, struct xrec temp)
{
    struct xrec * newNode = malloc(sizeof(struct xrec));

    *newNode = temp;
    newNode->next = list;
    // OR newNode.next = list;

    return newNode;  // linked list!  returns pointer to next node
    // returns to beginning of linked list
}


void computeGrade(struct xrec * list)
{
	double total = 0.0;

	while (list != NULL)
	{
		total = list->homework * .4 + 10
				+ list->quizzes * .15
				+ list->midterm * .15
				+ list->final* .2;


		switch ((int) total/10)
		{
			case 9: ;
			case 10:list->grade = 'A';break;
			case 8: list->grade = 'B';break;
			case 7: list->grade = 'C';break;
			case 6: list->grade = 'D';break;
			default:
				list->grade = 'F';
		}
	list = list->next;
	}

}


// or 'struct xrec a[]
// new
void printStudent(struct xrec * list)
{
	while (list != NULL)
	{
		// because list is a pointer, use arrow notation
		printf("\nName: %s\nSSN: %s\nGender: %c\nGrades: %4.2f, %4.2f, %4.2f, %4.2f\n",
				list->name,
				list->ssn,
				list->gender,
				list->homework, list->quizzes, list->midterm,list->final);
	    printf("Final grade: %c\n", list->grade);
	    list = list->next;  // need to continue
	}

}


struct xrec *  deleteFromList(struct xrec * list, char * t)

{
	// create two placeholders, since linked lists go in only one direction
	// you want the previous to be NULL, then update as you go.
	struct xrec * curr, * prev;

	// if the SSN is a match, we want to delete
	// if .prev contains null, it's the first record
	// if .next contains NULL, it's the last record
	for (prev = NULL, curr = list;
		 (curr != NULL) && (!strcmp(curr->ssn, t) == 0) && (curr->next != NULL);
 		 prev=curr, curr=curr->next)
	{
		// we want to move the links
		curr->prev = prev;
		prev->next = curr;
	}

	if (prev == NULL) // how to delete the first record?

	return curr;
}
