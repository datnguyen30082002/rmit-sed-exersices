#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int choice = 0;
    char password[100];
    char filename[] = "pwd.dat";
    std::fstream myfile; // declare an ofstream object

    do
    {
        /* Create menu */
        cout << endl
             << "------------------------------------" << endl;
        cout << "Password management program: " << endl;
        cout << "1. Save your password" << endl                      
             << "2. Read your password" << endl                      
             << "3. Modify your password with a blank space" << endl 
             << "4. Exit the program" << endl;
        cout << "Your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            /* Create and open file*/
            myfile.open(filename, std::ios::out); // open file

            if (!myfile)
            {
                std::cerr << "Fail to open file \n";
            }

            /* Read from console and write to file */
            std::cout << "Enter your password: ";
            std::cin.ignore(1, '\n'); // Ignore previous "\n" character
            std::cin.getline(password, sizeof(password));
            myfile << password << endl; // Write to file

            std::cout << "Saved your answers to file !";

            myfile.close(); // close file
            break;
        case 2:
            /* Open for reading and read */
            myfile.open(filename, std::ios::in);

            while (!myfile.eof())
            { // runs until end of file
                myfile.getline(password, sizeof(password));
                cout << "Password: " << password << endl;
            }

            myfile.close(); // Close the file.
            break;

        /* General method for all cases */
        case 3:
            /* Create and open file*/
            myfile.open(filename, std::ios::out); // open file

            if (!myfile)
            {
                std::cerr << "Fail to open file \n";
            }

            /* Read from console and write to file */
            std::cout << "Enter your password: ";
            std::cin.ignore(1, '\n'); // Ignore previous "\n" character
            std::cin.getline(password, sizeof(password));
            myfile << password << endl; // Write to file

            std::cout << "Saved your answers to file !" << endl;

            myfile.close(); // close file

            /* Open for reading and read */
            myfile.open(filename, std::ios::in);

            while (!myfile.eof()) // Run until end of file
            {
                myfile.getline(password, sizeof(password)); // To get the all line and ignore white space 
                cout << "password: " << password << endl;
            }
            myfile.close(); // Close the file

            break;

        default:
            break;
        }
    } while (choice != 4);

    return 0;
}