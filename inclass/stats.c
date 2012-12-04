
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
struct menu_item get_menu_input(void);




int main(void)
{

    double * data;
    struct menu_item choice;

    print_menu();

    choice = get_menu_input();

    printf("You chose command: %d", choice.command);

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
}


struct menu_item get_menu_input(void)
{
    struct menu_item choice;

    scanf("Make your choice: %d", &choice.command);

    return choice;

}
