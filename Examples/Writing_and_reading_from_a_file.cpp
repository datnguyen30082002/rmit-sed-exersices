#include <iostream>
#include <fstream>
using std::cin;
using std::cout;


int main () {
    char str[100];

    //Create and open a file (use write mode only to create file).
    std::fstream myfile;
    myfile.open("myFile.dat", std::ios::out);

    if (!myfile) {
    std::cerr << "Fail to create/open file \n";
    return -1;
    }

    //Write to file
    int num = 10;
    myfile << num << " Hello World !";
    myfile.close(); // close the file.
    std::cout << "Wrote to the file ! \n" << std::endl;

    //Open for reading and read
    myfile.open("myFile.dat", std::ios::in);
    myfile >> num >> str;

    std::cout << "Read from file: " << std::endl;
    std::cout << num << " " << str << "\n"; 

    myfile.close(); // close the file.
    
    return 0;
}