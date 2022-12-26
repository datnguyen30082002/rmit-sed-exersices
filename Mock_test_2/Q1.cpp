#include <iostream>
#include <string>
#include <vector>
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
    Manager(string name = "", double salary = 0, double allowance = 0) : Employee(name, salary), allowance(allowance) {}

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

    // Vector method
    // vector<Manager *> managers = {
    //     new (std::nothrow) Manager("manager 1", 500, 50),
    //     new (std::nothrow) Manager("manager 2", 550, 55),
    //     new (std::nothrow) Manager("manager 3", 600, 60),
    //     new (std::nothrow) Manager("manager 4", 700, 70),
    //     new (std::nothrow) Manager("manager 5", 800, 80)};

    // double totalIncome = 0;

    // for (auto s : managers)
    // {
    //     totalIncome += (s->getSalary() + s->getAllowance());
    // }

    // double avgTotalIncome = totalIncome / managers.size();
    // cout << "Average total income of 5 managers: " << avgTotalIncome << endl;

    // Create an array of 5 managers using dynamic memory allcation
    Manager *managers = new (std::nothrow) Manager[5]{
        Manager("manager1", 1000, 100),
        Manager("manager2", 3000, 200),
        Manager("manager3", 2000, 300),
        Manager("manager4", 4000, 200),
        Manager("manager5", 2000, 100)};

    if (managers == nullptr)
    {
        cout << "Fail to request memory allocation \n";
        return -1;
    }

    // Look through all elements to caculate sum and everage
    double incomeSum = 0;
    for (int i = 0; i < 5; i++)
    {
        cout << "\n i = " << i << ", " << managers[i].getSalary() + managers[i].getAllowance();
        incomeSum += (managers[i].getSalary() + managers[i].getAllowance());
    }
    
    cout << "\n incomeSum = " << incomeSum;
    cout << "Average of total income = " << incomeSum / 5;
}
