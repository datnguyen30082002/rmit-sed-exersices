#include "Header.h"
#include "House.h"
#include "User.h"

int main()
{
    User user1("user1", "User 1", "0823248508", 500);
    User user2("user2", "User 2", "0855764200", 500);
    User user3("user3", "User 3", "0955764201", 500);

    House house1("HCM", "house 1", true);
    House house2("Ha Noi", "house 2", true);
    House house3("Hue", "house 3", true);

    user1.setHouse(house1);
    house1.setUser(user1);
    
    vector<User *> users = { user1, user2, user3 };

    showUsersInfo(users, true);


    showHouseInfo(houses);

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