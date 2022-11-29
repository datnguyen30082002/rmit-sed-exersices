#include <iostream>
#include <string>
using namespace std;

union Student
{
    string fullName;
    string firstName;
};

int main()
{
    Student students[3];

    for (int i = 0; i < 3; i++)
    {
        string fullName;
        getline(cin, fullName);
        students[i].fullName = fullName;
    }

    for (Student student : students)
    {
        cout << student.fullName << endl;
    }
}