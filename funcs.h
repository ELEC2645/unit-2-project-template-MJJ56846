//gcc main.c funcs.c -lm -o main.out
#ifndef FUNCS_H
#define FUNCS_H

///////////////////////////Test menu////////////////////////
void menu_test(void);
///////////////////////////FILE HANDLING////////////////////////
void save_file(const char *label, float val);
void load_file(void);
void clear_file(void);
///////////////////////////menu 1////////////////////////
void menu_item_1(void);
void menu_item_2(void);
///////////////////////////menu 2////////////////////////
void menu2_item_1(void);
void menu2_item_2(void);
void menu2_item_3(void);
void menu2_item_4(void);
///////////////////////////menu 3////////////////////////
void menu3_item_1(void);
void menu3_item_2(void);
void menu3_item_3(void);
void menu3_item_4(void);
////////////////////////////menu 4//////////////////////
void menu4_item_1(float IO);
void menu4_item_2(float ts);
void menu4_item_3(float vi);
void menu4_item_4(float ts,float vo,float L);
void menu4_item_5(float ts, float vo, float L);
void menu4_item_6(float vo);
///////////////////////////menu 5///////////////////////
void menu5_item_1(float IO, float IOB_MAX, float vi);
void menu5_item_2(float IO, float IOB_MAX, float vo);


////////////////////////////////////Find Vo/Vi menu items/////////////////////////////////


/////////////////////menu 6//////////////////////////
void menu6_item_1(void);
/////////////////////menu 7//////////////////////////
void menu7_item_1(void);
void menu7_item_2(void);
void menu7_item_3(void);
void menu7_item_4(void);
void menu7_item_5(void);
/////////////////////menu 8////////////
void menu8_item_1(float K, float vi);
void menu8_item_2(float IO, float IOB_MAX, float vi, float K);
void menu8_item_3(float K, float vi);
void menu8_item_4(float IO, float IOB_MAX, float vo, float K);


//////////////////////////////////FILE HANDLING MENUS//////////////////////////

//////////////////////////////menu 9 items//////////////////////
void menu9_item_load(void);
void menu9_item_clear(void);


/////////////Important functions needed in funcs////////
int ask_number(int *out_number);
int ask_numberf(float *out_number);
void main_menu(void); 
void go_back_to_main(void);
void select_menu_item(int num1);


////////////////////////////////Math section////////////////////////////
//Buck vi and vo
void menu3_item_Vi(float IO);
void menu3_item_Vo(float IO);
void menu3_item_Vo_given(float IO, float vo);
//Buck vi and vo (given K)
void menu7_item_Vi(float IO, float K);
void menu7_item_Vo(float IO, float K);
void menu7_item_Vo_given(float IO, float K, float vo);


//Buck IOB(Max)
void IOBMAX_CVI_BUCK(float vi ,float L, float ts, float *iobmax);
void IOBMAX_CVO_BUCK(float vo ,float L, float ts, float *iobmax);


#endif