#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

class Student
{
private:
    string password;

public:
    string name;
    int score;

    Student() {} // Declare a constructor

    Student(string studentName, int studentScore)
    {
        name = studentName;
        score = studentScore;
    }

    void setName(string studentName)
    {
        name = studentName;
    }

    void setScore(int studentScore)
    {
        score = studentScore;
    }

    void change_pwd(string pwd)
    {
        password = pwd;
    }

    string getPassword()
    {
        return password;
    }

    void info()
    {
        cout << "Name is: " << name << endl;
        cout << "Score is: " << score << endl;
        cout << "Password is: " << password << endl;
    }
};

void EnterSize(int &n)
{
    do
    {
        cout << "Enter the array's size: ";
        cin >> n;
    } while (!(n > 0));
}

void InputStudent(Student students[MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        string name = "students_" + to_string(i + 1);
        int score = rand() % 100 + 1;
        string password = "123456";

        // Random students to have password
        int random = rand();
        if (random % 2 == 0)
            students[i].change_pwd("");
        else
            students[i].change_pwd(password);

        students[i].setName(name);
        students[i].setScore(score);
    }
}

void OutputStudent(Student students[MAX_SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "------- Student's info " << i + 1 << " ----------" << endl;
        students[i].info();
    }
}

void OutputStudentByPassword(Student students[MAX_SIZE], int n, bool isMissing)
{
    cout << endl
         << "-------Students who have password---------" << endl;

    for (int i = 0; i < n; i++)
    {
        if (isMissing)
        {
            if (students[i].getPassword().empty())
            {
                cout << endl
                     << "------- Student's info " << i + 1 << " ----------" << endl;
                students[i].info();
            }
        }
        else
        {
            if (!students[i].getPassword().empty())
            {
                cout << endl
                     << "------- Student's info " << i + 1 << " ----------" << endl;
                students[i].info();
            }
        }
    }
}

void InputPassword(Student students[MAX_SIZE], int n)
{
    std::ofstream myfile; // declare an ofstream object

    for (int i = 0; i < n; i++)
    {
        if (students[i].getPassword().empty())
        {
            string password;

            cin.ignore(); // Ignore '\n' character

            /* Read from console and write to file */
            cout << endl
                 << i + 1 << ". " << students[i].name;
            cout << endl
                 << "Enter password for " << students[i].name << ": ";
            getline(cin, password);

            cout << endl
                 << "New password is: " << password << endl;

            // Write to file & name the file
            string filename = students[i].name + ".dat";

            /* Create and open file*/
            myfile.open(filename, std::ios::out); // open file

            if (!myfile)
            {
                std::cerr << "Fail to open file \n";
            }

            myfile << password << endl; // Write to file

            std::cout << "Saved password to file !" << endl;

            myfile.close(); // close file

            students[i].change_pwd(password);
        }
    }
}

void CheckPassword(Student students[MAX_SIZE], int n)
{
    int choice;
    string password;
    std::ofstream myfile; // declare an ofstream object

    for (int i = 0; i < n; i++)
    {
        if (students[i].getPassword().empty())
        {
            continue;
        }

        bool flag = false;
        int count = 0;

        do
        {
            cout << endl
                 << students[i].name + " password management" << endl
                 << "1. Change your password" << endl
                 << "2. Exit" << endl;
            cout << "Enter your choice: ";

            cin >> choice;

            switch (choice)
            {
            case 1:
                count = 0;
                while (count < 3)
                {
                    cout << endl
                         << "Enter your current password: ";
                    cin >> password;

                    if (!(students[i].getPassword() == password))
                    {
                        count++;
                        cout << endl << "You have entered wrong password " << count << " times";
                        continue;
                    }

                    flag = true;
                    cin.ignore(1, '\n'); // Ignore '\n' character

                    /* Read from console and write to file */
                    cout << endl
                         << i + 1 << ". " << students[i].name;
                    cout << endl
                         << "Enter new password for " << students[i].name << ": ";
                    getline(cin, password);

                    cout << endl
                         << "New password is: " << password << endl;

                    // Write to file & name the file
                    string filename = students[i].name + ".dat";

                    /* Create and open file*/
                    myfile.open(filename, std::ios::out); // open file

                    if (!myfile)
                    {
                        std::cerr << "Fail to open file \n";
                    }

                    myfile << password << endl; // Write to file

                    std::cout << "Saved password to file !" << endl;

                    myfile.close(); // close file

                    students[i].change_pwd(password);

                    break;
                }
            }

            if (count >= 3)
            {
                cout << endl << "You have entered wrong password more than 3 times";
                flag = true;
            }

        } while (choice != 2 && flag == false);
    }
}

int main()
{
    srand(time(0));

    Student students[MAX_SIZE];
    int n;

    EnterSize(n);
    InputStudent(students, n);
    OutputStudent(students, n);
    // InputPassword(students, n);
    OutputStudentByPassword(students, n, false);
    CheckPassword(students, n);
    // cout << students[0].getPassword();

    // OutputStudent(students, n);

    // OutputStudentByPassword(students, n, false);

    return 0;
}