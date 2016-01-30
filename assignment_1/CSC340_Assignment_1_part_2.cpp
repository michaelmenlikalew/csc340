/*
Problem 2: Implement another C++ program to sort a list of integers
using the selection sort algorithm. You are required to

    1. use an integer vector to store the input numbers typed from the
keyboard. The declaration of this vector will be in main(). You'll need
to implement a separate function readData() to read numbers from the
keyboard
    2. implement a separate function called selectionSort(), which will
be called by the main() function to sort the afore-mentioned vector
    3. implement another function printVector() to print out the content
of the vector. This function will be called by main() right after
calling readData() and selectionSort(), respectively, to print out the
vector content before and after being sorted.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*
 * read_data - get user input
 * @v: vector
 * @tmp: temporary variable
 * @usr_input: user input
 * @ssin stringstream object
 * 
 * read user input as a line and with string stream to extract
 * integer and put it into vector
 */
void read_data(vector<long>& v)
{
    string usr_input;
    long tmp;
    stringstream ssin;
    cout << "Please enter numbers followed by spaces: " << flush;
    getline(cin, usr_input);
    ssin.str(usr_input);
    while (ssin >> tmp) {
        v.push_back(tmp);
    }
}

/*
 * swap - swap two argument
 * @i: argument 1
 * @j: argument 2
 * @tmp: temporary variable
 * 
 * helper function for selection sort. swap two number seperated 
 * by comma.
 */
void swap(long& i, long& j)
{
    long tmp;
    tmp = i;
    i = j;
    j = tmp;
}

/*
 * selection_sort - just a regular selectoin sort
 * @v: vector
 * @indx: index
 * @i, j: iterator
 *
 * find index that is the smallest in the array with loop and swap
 * with current i^th array
 */
void selection_sort(vector<long>& v)
{
    cout << "\nSorting number.\n" << flush;
    long indx, size, i, j;
    size = v.size();
    for (i = 0; i < size; i++) {
        indx = i;
        for (j = i; j < size; j++) {
            if (v[indx] > v[j])
                indx = j;
        }
        swap(v[i], v[indx]);
    }
}

/*
 * print - print all number in vector
 * @v: vector
 * 
 * print all number in vector using loop for size of vector time
 */
void print(vector<long>& v)
{
    long size = v.size();
    cout << "The numbers in sorted order are: " << flush;
    for (int i = 0; i < size; i++) {
        if (i > 0)
            cout << ", ";
        cout << v[i] << flush;
    }
    cout << endl;
}


int main()
{
    vector<long> list;
    read_data(list);
    selection_sort(list);
    print(list);

    return 0;
}

