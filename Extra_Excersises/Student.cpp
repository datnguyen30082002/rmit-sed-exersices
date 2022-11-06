#include <iostream>
using namespace std;

class Student
{
public:
    int age;
    int mark;

    Student(){}

    Student(int age, int mark)
    {
        age = age;
        mark = mark;
    }

    void info()
    {
        cout << "Student's age:" << age << endl;
        cout << "Studnet's mark: " << mark << endl;
    }

    void ranking(int mark)
    {
        if (mark < 50)
            cout << "Fail course"; 
        else if (mark >= 50 && mark <= 59)
            cout << "Pass the course";
        else if (mark >= 60 && mark <= 69)
            cout << "Creadit course";
        else if (mark >= 70 && mark <= 79)
            cout << "Distinction course";
        else if (mark >= 80)
            cout << "High distinction course";

        cout << endl;
    }
};

int main()
{
    Student my_student;

    int age, mark;
    cout << "enter student's age: " << endl;
    cin >> age;
    cout << "enter student's mark: " << endl;
    cin >> mark;

    my_student.age = age;
    my_student.mark = mark;

    my_student.info();

    my_student.ranking(my_student.mark);
}