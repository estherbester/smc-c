#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void get_student_grades(int i);
void get_name(void);

int get_number_of_tests(void); // asks how many tests taken

void get_test_grades(int); // gets grade eof each test taken

char calculate_grade(double, int); // calculate the average grade and returns letter grade


int main (void){
    int students, i;

    printf("How many students? ");
    scanf("%i", &students);
    printf("%i students. \n", students);

    int * student_array[students]; // create an array of pointers to contain students

    for (i=0; i< students; i++){
        get_student_grades(i); // start processing
    }

    return 0;
}


/*
    returns {array} characters
*/
void get_student_grades(int i){
    char letter_grade;
    int number_of_tests;
    double tests_sum;

    printf("%i", i);
    get_name();
    number_of_tests = get_number_of_tests();
    tests_sum = get_test_grades(number_of_tests);
    letter_grade = calculate_grade(tests_sum, number_of_tests);

}

void get_name(void){
    printf("What is the student's name? ");
    // get the name and put it in the array.
}

char calculate_grade(double tests_sum, int number_of_tests){

    char grade = 'F';


    return grade;
}
