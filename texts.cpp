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
* Definitions for the 2 functions which are created to output text
*
*/

#include <iostream>
#include "texts.h"

using namespace std;

void introduction_text() {

    cout << "Before you start, please choose the level of difficulty: " << endl;
    cout << "Easy: 1" << endl;
    cout << "Medium: 2" << endl;
    cout << "Hard: 3" << endl;
    cout << "Keep in mind that you can always stop the game after every move. You can do that by entering: -1" << endl;
    cout << "in your next move for the 3 inputs - index1 (row), index2 (column) and number!" << endl;

}

void ending_text() {

    cout << "Congratulations, you won! Thank you for playing!";
}
