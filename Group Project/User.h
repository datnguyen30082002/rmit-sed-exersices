#pragma once
#include "Header.h"
#include "House.h"

class User
{
private:
	string username;
	string password;
	string fullname;
	string phoneNumber;
	int creditPoint = 0;
	float ratingScore = 0;
	House house;
	int role = 0;
	int userHouseId = 0;

public:
	User();

	// Parameterized constructor
	User(string username, string password, string fullname, string phoneNumber, int creditPoint);

	User(string username, string password, string fullname, string phoneNumber, int creditPoint, float ratingScore);

	//User(string username, string password, string fullname, string phoneNumber, House house);

	// Get/Set method
	string getUsername();

	void setUsername(string username);

	string getPassword();

	void setPassword(string password);

	string getFullname();

	void setFullname(string fullname);

	string getPhoneNumber();

	void setPhoneNumber(string phoneNumber);

	int getCreditPoint();

	void setCreditPoint(int creditPoint);

	float getRatingScore();

	void setRatingScore(float ratingScore);

	House getUserHouse();

	void setHouse(House house);

	int getRole();

	void setRole(int role);

	int getUserHouseId();

	void setUserHouseId(int UserHouseId);

	bool registerMember(User user);

	void showInfo();

	void showInfoIncludeHouse();

	friend class Review;
};

void showUserHeader();

void showUserHeaderIncludeHouse();

bool caseInsensitiveStringCompare(const string &str1, const string &str2);

// Show info function
void showUsersInfo(vector<User *> users, bool includeHouse);

bool validateUsernameOfUser(vector<User *> users, string username);

// Check password function
bool validatePasswordOfUser(vector<User *> users, string password);

// Check phone number function
bool validatePhoneNumberOfUser(vector<User *> users, string phoneNumber);

User findByUsername(vector<User *> users, string username);
