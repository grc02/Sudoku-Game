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
* Executing the program/ application
*
*/

#include <iostream>
#include "functions.h"
#include "boards.h"
#include "texts.h"

using namespace std;

int main() {


    // Declaring and defining my variables and data structures
    char board[n][n], copy_of_the_original_board[n][n];
    int difficulty_level, n_of_filled_squares, value, index1, index2, number;
    int filled_squares_easy_level, filled_squares_medium_level, filled_squares_hard_level;
    bool v;

    // Printing out a welcoming message and preparing some data with the 3 functions after introduction_text()
    introduction_text();
    filled_squares_easy_level = filled_squares_calculator(easy_level_board, n);
    filled_squares_medium_level = filled_squares_calculator(medium_level_board, n);
    filled_squares_hard_level = filled_squares_calculator(hard_level_board, n);

    cin >> difficulty_level;

    // Validating the input and filling the boards that I will need depending on what the user chose as a difficulty
    value = validating_input(difficulty_level);
    if (value == -1) {
        cout << "Need to start a new game with a valid difficulty level!";
    } else {

        n_of_filled_squares = determining_filled_squares(value, filled_squares_easy_level, filled_squares_medium_level, filled_squares_hard_level);
        boards_filling(board, copy_of_the_original_board, difficulty_level, easy_level_board, medium_level_board, hard_level_board, n);
        board_printing(board, n);

        // Main logic of the program
        while (n_of_filled_squares < 81) {

            bool approved = false, c_check, r_check, b_check;

            cin >> index1 >> index2 >> number;

            // Checking if the user wants to stop playing
            if ((index1 == -1) && (index2 == -1) && (number == -1)) {
                cout << "Thank you for playing!" << endl;
                break;
            }

            v = validating_indexes_and_number(index1, index2, number);// Validation of the indexes and the number

            if (!v) {
                continue;
            }

            // Making sure that the indexes and everything with the input is correct
            if (number == 0) {
                approved = clearing_a_box(copy_of_the_original_board, index1, index2);
            } else {
                c_check = check_column(copy_of_the_original_board, board, index1, index2, number, n);
                r_check = check_row(copy_of_the_original_board, board, index1, index2, number, n);
                b_check = check_box(copy_of_the_original_board, board, (index1 - index1 % 3), (index2 - index2 % 3), number, index1, index2);
            }

            if (r_check && c_check && b_check) {
                if (board[index1][index2] == '_'){
                    n_of_filled_squares++;
                }
                board[index1][index2] = char(number + 48);
            }
            if (approved) {
                board[index1][index2] = '_';
                n_of_filled_squares--;
            }

            board_printing(board, n);

        }

        if (n_of_filled_squares == 81) {
            ending_text();
        }
    }

    return 0;
}
