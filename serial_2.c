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
    get input from user
    first 12 must be letter
    then hyphen
    second 9 must be digit
    then hyphen
    third 9 must be letter

*/
int validate_num (int ch, int *char_count)
{
    if (isdigit(ch))
        return 1;
    else
        return 0;
    *char_count += *char_count; // increment the number of characters input regardless
}

int validate_string (int ch, int *char_count)
{
    if (isalpha(ch))
        return 1;
    else
        return 0;
    *char_count += *char_count;

}

int main(void) {
    int ch,
        char_count = 0,
        hyphen_count = 0,
        first_is_valid=0,
        second_is_valid=0,
        third_is_valid=0;

    printf("Enter the serial number: \n");
    while ((ch=getchar()) != '\n') {

        if (ch == SEPARATOR)
        {
            char_count = 0; // reset the char_count
            hyphen_count++;
        }
        switch (hyphen_count)
        {
            case 0:
                first_is_valid += validate_string(ch, &char_count);
                break;
            case 1:
                if (first_is_valid != char_count)  // then we don't have enough letters
                {
                    printf ("\nFirst part of the key is invalid! First part should contain %d letters\n", char_count);
                    return 0;
                }
                second_is_valid += validate_num(ch, &char_count);
                break;
            case 2:
                third_is_valid += validate_string(ch, &char_count);
                if (second_is_valid != char_count)
                {
                    printf ("\nSecond part of the key is invalid! Second part should contain %d numbers\n", char_count);
                    return 0;
                }
                break;
        }
    }
    // Presumably the user has hit "Enter" after entering the third part of the serial number.
    if (third_is_valid == char_count) { // If the user typed exactly 9 letters:
        printf("Key is in a valid format. Your copy of Adobe Photoshop has been unlocked!\n");
    } else {
        printf ("\nThird part of the key is invalid! Third part should contain %d letters\n", char_count);
    }

    return 0;
}
