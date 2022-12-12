#include "Mylibrary.h"

/* Source file:
 * Definitions of functions/ methods for the module
*/

// Format user output
void showUserHeader()
{
    cout << "---------------------------- Users' info ---------------------------" << endl;
    cout.width(USER_USERNAME_WIDTH);
    cout << left << "Username";
    cout.width(USER_FULLNAME_WIDTH);
    cout << left << "Fullname";
    cout.width(USER_PHONE_NUMBER_WIDTH);
    cout << left << "Phone number";
    cout.width(USER_CREDIT_POINT_WIDTH);
    cout << left << "Credit point";
    cout << endl;
}

void showUserHeaderIncludeHouse()
{
    cout << "---------------------------- Users' info ---------------------------" << endl;
    cout.width(USER_USERNAME_WIDTH);
    cout << left << "Username";
    cout.width(USER_FULLNAME_WIDTH);
    cout << left << "Fullname";
    cout.width(USER_PHONE_NUMBER_WIDTH);
    cout << left << "Phone number";
    cout.width(USER_CREDIT_POINT_WIDTH);
    cout << left << "Credit point";
    cout.width(HOUSE_LOCATION);
    cout << left << "Location";
    cout.width(HOUSE_DESCRIPTION);
    cout << left << "Description";
    cout << endl;
}

void showHouseInfoHeader()
{
    cout << "-------------------- House's info --------------------" << endl;
    cout.width(HOUSE_LOCATION);
    cout << left << "Location";
    cout.width(HOUSE_DESCRIPTION);
    cout << left << "Description";
    cout << endl;
}

bool caseInsensitiveStringCompare(const string &str1, const string &str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }

    for (string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2)
    {
        if (tolower(static_cast<unsigned char>(*c1)) != tolower(static_cast<unsigned char>(*c2)))
        {
            return false;
        }
    }
    return true;
}

// Show info function
void showUsersInfo(vector<User *> users, bool includeHouse)
{
    if (!includeHouse)
    {
        showUserHeader();
    }
    else
    {
        showUserHeaderIncludeHouse();
    }

    for (int i = 0; i < users.size(); i++)
    {
        users[i]->showInfo();
    }
}

void showHouseInfo(vector<House *> houses)
{
    showHouseInfoHeader();
    for (int i = 0; i < houses.size(); i++)
    {
        houses[i]->showInfo();
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

// Check house location function
bool validateHouseInput(House house)
{
    for (int i = 0; i < defaultLocations.size(); i++)
    {
        if (caseInsensitiveStringCompare(defaultLocations[i], house.getLocation()))
        {
            return true;
        }
    }
    return false;
}