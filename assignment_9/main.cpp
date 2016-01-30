/* Shwe Aye
 * 915827905
 * saye@mail.sfsu.edu
 * Assignment 9
 * Dec. 7, 2015
 * I used g++ compiler on Linux(GNU)/Unix.
 *
 *
 * For each of the following problems, write a function that solves the problem
 * recursively. No for loops or while loops allowed! You should test each
 * function in your main method. You should just submit a single .cpp file. No
 * separate compilation needed.

 * Problem 1

 * Write a function that takes a string and returns true if that string is a
 * palindrome and false otherwise. The function should look like this:

 * bool isPalindrome(const string& input) {}



 * Problem 2

 * Write a function that takes an integer and returns the sum of its digits.
 * For this function, you will have to make clever use of the / and % operators!
 * Your function should look like this:

 * int digitSum(int input) {}



 * Problem 3

 * You are standing at the base of a staircase. At each step as you climb the
 *  staircase, you have the option of taking a small stride (one stair) or a
 * large stride (two stairs - assuming there are at least two stairs remaining).
 * Given that a staircase has X number of stairs, how many ways are there to
 * climb the staircase using different combinations of small and large strides? 
 * Write a function that takes a total number of stairs in the staircase and
 * returns the number of ways to climb it. If the staircase has three steps, for
 * example, there are three ways to climb it (three small strides, or a large
 * stride followed by a small stride, or a small stride followed by a large
 * stride). Your function should look like this:

 * int waysToClimb(int numStairs) {}
 */

#include <iostream>

#include "shwe_lib.cpp"

using namespace std;

int digit_sum(int input);
bool is_palindrome(const string &input);
void print_palindrome_result(const string &input);
int ways_to_climb(int num_stairs);

int main()
{
    string inp = "";
//    string inp = "taco cat",
    string inp2 = "abcdefg";
    print_palindrome_result(inp);
    print_palindrome_result(inp2);

//    int phi = 531753153;
    int phi = 0;
    cout << "Digit Sum of " << phi << " is " << digit_sum(phi) << endl;

    for (int num_stair = 0; num_stair < 10; num_stair++) {
        cout << "Number of ways to climb " << num_stair << " stairs is "
             << ways_to_climb(num_stair) << endl;
    }
    return 0;
}

/*
 * fix_string - fix strong for palindrome
 * @s: string
 *
 * delete character that aren't English character
 */
string fix_string(string s)
{
    int sig = s.size();
    if (sig <= 1)
        return s;
    if (!is_alphabet(s[0])) {
        s.erase(0, 1);
        sig--;
    }
    tolower(s[0]);
    return s[0] + fix_string(s.substr(1, sig));
}

/*
 * reverse_string - reverse input string
 * @s: string
 *
 * reverse the string so that it can be compare with input string
 */
string reverse_string(const string &s)
{
    int sig = s.size();
    if (sig <= 1)
        return s;
    return reverse_string(s.substr(1, sig)) +  s[0];
}

/*
 * is_palindrome - test if the input string is palindrome
 * @input: input string
 *
 * delete non-character in the string and put reverse of the string to the 
 * tmp and compare with input string to see if it is palindrome
 */
bool is_palindrome(const string &input)
{
    string org = input;
    org = fix_string(org);
    string tmp = reverse_string(org);
    if (tmp == org)
        return true;
    return false;
}

/*
 * print_palindrome_result - helper function to print from main
 * @inp: input
 *
 * print if the string is palindrome or not
 */
void print_palindrome_result(const string &inp)
{
    if (is_palindrome(inp)) {
        cout << inp << " is palindrome.\n";
    } else {
        cout << inp << " is not palindrome.\n";
    }
}

/*
 * digit_sum - sum all the digit of the number
 * 
 * get the remainder of current last value and cut the last value and repeat
 */
int digit_sum(int input)
{
    if (input < 10)
        return input;
    return input % 10 + digit_sum(input / 10);
}

int fib(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return fib(n - 2) + fib(n - 1);
}

/*
 * ways_to_climb - number of ways to climb the stair
 * 
 * num stair is just fibonacci number so after 0, 1, just return fib value
 */
int ways_to_climb(int num_stairs)
{
    if (num_stairs == 0)
        return 0;
    else if (num_stairs == 1)
        return 1;
    return fib(num_stairs);
}

