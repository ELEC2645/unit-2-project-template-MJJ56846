// ELEC2645 Unit 2 Project Template
// Command Line Application Menu Handling Code
//gcc main.c funcs.c -lm -o main.out

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include "funcs.h"


/* Prototypes mirroring the C++ version */

void main_menu(void);            /* runs in the main loop */
void print_main_menu(void);      /* output the main menu description */
int  get_user_input(void);       /* get a valid integer menu choice */
void select_menu_item(int input);/* run code based on user's choice */
void go_back_to_main(void);      /* wait for 'b'/'B' to continue */
int  is_integer(const char *s);  /* validate integer string */
int get_user_input2(void); //get user input menu 2

void go_back_to_main(void) {
    char input;
    // this do loop ensures user inputs 'b' or 'B' to go back
    // if user inputs other characters, it keeps prompting
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        scanf(" %c", &input);
    } while (input != 'b' && input != 'B');
    main_menu();
}


int ask_numberf(float *out_number) {//input protection for floats
    char buf[1024];
    int success;
    do {
        printf("Enter a float: ");
        if (!fgets(buf, 1024, stdin)) return 1;
        char *endptr;
        errno = 0;
        *out_number = strtof(buf, &endptr);
        if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n')){   
        success = 0;
        return -2;
        }
            
        else
            success = 1;
    } while (!success);
    return 0;
}
int ask_number(int *out_number) {//input protection for ints
    char buf[1024];
    int success;
    do {
        printf("Enter an integer: ");
        if (!fgets(buf, 1024, stdin)) return 1;
        char *endptr;
        errno = 0;
        *out_number = strtol(buf, &endptr, 10);
        if (errno == ERANGE || endptr == buf || (*endptr && *endptr != '\n')){   
        success = 0;
        return -2;
        }
            
        else
            success = 1;
    } while (!success);
    return 0;
}
int main(void)
{
    /* this will run forever until we call exit(0) in select_menu_item() */
    for(;;) {
        main_menu();
    }
    /* not reached */
    return 0;
}

 void main_menu(void)
{
    print_main_menu();
    {
        int input = get_user_input();
        select_menu_item(input);
    }
}

int get_user_input(void)
{
    enum { MENU_ITEMS = 3 };   /* 1,2 = items, 3 = Exit */
    char buf[128];
    int valid_input = 0;
    int value = 0;

    do {
        printf("\nSelect item: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            /* EOF or error; bail out gracefully */
            puts("\nInput error. Exiting.");
            exit(1);
        }

        // strip trailing newline
        buf[strcspn(buf, "\r\n")] = '\0';

        if (!is_integer(buf)) {
            printf("Enter an integer!\n");
            valid_input = 0;
        } else {
            value = (int)strtol(buf, NULL, 10);
            if (value >= 1 && value <= MENU_ITEMS) {
                valid_input = 1;
            } else {
                printf("Invalid menu item!\n");
                valid_input = 0;
            }
        }
    } while (!valid_input);

    return value;
}
/////////////////////////////////////get user input menu 2///////////////////////////

void select_menu_item(int input)
{
    switch (input) {
        case 1:
            menu_item_1();
            go_back_to_main();
            break;
        case 2:
            menu_item_2();
            go_back_to_main();
            break;

        default:
            printf("Bye!\n");
            exit(0);
    }
}

void print_main_menu(void)
{
    printf("\n----------- Main menu -----------\n");
    printf("\nChoose your path"
           "\t\t\t\t\t\t\n"
           "\t1. Buck converter\t\t\n"
           "\t2. FILE HANDLING\t\t\n"
           "\t3. Exit\t\t\t\t\n"
           "\t\t\t\t\t\t\n");
    printf("---------------------------------------------\n");
}



/* Return 1 if s is an optional [+/-] followed by one-or-more digits, else 0. */
int is_integer(const char *s)
{
    if (!s || !*s) return 0;

    /* optional sign */
    if (*s == '+' || *s == '-') s++;

    /* must have at least one digit */
    if (!isdigit((unsigned char)*s)) return 0;

    while (*s) {
        if (!isdigit((unsigned char)*s)) return 0;
        s++;
    }
    return 1;
}