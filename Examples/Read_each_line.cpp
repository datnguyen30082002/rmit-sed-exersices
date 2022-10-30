#include <iostream>
#include <fstream>

int main() {
    char buff[256] = {};

    ifstream infile("sample.txt", ios::in | ios::binary);
    if (!infile) {
    cout << "Cannot open file sample.txt" << endl;
    return 0;
    }

    while(!infile.eof()) { // runs until end of file
    infile.getline(buff, sizeof(buff));
    cout << buff << endl;
    } 

    infile.close();

    return 0;
}