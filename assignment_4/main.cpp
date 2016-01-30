#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <sstream>

#include "polynomial.h"
#include "shwe_lib.h"

int main()
{
    Polynomial eq_1;
    cout << "Testing Constructor.\n";
    cout << "Printing equation 1.\n";
    eq_1.print();
    
    cout << "\nTesting read_data().\n" << flush;
    eq_1.read_data();
    cout << "Printing equation 1.\n";
    eq_1.print();

    int deg = eq_1.get_degree();

    cout << "\nTesting get_degree().\nDegree of equation is " << deg
         << endl << flush;

    cout << "\nTesting get_coefficient().\n";
    for (int i = 0; i <= deg; i++)
    {
        cout << "Coefficient of x^" << i << " is " << eq_1.get_coefficient(i)
             << endl;
    }

    string user_in;
    int i = 0;
    bool fail = false, done = false;
    stringstream s_strm;
    cout << "\nTesting set_coefficient().\n";
    do {
        do {
            fail = false;
            i = 0;
            cout << "Enter the power of equation or (q to quit editing): "
                 << flush;
            getline(cin, user_in);
            if (user_in == "q") {
                done = true;
                break;
            }
            test_user_in(user_in, i, fail, 'd');
            if (i > int(eq_1.get_degree())) {
                fail = true;
                cout << "Error!\n" << flush;
            }
        } while (fail);
        if (!done)
            eq_1.set_coefficient(cin_coefficient(i), i);
    } while (!done);
    
    cout << "\nDone changing coefficient.\n" << flush;
    cout << "\nPrinting edited equation 1.\n";
    eq_1.print();

    int size = eq_1.get_degree() + 1;
    Polynomial eq_2(size);
    srand (time(NULL));
    for (int i = 0; i <= size; i++)
        eq_2.set_coefficient(rand() % 10 + 1, i);
    cout << "Printing equation 2.\n";
    eq_2.print();

    cout << "\nTesting addition operator+.\n";
    cout << "nequation 3 = equation 1 + equation 2\n";
    Polynomial eq_3;
    eq_3 = eq_1 + eq_2;
    
    cout << "Printing equation 3.\n";
    eq_3.print();

    Polynomial eq_4;
    cout << "\nTesting negation operator-.\n";
    eq_4 = -eq_3;
    cout << "Printing - (equation 3).\n";
    eq_4.print();

    cout << "\nTesting multiply().\n";
    eq_3.multiply(5);
    cout << "Printing (5 * equation 3).\n";
    eq_3.print();
    return 0;
    
}


