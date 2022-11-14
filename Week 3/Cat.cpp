#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

const int SIZE = 100;

class Cat
{
public:
    string name;
    int age;

    Cat() {}

    Cat(string cat_name, int cat_age)
    {
        name = cat_name;
        age = cat_age;
    }

    void setName(string cat_name)
    {
        name = cat_name;
    }

    void setAge(int cat_age)
    {
        age = cat_age;
    }

    void info()
    {
        cout << "Cat's name is: " << name << endl;
        cout << "Cat's age is: " << age << endl;
    }
};

class Person
{
public:
    string name;
    Cat mycat;

    Person() {} // Default constructor

    Person(string person_name, Cat mycat_val)
    {
        name = person_name;
        mycat = mycat_val;
    }

    void setname(string person_name)
    {
        name = person_name;
    }

    void setCat(Cat mycat_val)
    {
        mycat = mycat_val;
    }

    void info()
    {
        cout << "Person's name is: " << name << endl;
        mycat.info();
    }
};

void EnterSize(int &n)
{
    do
    {
        cout << "Enter the array's size: ";
        cin >> n;
    } while (!n > 0);
}

void InputCat(Cat &mycat)
{
    // Random cat's attributes
    // string name = "cat" + to_string(1);
    // int age = rand() % 10 + 1;

    string name;
    int age;

    cout << "Enter cat's name: ";
    getline(cin, name);

    cout << "Enter cat's age: ";
    cin >> age;

    mycat.setName(name);
    mycat.setAge(age);
}

void InputPerson(Person persons[SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        // string name = "persons_" + to_string(i + 1); // Random person's name

        string name;
        cout << "Enter person " << i + 1 << " name: ";
        cin.ignore(1, '\n');
        getline(cin, name);

        persons[i].setname(name);

        Cat mycat;
        InputCat(mycat);

        persons[i].setCat(mycat);
    }
}

void OutputPerson(Person persons[SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "--------- Person " << i + 1 << "'s info ----------" << endl;
        persons[i].info();
    }
}

int findHighestAge(Person persons[SIZE], int n)
{
    int max = persons[0].mycat.age;

    for (int i = 0; i < n; i++)
    {
        if (max < persons[i].mycat.age)
            max = persons[i].mycat.age;
    }

    return max;
}

void OutputPersonWithOldestCat(Person persons[SIZE], int n, int age)
{
    cout << endl
         << "-----------Person with oldest cat----------" << endl;
    for (int i = 0; i < n; i++)
    {
        if (persons[i].mycat.age == age)
        {
            persons[i].info();
            cout << endl;
        }
    }
}

int main()
{
    Person persons[SIZE];
    int n;

    EnterSize(n);
    InputPerson(persons, n);
    OutputPerson(persons, n);
    int oldest_age = findHighestAge(persons, n);
    OutputPersonWithOldestCat(persons, n, oldest_age);
}
