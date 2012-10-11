/*

Serial Number

Esther Nam
CS 50 TuTh
Fall 2012

Validates a serial number based on its formatting.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SEPARATOR '-'



    /*
        validate first input as letter
        validate length of letter input as 12

        validate second input as digit
        validate lenght of digit input as 9

        validate third input as letter
        validate length of letter input as 9

    */


/*
    get input from user
    first 12 must be letter
    then hyphen
    second 9 must be digit
    then hyphen
    third 9 must be letter

*/
int validate_num (int ch)
{
    if (isdigit(ch))
        return 1;
    else
        return 0;
}

int validate_string (int ch)
{
    if (isalpha(ch))
        return 1;
    else
        return 0;
}

int main(void) {
    int ch,
        hyphen_count = 0,
        first_is_valid=0,
        second_is_valid=0,
        third_is_valid=0;

    printf("Enter the serial number: \n");
    while ((ch=getchar()) != '\n') {
        if (ch == SEPARATOR)
            hyphen_count++;
        switch (hyphen_count)
        {
            case 0:
                first_is_valid += validate_string(ch);
                break;
            case 1:
                if (first_is_valid != 12)  // then we don't have enough letters
                {   
                    printf ("\nFirst part of the key is invalid! First part should contain 12 letters\n");
                    return 0;
                }
                second_is_valid += validate_num(ch);
                break;
            case 2:
                third_is_valid += validate_string(ch);
                if (second_is_valid != 9)
                {
                    printf ("\nSecond part of the key is invalid! Second part should contain 9 numbers\n");
                    return 0;
                }
                break;
        }
    }
    // Presumably the user has hit "Enter" after entering the third part of the serial number.
    if (third_is_valid == 9) { // If the user typed exactly 9 letters: 
        printf("Key is in a valid format. Your copy of Adobe Photoshop has been unlocked!\n"); 
    } else {
        printf ("\nThird part of the key is invalid! Third part should contain 9 letters\n");
    }
    
    return 0;
}
