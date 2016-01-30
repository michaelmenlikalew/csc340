#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int get_num(const string &s, bool &fail);
/*
 * is_number - check to see if c is a number
 * @c: character
 *
 * if c is between 1 and 9, return true.
 */
bool is_number(char &c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

/*
 * is_alphabet - testing to see if c is alphabet
 */
bool is_alphabet(const char &c)
{
    if ((c <= 'z' && c >= 'a') ||
        (c <= 'z' && c >= 'A'))
            return true;
    return false;
}

/*
 * is_delim - testing to see if c is delimiter
 */

bool is_delim(const char &c)
{
    if (c == ',' || c == '.' || c == ';' || c == '?')
        return true;
    return false;
}

/*
 * set_lower - set whole string to lower case
 * @s: string
 * 
 * using a loop to loop through whole string and
 * set every character to lower case letter
 */
/*void set_lower(string &s)
{
    for (int i = 0; s[i]; i++) {
        s[i] = tolower(s[i]);
    }
}
*/
/*
 * is_space - if the charater is space
 * @c: character
 *
 * if c is space, return true
 * else, return fales
 */
bool is_space(const char &c)
{
    if (c == ' ')
        return true;
    return false;
}

/*
 * test_user_in - test if user enter correctly
 * @user_in: user input
 * @n: number of power
 * @fail: bool counter
 * @c: character from function caller
 *
 * get the number from console by calling get_num function.
 * if user enter empty string, then it fails, print Error.
 */
void test_user_in(string &user_in, int &n, bool &fail, char c)
{
    if (!user_in.empty())
        n = get_num(user_in, fail);
    if (user_in.empty() || fail || (n < 0 && c == 'd')) {
        fail = true;
        cout << "Error!\n" << flush;
    }
}

/*
 * cin_degree - get the degree from user input
 *
 * get line from console and test user input by calling test_user_in function
 */
unsigned int cin_degree()
{
    string user_in;
    int deg = 0;
    bool fail = false;
    do {
        fail = false;
        cout << "Please enter max degree: " << flush;
        getline(cin, user_in);
        test_user_in(user_in, deg, fail, 'd');
    } while (fail);
    return deg;
}

/*
 * cin_coefficient - get coefficient from console
 * int i: power
 *
 * get line from console and test user input by calling test_user_in function
 */
int cin_coefficient(int i)
{
    int num;
    string user_in;
    bool fail = false;
    do {
        fail = false;
        cout << "Please enter coefficient for x^" << i << ": " << flush;
        getline(cin, user_in);
        test_user_in(user_in, num, fail, 'c');
    } while (fail);
    return num;
}

/*
 * get_num - get number from string
 * @s: string
 * @fail: bool counter
 *
 * insert string into stringstream and ignore as much space then get integer
 * and return it
 */
int get_num(const string &s, bool &fail)
{
    int n = 0;
    stringstream s_strm(s);
    while (is_space(s_strm.peek())) {
        s_strm.get();
    }
    s_strm >> n;
    if (s_strm.fail())
        fail = true;
    return n;
}
