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
* Using a function to calculate the filled squares in the 3 boards
*
*/



int filled_squares_calculator(char board[][9], int n) {

    int counter = n * n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '_') {
                counter--;
            }
        }
    }
    return counter;
}
