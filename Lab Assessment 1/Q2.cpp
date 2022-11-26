/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Lab Assessment: 1
  Author: Nguyen Thien Dat
  ID: s3877791
  Compiler used: g++ 8.1.0
  Created  date: 26/11/2022
  Acknowledgement: None
*/

#include <iostream>
#include <string>
using namespace std;

class EWallet
{
public:
  string name;
  double balance;

  EWallet() {}

  EWallet(string name, double balance)
  {
    this->name = name;
    this->balance = balance;
  }

  void setName(string name)
  {
    this->name = name;
  }

  void setBalance(double balance)
  {
    this->balance = balance;
  }

  string getName()
  {
    return name;
  }

  double getBalance()
  {
    return balance;
  }

  bool pay(double amount, string coupon)
  {
    if (this->balance < amount)
      return false;

    if (coupon == "BLACKFRIDAY")
    {
      this->balance = this->balance - (this->balance * 0.3);
    }
    else
      this->balance -= amount;

    return this->balance;
  }

  void info()
  {
    cout << "Name: " << name << endl;
    cout << "Balance: " << balance << endl;
  }
};

class User
{
public:
  string name;
  string pwd;
  EWallet acc;

  User() {} // Default constructor

  User(string name, string pwd, EWallet acc)
  {
    this->name = name;
    this->pwd = pwd;
    this->acc = acc;
  }

  void setName(string name)
  {
    this->name = name;
  }

  void setPwd(string pwd)
  {
    this->pwd = pwd;
  }

  void setAcc(EWallet acc)
  {
    this->acc = acc;
  }

  bool verifyPass()
  {
    string password;

    cout << "Enter password: ";
    getline(cin, password);

    if (password != this->pwd)
    {
      return false;
    }

    return true;
  }

  bool doPayment()
  {
    if (verifyPass() == true)
    {
      int amount;
      cout << "Enter amount: ";
      cin >> amount;

      string coupon_code;
      cout << "Enter coupon code: ";
      getline(cin, coupon_code);

      info();
      this->acc.pay();
      info();
    }
  }
  
  void info()
  {
    cout << "User's name is: " << name << endl;
    cout << "User's password is: " << pwd << endl;
    acc.info();
  }
};

int main()
{
  EWallet A("a", 10000);
  A.info();
  A.pay(1000, "");
  A.info();

  User B("Nguyen Thien Dat", "123456", A);

  cout << "----Result of verify password----" << endl;
  if (B.verifyPass() == true)
    cout << "Password is correct" << endl;
  else
    cout << "Password is incorrect" << endl;

  return 0;
}