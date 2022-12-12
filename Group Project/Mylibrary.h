#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

/* /* Header file:
* Only contain declarations (prototypes)
* of classes/ functions/ user defined data types
*/

void showUserHeader();

void showUserHeaderIncludeHouse();

void showHouseInfoHeader();

bool caseInsensitiveStringCompare(const string &str1, const string &str2);

// Show info function
void showUsersInfo(vector<User *> users, bool includeHouse);

void showHouseInfo(vector<House *> houses);

bool validateUsernameOfUser(vector<User *> users, string username);

// Check password function
bool validatePasswordOfUser(vector<User *> users, string password);

// Check phone number function
bool validatePhoneNumberOfUser(vector<User *> users, string phoneNumber);

// Check house location function
bool validateHouseInput(House house);

