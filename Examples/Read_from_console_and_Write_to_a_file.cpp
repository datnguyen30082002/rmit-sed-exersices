#include <iostream>
#include <fstream>

int main () {
    int your_age;
    char your_name[100];

    std::ofstream myfile; // declare an ofstream object
    myfile.open("MyFile.txt", std::ios::out); //open file
    
    if (!myfile) {
    std::cerr << "Fail to open file \n";
    }

    /* Write to file */
    myfile << "Saving to file ..." << std::endl; //flush to write immediately
   
    /* Read from console and write to file */
    std::cout << "Enter your age: "; 
    std::cin >> your_age;
    myfile << your_age << std::endl;

    std::cout << "Enter your name: "; 
    std::cin.ignore(1,'\n'); //Ignore previous "\n" character
    std::cin.getline(your_name, sizeof(your_name));
    myfile << your_name << "\n";

    std::cout << "Saved your answers to file !"; 

    myfile.close(); // close file
    
    return 0;
}
