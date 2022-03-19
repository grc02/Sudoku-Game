/**
*
* Solution to course project # <номер на вариант>
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Chonkov
* @idnumber 0MI0600130
* @compiler GCC
*
* Declaring my functions
*
*/

#ifndef DEMO_FUNCTIONS_H
#define DEMO_FUNCTIONS_H

int validating_input(int difficulty_level);

int determining_filled_squares(int value, int filled_squares_easy_level, int filled_squares_medium_level, int filled_squares_hard_level);

void board_printing(const char board[][9], int n);

void boards_filling(char board[][9], char copy[][9], int level, char easy_level_b[][9], char medium_level_b[][9], char hard_level_b[][9], int n);

void board_fill(char b[][9], char c[][9], int n, char original_b[][9]);

bool validating_indexes_and_number(int index1, int index2, int number);

bool clearing_a_box(const char default_board[][9], int index1, int index2);

bool check_column(char default_board[][9], char board[][9], int r, int c, int v, int n);

bool check_row(char default_board[][9], char board[][9], int r, int c, int v, int n);

bool check_box(char default_board[][9], char board[][9], int r, int c, int v, int index1, int index2);

#endif //DEMO_FUNCTIONS_H
