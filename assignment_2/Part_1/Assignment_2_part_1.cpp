/* Shwe Aye
 * 915827905
 * saye@mail.sfsu.edu
 * Assignment 2 Part 1
 * Sep. 18, 2015
 * I used g++ compiler on Linux(GNU)/Unix.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

#include "../../Shwe_Lib/shwe_lib.cpp"

using namespace std;

typedef vector< vector<double> > vector2D;

bool is_number(char& c);
void get_size(string out, int v_num, string& s);
void test_input_size(string& tmp, bool& fail);
void make_matrix_vector(vector2D& tmp, int& m, int& n);
void make_vector(string &s, vector2D& v,vector2D& u);
void get_vector_size(string& s);
void print_matrix(vector2D& tmp);

/*
 * get_size - helper function for get_vector_size()
 * @out: output string to the screen
 * @v_num: vector number. e.g: 1, 2, or 3
 * @s: string for usr_input
 * @tmp: tmp string for user input
 * @fail: bool for loop counter
 *
 * get user input, then test user input. if user input isn't a number,
 * try again. when done, add tmp string to a user_input
 */
void get_size(string out, int v_num, string& s)
{
    bool fail = true;
    string tmp;
    do {
        cout << "enter " << out << " size of vector " <<
            v_num << ": " << flush;
        while (cin.peek() == ' ')
            cin.get();
        getline(cin, tmp);
        test_input_size(tmp, fail);
    } while (fail);
    s += tmp + ' ';
}

/*
 * test_input_size - helper funcion for get_size()
 * @tmp: string containing user input
 * @fail: loop counter from get_size()
 * @size: size of tmp
 * @str_stream: stringstream variable
 *
 * put tmp into str_stream, skip all while spaces, put back string into tmp
 * after there are no while space and test tmp to see if it is an integer
 * if not, return from function
 */
void test_input_size(string& tmp, bool& fail)
{
    if(tmp.empty() || !is_number(tmp[0])) {
        cout << "ERROR. try again\n";
        return;
    }
    int size = tmp.size();
    for (int i = 0; i < size; i++) {
        if (!is_number(tmp[i])) {
            fail = true;
            cout << "ERROR. try again.\n";
            return;
        }
    }
    fail = false;
}

/*
 * make_matrix_vector - helper function
 * @tmp: temporary vector
 * @m: row
 * @n: column from linear algebra notation?
 * 
 * make 2d vector and fill them with any number, should be 0 in general
 */
void make_matrix_vector(vector2D& tmp, int& m, int& n)
{
    for (int i = 0; i < m; i++) {
        tmp.push_back(vector<double>());
        for (int j = 0; j < n; j++)
            tmp[i].push_back(0);
    }
}

/*
 * make_vector - get numbers from string to 3 variable
 * @m: row of vector 1
 * @n: column of vector 1
 * @n: column of vector 2
 * @s: string containing 3 variable
 * @u, v: vectors
 *
 * put string into stringstream
 * extract 3 variable from stringstream and put into row and column variables
 */
void make_vector(string &s, vector2D& u,
                 vector2D& v)
{
    int m, n, n2;
    stringstream str_stream(s);
    str_stream >> m >> n >> n2;
    make_matrix_vector(u, m, n);
    make_matrix_vector(v, n, n2);
}

/*
 * print_size - print the size of vector
 * @s: string containing size
 * @m, n: row and column of vector 1
 * @n2: column of vector 2
 * @str_stream: stringstream object
 *
 * put string into stringstream and extract the numbers
 * when finish, print out to screen in m x n format.
 */
void print_size(string& s)
{
    stringstream str_stream(s);
    int m, n, n2;
    m = n = n2 = 0;
    str_stream >> m >> n >> n2;
    cout << "\nsize of vectors are: " << m << 'x' << n << " and "
         << n << 'x' << n2 << ". Resulting vector is: " << m << 'x' << n2
         << ".\n" << flush;
}

/*
 * get_vector_size - get the size of vector
 * @s: user input in string variable
 *
 * get the size of row x column of 2 vectors and print the size back to
 * the screen. Everything is taking care by the helper function to prevent
 * code rewriting.
 */
