#ifndef MENU2_H
#define MENU2_H

//gcc main.c funcs.c menu2.c -o main.out
void main_menu2(void);            /* runs in the main loop */
void print_main_menu2(void);      /* output the main menu description */
int  get_user_input2(void);       /* get a valid integer menu choice */
void select_menu_item2(int input);/* run code based on user's choice */
void go_back_to_main2(void);      /* wait for 'b'/'B' to continue */


#endif