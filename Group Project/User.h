#pragma once
#include "Header.h"
#include "House.h"

class User
{
private:
	string username;
	string password;
	string fullname;
	string phone_number;
	int credit_point;
	House house;
	int role;

public:

	User();

	// Parameterized constructor
	User(string username,  string password, string fullname, string phone_number, int credit_point);

	//User(string username, string password, string fullname, string phone_number, House house);

	// Get/Set method
	string getUsername();

	void setUsername(string username);

	string getPassword();

	void setPassword(string password);

	string getFullname();

	void setFullname(string fullname);

	string getPhone_number();

	void setPhone_number(string phone_number);

	int getCredit_point();

	void setCredit_point(int credit_point);

	void setHouse(House house);

	int getRole();

	void setRole(int role);

	bool registerMember(User user);

	void showInfo();

	void showInfoIncludeHouse();
};

void showUserHeader();

void showUserHeaderIncludeHouse();


bool caseInsensitiveStringCompare(const string& str1, const string& str2);

// Show info function
void showUsersInfo(vector<User*> users, bool includeHouse);

bool validateUsernameOfUser(vector<User*> users, string username);

// Check password function
bool validatePasswordOfUser(vector<User*> users, string password);

// Check phone number function
bool validatePhoneNumberOfUser(vector<User*> users, string phoneNumber);


