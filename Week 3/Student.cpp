#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100;

class Student
{
public:
    string name;
    int score;

    Student(){} // Declare a constructor

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

    void info()
    {
        cout << "Name is: " << name << endl;
        cout << "Score is: " << score << endl;
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
        cout << "Input Student's info " << i + 1 << endl;

        string name;
        int score;

        cout << "Input Student's name: ";
        cin.ignore(1, '\n');
        getline(cin, name);
        cout << "Input Student's score: ";
        cin >> score;

        students[i].setName(name);
        students[i].setScore(score);
    }
}

void OutputStudent(Student students[MAX_SIZE], int n)
{
    int max = students[0].score;

    for (int i = 0; i < n; i++)
    {
        cout << "Student's info " << i + 1 << endl;
        students[i].info();
    }
}

void findHighestScore(Student students[MAX_SIZE], int n)
{
    int max = students[0].score;

    for (int i = 0; i < n; i++)
    {
        if (students[i].score > max)
        {
            max = students[i].score;
        }
    }

    cout << "Student with the highest score is: " << endl;

    for (int i = 0; i < n; i++)
    {
        if (students[i].score == max)
        {
            students[i].info();
        }
    }
}

int main()
{
    Student students[MAX_SIZE];
    int n;

    EnterSize(n);
    InputStudent(students, n);
    OutputStudent(students, n);
    findHighestScore(students, n);

    return 0;
}