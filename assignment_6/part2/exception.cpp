/* Shwe Aye
 * 915827905
 * saye@mail.sfsu.edu
 * Assignment 6 Part 2
 * Oct. 31, 2015
 * I used g++ compiler on Linux(GNU)/Unix.
 */

#include "exception.h"

using namespace std;

const char* Exception_Negative_Deposit::what() const throw() {
    return "can't deposit negative amount!";
}

const char* Exception_Negative_Withdraw::what() const throw() {
    return "can't withdraw negative amount!";
}

const char* Exception_Overdraw::what() const throw() {
    return "not enough amount!";
}
