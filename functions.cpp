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
* Definitions of the functions
*
*/


#include <iostream>
#include "functions.h"

using namespace std;

int validating_input(int difficulty_level) {

    int n_of_squares;

    if (!((difficulty_level == 1) || (difficulty_level == 2) || (difficulty_level == 3))) {
        cout << "Entered an invalid level of difficulty" << endl;
        n_of_squares = -1;
        return n_of_squares;
    } else {
        return difficulty_level;
    }
}

int determining_filled_squares(int value, int filled_squares_easy_level, int filled_squares_medium_level,
                               int filled_squares_hard_level) {

    switch (value) {
        case 1:
            return filled_squares_easy_level;
        case 2:
            return filled_squares_medium_level;
        case 3:
            return filled_squares_hard_level;
        default:
            cout << value;
            return -1;
    }
}

void board_printing(const char board[][9], const int n) {

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j == 8) {
                cout << board[i][j];
                break;
            }
            cout << board[i][j] << ' ';
        }
        cout << '\n';

    }

}

void board_fill(char b[][9], char c[][9], int n, char original_b[][9]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            b[i][j] = char(original_b[i][j]);
            c[i][j] = char(original_b[i][j]);
        }
    }
}

void boards_filling(char board[][9], char copy[][9], int level, char easy_level_b[][9], char medium_level_b[][9],
                    char hard_level_b[][9], int n) {
    if (level == 1) {
        board_fill(board, copy, n, easy_level_b);
    } else if (level == 2) {
        board_fill(board, copy, n, medium_level_b);
    } else if (level == 3) {
        board_fill(board, copy, n, hard_level_b);
    }
}

bool validating_indexes_and_number(int index1, int index2, int number) {

    bool valid = true;

    if (!((index1 >= 0 && index1 <= 8) && (index2 >= 0 && index2 <= 8))) {
        cout << "Invalid index!" << endl;
        valid = false;
    }

    if (!(number >= 0 && number <= 9)) {
        cout << "Invalid number!" << endl;
        valid = false;
    }

    return valid;
}

bool clearing_a_box(const char default_board[][9], int index1, int index2) {
    if ((default_board[index1][index2] == '_')) {
        return true;
    }
    cout << "Can't assign new value to the original board!" << endl;
    return false;
}

bool check_column(char default_board[][9], char board[][9], int r, int c, int v, int n) {

    bool available = true;

    for (int i = 0; i < n; ++i) {
        if (board[i][c] == char(v + 48)) {
            available = false;
            cout << "The number that you try to enter is already in this column!" << endl;
        }
    }

    if (available && (default_board[r][c] == '_')) {
        return true;
    }
    return false;
}

bool check_row(char default_board[][9], char board[][9], int r, int c, int v, int n) {

    bool available = true;

    for (int i = 0; i < n; ++i) {
        char row_v = board[r][i];
        if (row_v == char(v + 48)) {
            available = false;
            cout << "The number that you try to enter is already in this row!" << endl;
        }
    }

    if (available && (default_board[r][c] == '_')) {
        return true;
    }
    return false;
}

bool check_box(char default_board[][9], char board[][9], int r, int c, int v, int index1, int index2) {

    bool available = true;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i + r][j + c] == char(v + 48)){
                available = false;
                cout << "The number that you try to enter is already in 3x3 box!" << endl;
            }
        }
    }

    if (available && (default_board[index1][index2] == '_')) {
        return true;
    }
    return false;
}
