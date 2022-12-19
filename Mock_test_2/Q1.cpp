#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    double salary;

public:
    Employee(string name = "", double salary = 0) : name(name), salary(salary) {}

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return this->name;
    }

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    double getSalary()
    {
        return this->salary;
    }

    virtual void showInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Manager : public Employee
{
private:
    double allowance;

public:
    Manager(string name = "", double salary = 0, double allowance = 0) : Employee(name), Employee(salary), allowance(allowance) {}

    void setAllowance(double allowance)
    {
        this->allowance = allowance;
    }

    double getAllowance()
    {
        return this->allowance;
    }

    void showInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Allowance: " << allowance << endl;
    }
};

int main()
{
    Employee employee1("employee 1", 100), employee2("employee 2", 200);
    Manager manager1("manager 1", 500, 50);

    employee1.showInfo();
    employee2.showInfo();
    manager1.showInfo();
}