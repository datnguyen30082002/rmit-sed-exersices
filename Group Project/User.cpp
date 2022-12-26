#include "User.h"
#include "Utils.h"

User::User() {}

User::User(string username, string password, string fullname, string phone_number, int credit_point)
{
    this->username = username;
    this->password = password;
    this->fullname = fullname;
    this->phone_number = phone_number;
    this->credit_point = credit_point;
}

// User::User(string username, string password, string fullname, string phone_number, House house)
// {
//     this->username = username;
//     this->password = password;
//     this->fullname = fullname;
//     this->phone_number = phone_number;
//     this->house = house;
// }

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

int User::getRole()
{
    return role;
}

void User::setRole(int role)
{
    this->role = role;
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
    cout.width(USER_ROLE_WIDTH);
    if (role == 2)
    {
        cout << left << "Member";
    }
    else
        cout << left << "Admin";
}

void User::showInfoIncludeHouse()
{
    cout << endl;
    cout.width(USER_USERNAME_WIDTH);
    cout << left << username;
    cout.width(USER_FULLNAME_WIDTH);
    cout << left << fullname;
    cout.width(USER_PHONE_NUMBER_WIDTH);
    cout << left << phone_number;
    cout.width(USER_CREDIT_POINT_WIDTH);
    cout << left << credit_point;
    cout.width(USER_ROLE_WIDTH);
    if (role == 2)
    {
        cout << left << "Member";
    }
    else
        cout << left << "Admin";
    if (house.getId() == 0)
        cout << "There is no house for this user";
    else
        house.showInfo();
}

// Format user output
void showUserHeader()
{
    cout << "---------------------------- Users' info ---------------------------" << endl;
    cout.width(USER_USERNAME_WIDTH);
    cout << left << "Username";
    cout.width(USER_FULLNAME_WIDTH);
    cout << left << "Full name";
    cout.width(USER_PHONE_NUMBER_WIDTH);
    cout << left << "Phone number";
    cout.width(USER_CREDIT_POINT_WIDTH);
    cout << left << "Credit point";
    cout.width(USER_ROLE_WIDTH);
    cout << left << "Role";
    // cout << endl;
}

void showUserHeaderIncludeHouse()
{
    cout << "---------------------------- Users' info ---------------------------" << endl;
    cout.width(USER_USERNAME_WIDTH);
    cout << left << "Username";
    cout.width(USER_FULLNAME_WIDTH);
    cout << left << "Full name";
    cout.width(USER_PHONE_NUMBER_WIDTH);
    cout << left << "Phone number";
    cout.width(USER_CREDIT_POINT_WIDTH);
    cout << left << "Credit point";
    cout.width(USER_ROLE_WIDTH);
    cout << left << "Role";
    cout.width(HOUSE_ID);
    cout << left << "ID";
    cout.width(HOUSE_LOCATION);
    cout << left << "Location";
    cout.width(HOUSE_DESCRIPTION);
    cout << left << "Description";
    // cout << endl;
}

// Show info function
void showUsersInfo(vector<User *> users, bool includeHouse)
{
    if (!includeHouse)
    {
        showUserHeader();
        for (int i = 0; i < users.size(); i++)
        {
            users[i]->showInfo();
        }
    }
    else
    {
        showUserHeaderIncludeHouse();
        for (int i = 0; i < users.size(); i++)
        {
            users[i]->showInfoIncludeHouse();
        }
    }
}

bool validateUsernameOfUser(vector<User *> users, string username)
{
    bool check = true;

    // Check username (username must have at least 5 characters)
    if (username.length() < 5)
    {
        cout << "username must have at least 5 characters" << endl;
        check = false;
    }

    // Username must not contain white space
    for (int i = 0; i < username.length(); i++)
    {
        if (isspace(username[i]))
        {
            cout << "The username must not have space" << endl;
            check = false;
            break;
        }
    }

    // Check if username is already existed
    for (int i = 0; i < users.size(); i++)
    {
        if (caseInsensitiveStringCompare(users[i]->getUsername(), username))
        {
            cout << "username " << username << " has already exits!" << endl;
            check = false;
            break;
        }
    }
    return check;
}

// Check password function
bool validatePasswordOfUser(vector<User *> users, string password)
{
    bool check = true;

    // Check password (password must have at least 8 characters)
    if (password.length() < 8)
    {
        cout << "The password must have at least 8 characters" << endl;
        check = false;
    }

    return check;
}

// Check phone number function
bool validatePhoneNumberOfUser(vector<User *> users, string phoneNumber)
{
    bool check = true;

    // Check phone number (phone number must have 10 numbers)
    if (!(phoneNumber.length() == 10))
    {
        cout << "The phone number must have 10 numbers" << endl;
        check = false;
    }

    // The app only accepts phone number start with 09xxxxxxxx
    if (!(phoneNumber.at(0) == '0' && phoneNumber.at(1) == '9'))
    {
        cout << "Phone number must start with 09" << endl;
        check = false;
    }

    // Check if the phone number has existed or not
    for (int i = 0; i < users.size(); i++)
    {
        if ((users[i]->getPhone_number() == phoneNumber))
        {
            cout << "Phone number " << phoneNumber << " has already existed!" << endl;
            check = false;
        }
    }

    return check;
}
