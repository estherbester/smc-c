
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 200

struct menu_item
{
    int command;
    char * function_to_call;
};


void print_menu(void);
int get_menu_input(void);
void clear_buffer(void);


int main(void)
{

    double * data;
    int choice;
    struct menu_item menu_commands[]
            = {

            };



    print_menu();

    choice = get_menu_input();
    // now run the function represented by that choice
    // (which we have in our array of menu_item structs)


    return 0;
}

void print_menu (void)
{
    printf("\n");
    printf("========== MENU ==========\nChoose from the following:\n==========================");
    printf("\n");
    printf("1: Enter data.");
    printf("\n");
    printf("2: Display data.");
    printf("\n");
    printf("3: Quit.");
    printf("\n");
    printf("Your choice: ");

}


int get_menu_input(void)
{
    int choice;

    scanf("%i", &choice);

    fflush(stdout);

    if (choice == EOF) {
        choice = 3;
    }

    printf("You chose command: %i\n", choice);
    return choice;

}
