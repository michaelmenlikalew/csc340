/*
Problem 1. Implement a C++ program that has the following functions:
    1. Reads in a paragraph of English text up to 100 words from the
keyboard and stores this paragraph in a string object. Feel free to 
include this task in the main() function.
    2. Identifies the least frequent letter (case insensitive) in the 
above paragraph. Implement a separate function getLeastFreqLetter() 
for this task. The main() function then calls this function to find 
out the least frequent letter and its frequency.
    3. Calculate the frequency of each unique word (case insensitive). 
Implement another function countWordFreq() for this task. Use white 
spaces and punctuation marks such as comma, period, semicolon and 
question mark as word delimiters. Please define a global struct that 
contains two fields, word and its count for this task. You can then 
define an array of this struct to store all the unique words and its 
counts. The main() function will call this function to print out each 
word and its corresponding frequency.
    4. Identify the most frequently occurring word in the paragraph. 
Implement another stand-alone function getMostFreqWord() for this
purpose. This function will be called in main() to identify the most
frequent word and its respective frequency.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include "shwe_lib.cpp"

using namespace std;

const int T_SIZE = 151;
const int ALPH_SIZE = 26;

/*
 * struct Letter_Bag - struct to hold paragraph & 26 letters
 * @word: basically  hold a paragraph but typing paragraph is so long
 * @letter[]: hold 26 letter from a-z
 * 
 * using struct is better than two different vector and array
 * floating around so putting them into one is better
 */
struct Letter_Bag
{
    string word;
    int letter[ALPH_SIZE];
};

/*
 * struct Word_Bag - struct to hold word and count of that word
 * @wrd: word
 * @cnt: count
 * 
 * putting the word and the count of it in a struct is much
 * easier to do
 */
struct Word_Bag
{
    string wrd;
    int cnt;
    Word_Bag equal(const Word_Bag& other);
};

void set_zero(Letter_Bag& p);
int get_least_freq_letter(Letter_Bag& p);
void count_letter_freq(Letter_Bag& p);
void count_word_freq(Word_Bag* w_list, const string& s);
int Universal_hash(string s);
void print_word_list(const Word_Bag& w_list);
void get_most_freq(const Word_Bag& w_list);
void get_paragpaph(string& s);

/*
 * set_zero_letter - set array of 26 letters to 0
 * @p: struct that hold paragraph
 * 
 * setting array of 26 to 0 so that it doesn't have garbage
 * in that memory which value is greater than 1
 */
void set_zero_letter(Letter_Bag& p)
{
    for (int i = 0; i < ALPH_SIZE; i++) {
        p.letter[i] = 0;
    }
}

/*
 * get_least_freq_letter - get least frequent letter from a paragraph
 * @p: paragraph
 * @idx: index
 * @val: value
 * 
 * set initial value to big number then test if count of letters
 * in array are smaller that value. If true, then assign to value
 */
int get_least_freq_letter(Letter_Bag& p)
{
    set_zero_letter(p);
    count_letter_freq(p);
    int indx, val = 9999;
    for (int i = 0; i < ALPH_SIZE; i++) {
        if (val > p.letter[i] && p.letter[i] > 0) {
            indx = i;
            val = p.letter[i];
        }
    }
    return indx;
}

/*
 * count_letter_freq - count frequency of letters in array
 * @indx = index of array
 * 
 * count letter freq until the end of string
 * idx is equal to alphabet - 'a' to get array
 * between 0-25, which is a-z
 */
void count_letter_freq(Letter_Bag& p)
{
    int indx, len;
    len = p.word.length();
    for (int i = 0; i < len; i++) {
        if (is_alphabet(p.word[i])) {
            indx = p.word[i];
            indx -= 'a';
            p.letter[indx]++;
        }
    }
}

/*
 * set_zero_count - set all word count 0
 * @w: word
 * 
 * setting all word count to 0 to play safe
 */
void set_zero_count(Word_Bag& w)
{
    for (int i = 0; i < T_SIZE; i++) {
        w.cnt = 0;
    }
}

