/* Shwe Aye
 * 915827905
 * saye@mail.sfsu.edu
 * Assignment 2 Part 2
 * Sep. 18, 2015
 * I used g++ compiler on Linux(GNU)/Unix.
 */

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*
 * read_data - read data from the file
 * @fin: fine in just like cin
 * @pos: position
 * @data: vector of int that contain data
 * 
 * read data from the file until the end of the file and put the number
 * onto the vector
 */
void read_data(fstream& fin, const long& pos, vector<string>& data)
{
    string tmp;
    fin.seekg(pos);
    while (fin >> tmp) {
        data.push_back(tmp);
    }
}

/*
 * write_data - write the data back to the file
 * 
 * go to the position write number from 7777 to 7781 and continue to
 * write the rest of data back to the file.
 */
void write_data(fstream& fout, const long& pos, vector<string>& data)
{
    unsigned int size = data.size();
    fout.seekp(pos);
    for (int n = 7777; n <= 7781; n++) {
        fout << n << endl;
    }
    for (unsigned int i = 0; i < size; i++) {
        fout << data[i] << endl;
    }
}

int main()
{
    fstream f_stream("file_1.txt", fstream::in| fstream::out);
    if (!f_stream.is_open())
        cout << "ERROR. file1.txt does not exist";
    vector<string> data;
    long pos = 5 * 6000;
    read_data(f_stream, pos, data);
    f_stream.clear();
    write_data(f_stream, pos, data);
    f_stream.close();
}
