/* Shwe Aye
 * 915827905
 * saye@mail.sfsu.edu
 * Assignment 2 Part 2
 * Sep. 18, 2015
 * I used g++ compiler on Linux(GNU)/Unix.
 */

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "../../Shwe_Lib/shwe_lib.cpp"

using namespace std;

bool test_file(ifstream& fin, string &file);
void get_user_input(string& usr_in);
bool open_files(string& usr_in, ifstream& fin_1, ifstream& fin_2);
void print_file_error(string& s);
bool is_sorted(ifstream &fin);

bool test_file(ifstream& fin, string &file)
{
    fin.open(file.c_str());
    if (fin.fail()) {
        print_file_error(file);
        return false;
    }
    return true;
}

void get_user_input(string& usr_in)
{
    cout << "Ready to merge file.\n"
         << "Enter the name of two files seperated by space: "
         << flush;
    getline(cin, usr_in);
}

bool open_files(string& usr_in, ifstream& fin_1, ifstream& fin_2)
{
    string file_1, file_2;
    stringstream sstrm(usr_in);
    sstrm >> file_1 >> file_2;
    bool passed;
    passed = test_file(fin_1, file_1);
    if (passed)
        passed = test_file(fin_2, file_2);
    return passed;
}

void print_file_error(string& s)
{
    cout << "ERROR opening " << s << '.'<< endl;
}

void finish(ifstream& fin, ofstream& fout, int& tmp)
{
    do {
        fout << tmp << endl;
    } while (fin >> tmp);
}

void merge_files(ifstream &fin_1, ifstream& fin_2)
{
    ofstream fout;
    int x, y;
    bool x_done, y_done;
    if (!is_sorted(fin_1))
        return;
    if (!is_sorted(fin_2))
        return;
    x_done = y_done = false;
    fout.open("merged_file.txt");
    cout << "Both files are merged into \"merged_file.txt\"\n";
    if (!(fin_1 >> x)) {
        x_done = true;
    }
    if (!(fin_2 >> y)) {
        y_done = true;
    }
    while (!x_done && !y_done) {
        if (x <= y) {
            fout << x << endl;
            if (!(fin_1 >> x))
                x_done = true;
        } else if (x > y) {
            fout << y << endl;
            if (!(fin_2 >> y))
                y_done = true;
        }
    }
    if (x_done && !y_done)
        finish(fin_2, fout, y);
    else if (y_done && !x_done)
        finish(fin_1, fout, x);
    fout.close();
}

bool is_sorted(ifstream &fin)
{
    string s;
    bool passed;
    vector<int> v;
    int x, size;
    stringstream sstrm;
    while (fin >> s) {
        size = s.size();
        for (int i = 0; i < size; i++) {
            passed = is_number(s[i]);
            if (!passed) {
                cout << "ERROR. not integer.\n";
                return false;
            }
        }
        sstrm.str(s);
        sstrm >> x;
        v.push_back(x);
        sstrm.str(string());
        sstrm.clear();
    }
    size = v.size();
    for (int i = 0; i < size - 1; i++) {
        if (v[i] > v[i + 1]) {
            cout << "ERROR. not sorted.\n";
            return false;
        }
    }
    fin.clear();
    fin.seekg(0, fin.beg);
    return true;
}

int main()
{
    ifstream fin_1, fin_2;
    stringstream sstrm;
    string usr_in;
    bool passed;
    get_user_input(usr_in);
    passed = open_files(usr_in, fin_1, fin_2);
    if (passed)
        merge_files(fin_1, fin_2);
    fin_1.close();
    fin_2.close();
    
    return 0;
}
