
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "funcs.h"
#include "menu2.h"
//gcc main.c funcs.c menu2.c -o main.out

void main_menu2(void);            /* runs in the main loop */
void print_main_menu2(void);      /* output the main menu description */
int  get_user_input2(void);       /* get a valid integer menu choice */
void select_menu_item2(int input);/* run code based on user's choice */
void go_back_to_main2(void);      /* wait for 'b'/'B' to continue */
int  is_integer(const char *s);  /* validate integer string */

int main2(void)
{
    /* this will run forever until we call exit(0) in select_menu_item() */
    for(;;) {
        main_menu2();
    }
    /* not reached */
    return 0;
}

void go_back_to_main2(void) {
    char input2;
    // this do loop ensures user inputs 'b' or 'B' to go back
    // if user inputs other characters, it keeps prompting
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        scanf(" %c", &input2);
    } while (input2 != 'b' && input2 != 'B');
    main_menu2();
}

 void main_menu2(void)
{
    print_main_menu2();
    {
        int input2 = get_user_input2();
        select_menu_item2(input2);
    }
}

int get_user_input2(void)
{
    enum { MENU_ITEMS2 = 3 };   /* 1,2 = items, 3 = Exit */
    char buf2[128];
    int valid_input2 = 0;
    int value2 = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf2, sizeof(buf2), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf2[strcspn(buf2, "\r\n")] = '\0';

        if (!is_integer(buf2)) {
            printf("Enter an integer!\n");
            valid_input2 = 0;
        } else {
            value2 = (int)strtol(buf2, NULL, 10);
            if (value2 >= 1 && value2 <= MENU_ITEMS2) {
                valid_input2 = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input2 = 0;
            }
        }
    } while (!valid_input2);

    return value2;
}

void select_menu_item2(int input2)
{
    switch (input2) {
        case 1:
            menu_item_3();
            go_back_to_main();
            break;
        case 2:
            menu_item_4();
            go_back_to_main();
            break;

        default:
            printf("Bye!\n");
            exit(0);
    }
}

void print_main_menu2(void)
{
    printf("\n----------- Main menu -----------\n");
    printf("\nWanted outcome"
           "\t\t\t\t\t\t\n"
           "\t1. Find K\t\t\n"
           "\t2. Find Vi/Vo\t\t\n"
           "\t3. Exit\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
}