void get_vector_size(string& s)
{
    get_size("row", 1, s);
    get_size("colunm", 1, s);
    get_size("column", 2, s);
    print_size(s);
}

/*
 * print_matrix - print 2d vector
 * @tmp: temporary vector to print 
 * @clmn: column
 *
 * loop through 2d vector and print out the the screen
 */
void print_matrix(vector2D& tmp)
{
    for (unsigned int row = 0; row < tmp.size(); row++) {
        for (unsigned int clmn = 0; clmn < tmp[0].size(); clmn++) {
            cout << setw(5) << tmp[row][clmn];
        }
        cout << endl;
    }
}

/*
 * goto_num - go to next number
 * 
 * if comma or space is in the way, step over it until number is found.
 */
void goto_num(stringstream& str_stream)
{
    do {
        if (str_stream.peek() == ',') {
            str_stream.get();
            break;
        } else if (str_stream.peek() == ' ') {
            str_stream.get();
        } else {
            break;
        }
    } while (str_stream);
}

/*
 * get_number - skip space and comma then get the next number
 * @str_stream: stringstream
 * @num = number
 *
 * while next character is stringstream is space or comma then return 0
 * if it is a number, get the number and get comma
 */
int get_number(stringstream &str_stream)
{
    char c;
    int num = 0;
    do {
        c = str_stream.peek();
        if (c == ' ') {
            str_stream.get();
        } else if (c == ',') {
            str_stream.get();
            return 0;
        } else if (is_number(c)) {
            str_stream >> num;
            goto_num(str_stream);
            break;
        } else {
            break;
        }
    } while (str_stream);
    return num;
}

/*
 * make_matrix_number - get the number for matrix and fill it into matrix
 * @v_letter: vector letter
 * @tmp: any matrix passed from
 *
 * get all the number from user. If user didn't enter anything, they will be
 * zeros. After getting number from user, put those back to stringstream then
 * extract number back from string stream
 */
void make_matrix_number(vector2D& tmp, char v_letter)
{
    unsigned int row_size = tmp.size(), col_size = tmp[0].size();
    string user_in;
    stringstream str_stream;
    cout << "\nCells for vector " << char(toupper(v_letter))
         << " will be filled with 0's if the numbers aren't entered.\n"
         << "\nEnter the number seperated by comma or space.\n"
         << "More than 1 space will be treated as single space.\n";
    for (unsigned int i = 0; i < col_size; i++) {
        //get user input
        cout << "Please enter " << row_size << " numbers for " << v_letter << (i + 1)
             << ": ";
        while (cin.peek() == ' ')
            cin.get();
        getline(cin, user_in);
        if (user_in.empty())
            cout << "initializing numbers to 0 for vector " << v_letter
                 << (i + 1) << ".\n";
        //put number into the matrix
        str_stream.str(user_in);
        for (unsigned int j = 0; (j < row_size) && str_stream; j++) {
            tmp[j][i] = get_number(str_stream);
        }
        str_stream.clear();
    }
}

/*
 * multiply_matrix - multiply the two matrix
 * 
 * multiply the two matrix, the formula is Aik * bkj
 */
vector2D multiply_matrix(vector2D& u, vector2D& v)
{
    int row = u.size(), col = v[0].size(), m = u[0].size();
    vector2D tmp_matrix;
    make_matrix_vector(tmp_matrix, row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < m; k++) {
                tmp_matrix[i][j] += u[i][k] * v[k][j];
            }
        }
    }
    return tmp_matrix;
}

int main()
{
    vector2D u, v;
    string usr_in;
    get_vector_size(usr_in);
    make_vector(usr_in, u, v);
    make_matrix_number(u, 'u');
    make_matrix_number(v, 'v');
    
    cout << "\nVector U\n";
    print_matrix(u);
    
    cout << "\nVector V\n";
    print_matrix(v);
    vector2D m = multiply_matrix(u, v);
    
    cout << "\nResult of U x V\n";
    print_matrix(m);
    
    return 0;
}


