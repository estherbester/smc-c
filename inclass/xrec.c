/* linked lists */

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
    struct xrec * next;  // the only kind of struct you can have here: pointer to a struct
    // sizeof pointer is 4
};


int main (void) {
    struct xrec * first;
    struct xrec temp;
    FILE * infile;

    first = NULL;

    while (fscanf(infile, " .... ", temp.name /*, etc */) != EOF)
    {
        temp.name[10] = '\0';
        // OR:
        // x[size++] = temp;
        temp.ssn[11] = '\0';
        first = addToList(first, temp);  // must return pointer to struct

    }
}


struct xrec * addToList(struct xrec * list, struct xrec t)
{
    struct xrec * newNode;
    newNode = malloc(sizeof(struct xrec));

    *newNode = t;
    newNode->next = list;
    return newNode;  // linked list!  returns pointer to next node
    // returns to beginning

}


void printName(struct xrec * list)
{
    while (list != NULL)
    {
        printf("Name: %s", list->name);
        list = list->next;
    }
}
