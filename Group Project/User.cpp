#include "User.h"

User::User(string username, string fullname, string phone_number, int credit_point)
{
    this->username = username;
    this->fullname = fullname;
    this->phone_number = phone_number;
    this->credit_point = credit_point;
}

User::User(string username, string password, string fullname, string phone_number, House house)
{
    this->username = username;
    this->password = password;
    this->fullname = fullname;
    this->phone_number = phone_number;
    this->house = house;
}

// Get/Set method
string User::getUsername()
{
    return username;
}

void User::setUsername(string username)
{
    this->username = username;
}

string User::getPassword()
{
    return password;
}

void User::setPassword(string password)
{
    this->password = password;
}

string User::getFullname()
{
    return fullname;
}

void User::setFullname(string fullname)
{
    this->fullname = fullname;
}

string User::getPhone_number()
{
    return phone_number;
}

void User::setPhone_number(string phone_number)
{
    this->phone_number = phone_number;
}

int User::getCredit_point()
{
    return credit_point;
}

void User::setCredit_point(int credit_point)
{
    this->credit_point = credit_point;
}

void User::setHouse(House house)
{
    this->house = house;
}

bool User::registerMember(User user)
{
    return true;
}

void User::showInfo()
{
    cout.width(USER_USERNAME_WIDTH);
    cout << left << username;
    cout.width(USER_FULLNAME_WIDTH);
    cout << left << fullname;
    cout.width(USER_PHONE_NUMBER_WIDTH);
    cout << left << phone_number;
    cout.width(USER_CREDIT_POINT_WIDTH);
    cout << left << credit_point;
    house.showInfo();
    cout << endl;
}