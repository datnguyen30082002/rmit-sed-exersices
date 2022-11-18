#include <iostream>
#include <string>
using namespace std;
const int SIZE = 100;

class BankAcc
{
public:
    string name;
    float amount;

    BankAcc() {}

    void setName(string name)
    {
        this->name = name;
    }

    void setAmount(float amount)
    {
        this->amount = amount;
    }

    void withdraw(int num)
    {
        if (this->amount < num)
        {
            cout << "Balance is not enough for withdrawal" << endl;
            return;
        }

        this->amount -= num;
        cout << "The balance is " << this->amount;
    }

    void info()
    {
        cout << "Name: " << name << endl;
        cout << "Amount: " << amount << endl;
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

void InputData(BankAcc bankacc[SIZE], int n)
{
    for (int i = 0; i < n; i++)
    {
        string name;
        cout << "Enter bank account " << i + 1 << " name: ";
        cin.ignore(1, '\n');
        getline(cin, name);

        float amount;
        cout << "Enter bank account " << i + 1 << " amount: ";
        cin >> amount;

        bankacc[i].setName(name);
        bankacc[i].setAmount(amount);
    }
}

void OutputData(BankAcc bankacc[SIZE], int n)
{
    cout << endl
         << "---------Bank account's info-----------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Bank account " << i + 1 << ": " << endl;
        bankacc[i].info();
    }
}

int main()
{
    BankAcc bankacc[SIZE];
    int n;

    EnterSize(n);
    InputData(bankacc, n);
    OutputData(bankacc, n);

    cout << endl
         << "---------Withdrawal-----------";
    for (int i = 0; i < n; i++)
    {
        cout << endl
             << "Withdraw for bank account" << i + 1 << ": " << endl;

        int money;
        cout << "Enter the amount you want to withdraw: ";
        cin >> money;

        bankacc[i].withdraw(money);
    }
}