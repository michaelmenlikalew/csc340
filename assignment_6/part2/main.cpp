/* Shwe Aye
 * 915827905
 * saye@mail.sfsu.edu
 * Assignment 6 Part 2
 * Oct. 31, 2015
 * I used g++ compiler on Linux(GNU)/Unix.
 */


#include <iostream>

#include "part2.cpp"

using namespace std;

/*
 * tester file
 */
int main()
{
    Account accnt1(173.3715);
    double val = 5.513;
    try {
        cout << "Initial account value: " << accnt1.getBalance() << endl;

        cout << "Deposit " << val << ".\n";
        accnt1.deposit(val);
        cout << "current account value: " << accnt1.getBalance() << endl;

        cout << "Deposit -10.\n";
        accnt1.deposit(-10);
        cout << "current account value: " << accnt1.getBalance() << endl;
        
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    try {
        val = 12.531;
        cout << "current account value: " << accnt1.getBalance() << endl;

        cout << "withdraw " << val << ".\n";
        accnt1.withdraw(val);
        cout << "current account value: " << accnt1.getBalance() << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    try {
        val = -734.531;
        cout << "withdraw " << val << ".\n";
        accnt1.withdraw(val);
        cout << "current account value: " << accnt1.getBalance() << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }

    try {
        val = 1537284.35417528;
        cout << "withdraw " << val << ".\n";
        accnt1.withdraw(val);
        cout << "current account value: " << accnt1.getBalance() << endl;
    } catch (exception &e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
        
    