/*
 * count_word_freq - count frequency of each word
 * @tmp: temporary variable
 * @h: hash value
 * 
 * while loop test if array slot has already been
 * taken just to be safe
 * If the slot is temp string, count add 1
 * 
 */
void count_word_freq(Word_Bag* w_list, const string& s)
{
    string tmp;
    int h;
    istringstream ssin(s);
    while (ssin >> tmp) {
        h = Universal_hash(tmp);
        while (w_list[h].wrd != tmp && w_list[h].cnt != 0) {
            h++;
        }
        w_list[h].wrd = tmp;
        w_list[h].cnt++;
    }
}

/*
 * Universal hashing - hash value for constant lookup
 * @h: hash value
 * 
 * h = ((h * a) + x[i])) mod p, a < p, p = prime
 */
int Universal_hash(string s)
{
    int h = 0;
    for (int i = 0; s[i]; i++) {
        h = ((h * 181) + s[i]) % T_SIZE;
    }
    return h;
}

/*
 * print_word_list - print the whole word list
 * @w_list: word list
 * 
 * print everything except the size of 0 because
 * Table size is not vector, this isn't push back method.
 */
void print_word_list(const Word_Bag* w_list)
{
    cout << setw(17) << left << "Word " << "| Counts\n";
    for (int i = 0; i < T_SIZE; i++) {
        if (w_list[i].cnt > 0) {
            cout << setw(17) << left << w_list[i].wrd <<
                "| " << w_list[i].cnt << endl << flush;
        }
    }
    cout << endl;
}

/*
 * get_most_freq - get the most frequency form the word list
 * @tmp: temporary Struct
 * 
 * put random array list of word in tmp, 0th element of
 * an array in this case. Compare temp with i^th array list
 * if i^th arry list is larger, assign that to tmp
 * If reached the end of the list, print out the word.
 */
void get_most_freq(const Word_Bag* w_list)
{
    Word_Bag tmp;
    tmp.equal(w_list[0]);
    for (int i = 0; i < T_SIZE; i++) {
        if (tmp.cnt < w_list[i].cnt)
            tmp.equal(w_list[i]);
    }
    cout << "most freq word is \"" << tmp.wrd << "\" with " <<
        tmp.cnt << " counts.\n";
}

/*
 * equal - member function of struct to copy
 * @other: temporary Word_Bag object
 * 
 * deep copy other object to this.
 */
Word_Bag Word_Bag::equal(const Word_Bag& other)
{
    this->cnt = other.cnt;
    this->wrd = other.wrd;
    return *this;
}

/*
 * get_paragraph: get usr_input
 * @s: string
 * 
 * get usr_input as paragraph to store everything
 */
void get_paragraph(string& s)
{
    cout << "Please enter a paragraph up to 100 word: ";
    getline(cin, s);
    cout << endl;
}

/*
 * test_usr_input: check user input about word
 * @s: string
 * 
 * test user input whether they input blank string
 * if user input is blank or space, return false or
 * true otherwise.
 */
bool test_usr_input(const string& s)
{
    for (int i = 0; s[i]; i++) {
        if (is_alphabet(s[i]))
            return true;
    }
    return false;
}

/*
 * del_delim: delete everything that is not alphabet
 * @s: string
 * 
 * delete everything that isn't alphabet, such as: string,
 * comma, paranthesis, semicolon, colon, etc.
 */ 
void del_delim(string &s)
{
    for (int i = 0; s[i]; i++) {
        if (!is_alphabet(s[i])) {
            s[i] = ' ';
        }
    }
}

int main()
{
    string usr_input;
    char indx;
    bool pass;
    do {
        get_paragraph(usr_input);
        pass = test_usr_input(usr_input);
    } while (!pass);
    del_delim(usr_input);
    set_lower(usr_input);
    Letter_Bag prgraph;
    prgraph.word = usr_input;
    
    indx = get_least_freq_letter(prgraph) + 'a';
    cout << indx << " is the least frequent letter.\n\n";
    
    Word_Bag* w_list = new Word_Bag[T_SIZE];
    count_word_freq(w_list, usr_input);
    print_word_list(w_list);
    get_most_freq(w_list);
    delete[] w_list;
    
    return 0;
}
