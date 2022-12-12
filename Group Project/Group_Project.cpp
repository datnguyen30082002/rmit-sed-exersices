#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Define global constant
int USER_USERNAME_WIDTH = 15;
int USER_FULLNAME_WIDTH = 20;
int USER_PHONE_NUMBER_WIDTH = 20;
int USER_CREDIT_POINT_WIDTH = 15;
int HOUSE_LOCATION = 15;
int HOUSE_DESCRIPTION = 20;

// Define default locations
vector<string> defaultLocations = {"Ha Noi", "Hue", "HCM"};

class House
{
private:
    string location;
    string description;

public:
    House() {}

    House(string location, string description)
    {
        this->location = location;
        this->description = description;
    }

    void setLocation(string location)
    {
        this->location = location;
    }

    string getLocation()
    {
        return location;
    }

    void setDescription(string description)
    {
        this->description = description;
    }

    string getDescription()
    {
        return description;
    }

    void showInfo()
    {
        cout.width(HOUSE_LOCATION);
        cout << left << location;
        cout.width(HOUSE_DESCRIPTION);
        cout << left << description;
        cout << endl;
    }
};

class User
{
private:
    string username;
    string password;
    string fullname;
    string phone_number;
    int credit_point;
    House house;

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

    User(string username, string password, string fullname, string phone_number, House house)
    {
        this->username = username;
        this->password = password;
        this->fullname = fullname;
        this->phone_number = phone_number;
        this->house = house;
    }

    // Get/Set method
    string getUsername()
    {
        return username;
    }

    void setUsername(string username)
    {
        this->username = username;
    }

    string getPassword()
    {
        return password;
    }

    void setPassword(string password)
    {
        this->password = password;
    }

    string getFullname()
    {
        return fullname;
    }

    void setFullname(string fullname)
    {
        this->fullname = fullname;
    }

    string getPhone_number()
    {
        return phone_number;
    }

    void setPhone_number(string phone_number)
    {
        this->phone_number = phone_number;
    }

    int getCredit_point()
    {
        return credit_point;
    }

    void setCredit_point(int credit_point)
    {
        this->credit_point = credit_point;
    }

    void setHouse(House house)
    {
        this->house = house;
    }

    bool registerMember(User user)
    {
        return true;
    }

    void showInfo()
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
};

// Format user output function
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

// Compare 2 strings function
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

// Show house info function
void showHouseInfo(vector<House *> houses, bool includeUser)
{
    showHouseInfoHeader();
    for (int i = 0; i < houses.size(); i++)
    {
        houses[i]->showInfo();
    }
}

// Check username function
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

int main()
{
    vector<User *> users = {
        new (std::nothrow) User("user1", "User 1", "0823248508", 500),
        new (std::nothrow) User("user2", "User 2", "0855764200", 500),
        new (std::nothrow) User("user3", "User 3", "0955764201", 500)};

    showUsersInfo(users, true);

    vector<House *> houses = {
        new (std::nothrow) House("HCM", "Nice"),
        new (std::nothrow) House("Ha Noi", "Good"),
        new (std::nothrow) House("Hue", "Beautiful")};
    
    showHouseInfo(houses, false);

    int role, featureChoice, subFeature;
    cout << "\nEEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "VACATION HOUSE EXCHANGE APPLICATION" << endl
         << endl;
    cout << "Instructors: Mr. Linh Tran & Phong Ngo" << endl;
    cout << "Group: Group 6" << endl;
    cout << "s3877791, Nguyen Thien Dat" << endl;
    cout << "sXXXXXXX, Student Name" << endl;
    cout << "sXXXXXXX, Student Name" << endl;
    cout << "sXXXXXXX, Student Name" << endl
         << endl;
    cout << "Use the app as 1. Guest   2. Member   3. Admin" << endl;
    cout << "Enter your choice: ";
    cin >> role;

    // declare variables for register features:
    string username, password, fullname, phoneNumber, houseLocation, houseDescription;
    House house;
    User user;

    switch (role)
    {
    case 1:
        cout << "You use the app as Guest." << endl;
        int guestChoice;
        cout << "1. Register" << endl;
        cout << "2. Seach and View house detail" << endl;
        cout << "3. Back to main features" << endl;
        cout << "Enter your choice: ";
        cin >> guestChoice;

        switch (guestChoice)
        {
        case 1:
            // 1. A non-member can register to become a member (information is recorded).
            do
            {
                cout << "Enter username: ";
                cin.ignore();
                getline(cin, username);
            } while (!validateUsernameOfUser(users, username));

            cout << "Enter fullname: ";
            getline(cin, fullname);

            do
            {
                cout << "Enter password: ";
                getline(cin, password);
            } while (!validatePasswordOfUser(users, password));

            do
            {
                cout << "Enter phone number: ";
                getline(cin, phoneNumber);
            } while (!validatePhoneNumberOfUser(users, phoneNumber));

            user.setUsername(username);
            user.setPassword(password);
            user.setFullname(fullname);
            user.setPhone_number(phoneNumber);

            int houseChoice;
            cout << "1. Register your house information" << endl;
            cout << "2. Skip" << endl;
            cout << "Enter your choice: ";
            cin >> houseChoice;

            switch (houseChoice)
            {
            case 1:
                do
                {
                    cout << "Enter your house location (location must be: 'Ha Noi', 'Hue', 'HCM'): ";
                    cin.ignore();
                    getline(cin, houseLocation);
                    house.setLocation(houseLocation);
                } while (!validateHouseInput(house));

                cout << "Enter house description: ";
                getline(cin, houseDescription);
                house.setDescription(houseDescription);

                user.setHouse(house);
                break;
            case 2:
                break;
            }

            // Validate input from user
            cout << "> Register successfully!" << endl;
            user.setCredit_point(500);
            users.push_back(&user);
            showUsersInfo(users, true);

            break;
        case 2:

            break;
        case 3:
            break;
        }

        // cout << "Register as member/View house details without seeing reviews or availibility" << endl;
        break;
    case 2:
        /*cout << "Enter your username: ";
        getline(cin, username);
        cout << "Enter your password: ";
        getline(cin, password);

        if (user.getUsername())*/

        break;
    }

    return 0;
}