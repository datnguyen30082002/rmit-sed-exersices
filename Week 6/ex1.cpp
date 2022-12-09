#include <iostream>
#include <string>
using namespace std;

// Create a Tutor object, and test access to all inherited attributes (by assigning random values for them).
class Person
{
public:
    string name = "Nguyen Thien Dat";
    int age = 20;

    Person()
    {
        cout << "Person constructor" << endl;
    }

    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    void personInfo()
    {
        cout << "Name = " << name << ", age = " << age << endl;
    }

    ~Person()
    {
        cout << "Person destructor" << endl;
    }
};

class Student
{
public:
    int studentID = 3877791;

    Student()
    {
        cout << "Student constructor" << endl;
    }

    Student(int studentID)
    {
        this->studentID = studentID;
    }

    void studentInfo()
    {
        cout << "Student ID = " << studentID << endl;
    }

    ~Student()
    {
        cout << "Student destructor" << endl;
    }
};

class Staff
{
public:
    int staffID = 123456;

    Staff()
    {
        cout << "Staff constructor" << endl;
    }

    Staff(int staffID)
    {
        this->staffID = staffID;
    }

    void staffInfo()
    {
        cout << "Staff ID = " << staffID << endl;
    }

    ~Staff()
    {
        cout << "Staff destructor" << endl;
    }
};

class Tutor : public Person, public Staff, public Student
{
public:
    void consultation()
    {
        
    }
    void showInfo()
    {
        cout << "This tutor info" << endl;
    }
};

int main()
{
    Tutor myTutor;
    myTutor.staffInfo();
    myTutor.showInfo();
    // myTutor.personInfo();
    // myTutor.staffInfo();
    // myTutor.studentInfo();
}
