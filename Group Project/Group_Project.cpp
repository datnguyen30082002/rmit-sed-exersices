#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class User
{
private:
    string username;
    string fullname;
    string phone_number;
    int credit_point = 0;

public:
    // Default constructor
    User() {}

    // Parameterized constructor
    User(string username, string fullname, string phone_number, int credit_point)
    {
        this->username = username;
        this->fullname = fullname;
        this->phone_number = phone_number;
        this->credit_point = credit_point;
    }

    // Get/Set method
    string getUsername()
    {
        return username;
    }

    void setUsername(string username)
    {
        username = username;
    }

    string getFullname()
    {
        return fullname;
    }

    void setFullname(string fullname)
    {
        fullname = fullname;
    }

    string getPhone_number()
    {
        return phone_number;
    }

    void setPhone_number(string phone_number)
    {
        phone_number = phone_number;
    }

    int getCredit_point()
    {
        return credit_point;
    }

    void setCredit_point(int credit_point)
    {
        credit_point = credit_point;
    }

    bool validateInput(User user)
    {

        return true;
    }

    bool registerMember(User user)
    {
        string username, fullname, phone_number;

        cout << "Enter username: ";
        getline(cin, username);
        cout << "Enter fullname: ";
        getline(cin, fullname);
        cout << "Enter phone number: ";
        getline(cin, phone_number);

        return true;
    }

    void showInfo()
    {
        cout.width(5);
        cout << left << username;
        cout.width(20);
        cout << left << fullname;
        cout.width(5);
        cout << left << phone_number;
        cout.width(5);
        cout << left << credit_point;
        cout << endl;
    }
};

int main()
{
    vector<User *> users = {
        new (std::nothrow) User("User1", "User 1", "0823248508", 500),
        new (std::nothrow) User("User2", "User 2", "0855764200", 500),
        new (std::nothrow) User("User3", "User 3", "0855764201", 500)};

    cout << "-----Users' info-------" << endl;    
    users[0]->showInfo();
    users[1]->showInfo();
    users[2]->showInfo();

    return 0;
}