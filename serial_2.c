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
        section_length = 0,
        char_count = 0,
        hyphen_count = 0,
        first_is_valid=0,
        second_is_valid=0,
        third_is_valid=0;

    printf("Enter the serial number: \n");
    while ((ch=getchar()) != '\n') {

        if (ch == SEPARATOR)
        {
            // gives us the length of the section up to the hyphen.
            hyphen_count++;
            section_length = char_count;
            char_count = 0; // reset the char_count for the next section
        }
        else
        {
            char_count++; // increment the number of characters input regardless

            // Each character belongs in a section; test its type accordingly.
            // e.g., if the input is in the second section, then the hyphen_count is 1,
            // so we test its type in case 1.
            switch (hyphen_count)
            {
                case 0:
                    first_is_valid += validate_string(ch);
                    break;
                case 1:
                    // This check is made every time a number is entered for the
                    // second section, but it should pass every time.
                    // If validate_string ever returned a 0, then first_is_valid length would be less
                    //than the numbe rof characters in the section then we don't have enough letters
                    if (first_is_valid != section_length)
                    {
                        printf ("\nFirst part of the key is invalid! First part should contain %d letters\n", section_length);
                        return 0;
                    }
                    second_is_valid += validate_num(ch);
                    break;
                case 2:
                    if (second_is_valid != section_length)
                    {
                        printf ("\nSecond part of the key is invalid! Second part should contain %d numbers\n", section_length);
                        return 0;
                    }
                    third_is_valid += validate_string(ch);
                    break;
                default:
                    printf("You have too many sections. Key is invalid.");
                    return 0;
            }
        }
    }
    // Presumably the user has hit "Enter" after entering the third part of the serial number.
    section_length = char_count;

    // They hit "Enter" too early
    if (hyphen_count < 2)
    {
        printf("Invalid key -- not enough sections\n");
    }
    else
    if (third_is_valid != section_length) {
            printf ("\nThird part of the key is invalid! Third part should contain %d letters\n", section_length);
        } else {
            printf("Key is in a valid format. Your copy of Adobe Photoshop has been unlocked!\n");
        }

    return 0;
}
