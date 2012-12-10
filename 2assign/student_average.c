/*

Write a complete program that prompts how many students? reads the number.
Make a loop for that many students.
- prompts the first student for name and
- how many tests,
- get name,
- number of tests.

- Make a loop to sum all of her/his tests and compute the average of her/his test.

  Your program should output student name, test average and a letter grade.

  NOTE: to get credit you must write at least one function.
  Note: To assign the letter grade use (if  average >= 90, A, >=80, B etc.).
*/


#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

struct student_record
{
    char name[20];
    int number_of_tests;
    double * scores;
    double average_score;
    char grade;
};

struct student_record get_student_record(void);
void get_name(char *);
int get_number_of_tests(void);
double get_scores_for_tests(int, double *);
double get_test_grade(int);
double calculate_average(double tests_sum, int number_of_tests);
char get_letter_grade(double testValue);
void print_student_records(struct student_record student_records[], int);


int main(void)
{

    int i,
        number_of_students = 0;
    struct student_record * all_records;

    // Get the number of students - we need to create a record for each student.
    printf("How many students? ");
    scanf("%d", &number_of_students);
    //fflush(stdin);

    printf("You entered: %d students\n", number_of_students);

    // Create storage for the number of student records we need to save.
    all_records = malloc(number_of_students * sizeof(struct student_record));

    // The real work begins:
    for (i = 0; i < number_of_students; i++)
    {
        printf("\nEntering record for Student %d:\n", i+1);
        all_records[i] = get_student_record();
    }

    print_student_records(all_records, number_of_students);

    return 0;

}

/*
   Constructs student record by calling various functions

   Returns {struct student_record}
*/
struct student_record get_student_record(void)
{

    double  total_score=0;

    struct student_record record;

    get_name(record.name);

    record.number_of_tests = get_number_of_tests();

    // Allocate memory to store the tests
    record.scores = malloc(record.number_of_tests * sizeof(double));

    total_score = get_scores_for_tests(record.number_of_tests, record.scores);

    // Compute the average of all the test scores
    record.average_score = total_score/record.number_of_tests;

    // Determine the letter grade
    record.grade = get_letter_grade(record.average_score);

    return record;
}

/*
  Asks for student's name and saves it to string name

  Param {char * } -- points to struct student_record.name array
*/
void get_name(char * name)
{
    char input_name[20];
    printf("What is the student's name? ");

    scanf("%s", input_name);
    //fflush(stdin);
    strcpy(name, input_name);
}

/*
  Gets input from user
  Returns {int} number of tests.
*/
int get_number_of_tests(void){

    int number_of_tests = 0;

    printf("How many tests taken? ");
    scanf("%i", &number_of_tests);
    //fflush(stdin);

    return number_of_tests;
}

/*
    Given the number of tests, get the score for each test
    and store in the array that is passed as tge second param

    Param {int} number of tests for which we need to get score
    Param {double *} array of test scores which we will populate here.
    Returns {double} sum of the score (to help compute the average later.)
*/
double get_scores_for_tests(int number_of_tests, double * scores)
{
    int i;
    double total_score=0;

    for (i=0; i< number_of_tests; i++)
    {
        scores[i] = get_test_grade(i);
        total_score += scores[i];
    }
    return total_score;

}

/*
   Gets grade of each test taken.

   Param {int} is required only for the print statement.
   Returns {double} score that is input by the user
*/
double get_test_grade(int index)
{
    double score = 0.00;

    printf("Enter Test Score %d: ", index+1);
    scanf("%lf", &score);
    //fflush(stdin);

    return score;
}

/*
   Param {double} representing the percentage grade that the user inputted.
   Returns {char} representing letter grade
*/
char get_letter_grade(double testValue)
{
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
             }
        }
    }
    return grade;
}

/*
   Prints out each student's record: test average and final grade

   Param {struct student_record *}
   param {int} length of the struct array
*/
void print_student_records(struct student_record records[], int number_of_students)
{
    int i;
    printf("\n========== STUDENT RECORDS ==========\n");
    printf("    %-20s%8s %10s\n", "Name", "Average", "Grade");

    for(i=0; i< number_of_students; i++)
    {
        printf("%2d. %-20s%7.2lf%10c\n",
                            i+1,
                            records[i].name,
                            records[i].average_score,
                            records[i].grade);
    }
}



