#include "Header.h"
#include "House.h"
#include "User.h"
#include "Utils.h"
#include "RentDate.h"
#include "Review.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <limits>
#include <ctime>
#include <sstream>

using namespace std;

bool hasCreateDefaultData = false; // Global variable to check if the default data has been existed or not

/* Functions for main */
// Show house info function
void showHouseInfo(vector<House*> houses, vector<User*> users)
{
	showBasicHouseHeader();
	for (int i = 0; i < houses.size(); i++)
	{
		cout << endl;
		User user = findByUsername(users, houses[i]->getUsername());
		houses[i]->showBasicInfo();
		cout << ", owner: " << user.getUsername() << " - " << user.getPhoneNumber();
	}
}

// Find the largest house id function
int findMaxHouseId(vector<House*> houses)
{
	if (houses.size() == 0)
	{
		return 0;
	}

	int max = houses[0]->getId();

	for (auto maxId : houses)
	{
		if (maxId->getId() > max)
		{
			max = maxId->getId();
		}
	}

	return max;
}

// Find the largest review id function
int findMaxReviewId(vector<Review*> reviews)
{
	if (reviews.size() == 0)
	{
		return 0;
	}

	int max = reviews[0]->getReviewId();

	for (auto maxId : reviews)
	{
		if (maxId->getReviewId() > max)
		{
			max = maxId->getReviewId();
		}
	}

	return max;
}

// String append function
std::string join(std::vector<std::string> const& strings, std::string delim)
{
	std::stringstream ss;
	std::copy(strings.begin(), strings.end(), std::ostream_iterator<std::string>(ss, delim.c_str()));
	return ss.str();
}

// Split string upto delimiter function
vector<string> split(string str, char delimiter)
{
	// Using str in a string stream
	stringstream ss(str);
	vector<string> res;
	string token;
	while (getline(ss, token, delimiter))
	{
		res.push_back(token);
	}

	return res;
}

int main()
{
	// Reload data
	fstream myUserFile;
	fstream myHouseFile;
	fstream myReviewFile;

	string userFile = "user.dat";
	string houseFile = "house.dat";
	string reviewFile = "review.dat";

	vector<User*> users = { };
	vector<House*> houses = { };
	vector<Review*> reviews = { };


	if (hasCreateDefaultData) // If there is no default data then initialize and store to files
	{
		// Initialize default data
		User* admin1 = new (std::nothrow) User("admin1", "1", "ADMIN 1", "0912000111", 500);
		User* admin2 = new (std::nothrow) User("admin2", "1", "ADMIN 2", "0912333555", 500);
		User* user1 = new (std::nothrow) User("user1", "1", "User 1", "0823248508", 500, 0);
		User* user2 = new (std::nothrow) User("user2", "1", "User 2", "0855656565", 500, 3);
		User* user3 = new (std::nothrow) User("user3", "1", "User 3", "0955764201", 500, 5);
		User* user4 = new (std::nothrow) User("user4", "1", "User 4", "0955764202", 500, 7);
		User* user5 = new (std::nothrow) User("user5", "1", "User 5", "0955764202", 500, 7);
		User* user6 = new (std::nothrow) User("user6", "1", "User 6", "0955764202", 500, 7);
		User* user7 = new (std::nothrow) User("user7", "1", "User 7", "0955764202", 500, 7);

		House* house1 = new (std::nothrow) House(1, "HCM", "house of user 1", true, 100, 5, false);
		House* house2 = new (std::nothrow) House(2, "Ha Noi", "house of user 2", true, 120, 0, false);
		House* house3 = new (std::nothrow) House(3, "Hue", "house of user 3", true, 150, 7, true);
		House* house4 = new (std::nothrow) House(4, "Ha Noi", "house of user 4", false, 110, 0, false);
		House* house5 = new (std::nothrow) House(5, "Hue", "house of user 5", false, 190, 8, false);
		House* house6 = new (std::nothrow) House(6, "Ha Noi", "house of user 6", true, 150, 5, false);
		House* house7 = new (std::nothrow) House(7, "Hue", "house of user 7", true, 120, 0, false);

		house1->setRentDate(new RentDate(true));

		admin1->setRole(3);
		admin2->setRole(3);
		user1->setRole(2);
		user2->setRole(2);
		user3->setRole(2);
		user4->setRole(2);
		user5->setRole(2);
		user6->setRole(2);
		user7->setRole(2);

		user1->setHouse(*house1);
		user2->setHouse(*house2);
		user3->setHouse(*house3);
		user4->setHouse(*house4);
		user5->setHouse(*house5);
		user6->setHouse(*house6);
		user7->setHouse(*house7);

		house1->setUsername(user1->getUsername());
		house2->setUsername(user2->getUsername());
		house3->setUsername(user3->getUsername());
		house4->setUsername(user4->getUsername());
		house5->setUsername(user5->getUsername());
		house6->setUsername(user6->getUsername());
		house7->setUsername(user7->getUsername());

		Review* review1 = new (std::nothrow) Review(1, 1, "user2", 5, "nice", RentDate());
		house1->setHouseRatingScore(5);

		//For testing
		vector<string> requestOccupation = { "user1", "user2", "user3" };
		house2->setRequestOccupation(requestOccupation);

		users = { admin1, admin2, user1, user2, user3, user4, user5, user6, user7 };
		houses = { house1, house2, house3, house4, house5, house6, house7 };
		reviews = { review1 };
	}
	else // If files already have data then reload data to objects
	{
		// Open user file
		myUserFile.open("user.dat", std::ios::in);

		if (!myUserFile.is_open()) {
			cout << "Fail to open file \n";
		}

		/* Reload users' data from the file */
		string dataUsername, dataPassword, dataFullname, dataPhoneNumber, dataCreditPoint, dataRole, dataUserHouseId, dataRatingScore;

		vector<User*> userImport = {};

		while (!myUserFile.eof()) {

			dataUsername = "", dataPassword = "", dataFullname = "", dataPhoneNumber = "", dataCreditPoint = "", dataRole = "", dataUserHouseId = "", dataRatingScore = "";

			// Read data from file
			getline(myUserFile, dataUsername, ':'); // read until seeing ':' character
			getline(myUserFile, dataPassword, ':');
			getline(myUserFile, dataFullname, ':');
			getline(myUserFile, dataPhoneNumber, ':');
			getline(myUserFile, dataCreditPoint, ':');
			getline(myUserFile, dataRatingScore, ':');
			getline(myUserFile, dataRole, ':');
			getline(myUserFile, dataUserHouseId);

			if (dataUsername == "" || dataUsername == "\n")
				break;

			User* dataUser = new (std::nothrow) User(dataUsername, dataPassword, dataFullname, dataPhoneNumber, std::stoi(dataCreditPoint), std::stof(dataRatingScore));
			dataUser->setRole(stoi(dataRole));
			dataUser->setUserHouseId(stoi(dataUserHouseId));

			userImport.push_back(dataUser);
		}

		myUserFile.close(); // Close user file

		// Open house file
		myHouseFile.open("house.dat", std::ios::in);

		if (!myHouseFile.is_open()) {
			cout << "Fail to open file \n";
		}

		/* Reload houses' data from the file */
		string dataHouseId, dataHouseLocation, dataHouseDescription, dataHouseUsername, dataHouseAcceptOccupation,// 
			dataHouseStatus, dataHouseRentStatus, dataHouseConsumingPoint, dataHouseMinOccupierRating, //
			dataHouseRatingScore, dataHouseReviewId, dataHouseRequestList, dataHouseRentDate;

		vector<House*> houseImport = {};

		while (!myHouseFile.eof()) {

			dataHouseId = "", dataHouseLocation = "", dataHouseDescription = "", dataHouseUsername = "", dataHouseAcceptOccupation = "";
			dataHouseStatus = "", dataHouseRentStatus = "", dataHouseConsumingPoint = "", dataHouseMinOccupierRating = "", dataHouseRatingScore = "";
			dataHouseReviewId = "", dataHouseRequestList = "", dataHouseRentDate = std::string("");

			// Read data from file
			getline(myHouseFile, dataHouseId, ':'); // read until seeing ':' character
			getline(myHouseFile, dataHouseLocation, ':');
			getline(myHouseFile, dataHouseDescription, ':');
			getline(myHouseFile, dataHouseUsername, ':');
			getline(myHouseFile, dataHouseAcceptOccupation, ':');
			getline(myHouseFile, dataHouseStatus, ':');
			getline(myHouseFile, dataHouseRentStatus, ':');
			getline(myHouseFile, dataHouseConsumingPoint, ':');
			getline(myHouseFile, dataHouseMinOccupierRating, ':');
			getline(myHouseFile, dataHouseRatingScore, ':');
			getline(myHouseFile, dataHouseReviewId, ':');
			getline(myHouseFile, dataHouseRequestList, ':');
			getline(myHouseFile, dataHouseRentDate);

			if (dataHouseId == "" || dataHouseId == "\n")
				break;

			House* dataHouse = new (std::nothrow) House(stoi(dataHouseId), dataHouseLocation, dataHouseDescription, stoi(dataHouseStatus), stoi(dataHouseConsumingPoint), stoi(dataHouseMinOccupierRating));
			dataHouse->setStatus(stoi(dataHouseStatus));
			dataHouse->setUsername(dataHouseUsername);
			dataHouse->setRentStatus(stoi(dataHouseRentStatus));
			dataHouse->setHouseRatingScore(stoi(dataHouseRatingScore));
			dataHouse->setHouseReviewId(stoi(dataHouseReviewId));

			// Extract occupier's name from request list and set back to object
			vector<string> houseRequestList = split(dataHouseRequestList, ',');

			dataHouse->setRequestOccupation(houseRequestList);

			// Extract day, month, year and store back to object
			if (dataHouseRentDate.find("N/A") == std::string::npos) {
				vector<string> houseRentDate = split(dataHouseRentDate, '/');

				if (houseRentDate.size() > 0)
				{
					RentDate* dataHouseRentDate = new (std::nothrow) RentDate();
					dataHouseRentDate->setDay(stoi(houseRentDate[0]));
					dataHouseRentDate->setMonth(stoi(houseRentDate[1]));
					dataHouseRentDate->setYear(stoi(houseRentDate[2]));

					dataHouse->setRentDate(dataHouseRentDate);
				}
			}

			houseImport.push_back(dataHouse);
		}

		myHouseFile.close(); // Close house file

		// Open review file
		myReviewFile.open("review.dat", std::ios::in);

		if (!myReviewFile.is_open()) {
			cout << "Fail to open file \n";
		}

		/* Reload reviews' data from the file */
		string dataReviewId, dataReviewHouseId, dataReviewer, dataReviewScore, //
			dataReviewComment, dataReviewDate, dataReviewHouseOwner, dataReviewOwnerScore, //
			dataReviewOwnerComment, dataReviewOwnerReviewDate, dataReviewOwnerWriterReview;
		vector<Review*> reviewImport = {};

		while (!myReviewFile.eof()) {

			dataReviewId = "", dataReviewHouseId = "", dataReviewer = "", dataReviewScore = "", dataReviewComment = "";
			dataReviewDate = "", dataReviewHouseOwner = "", dataReviewOwnerScore = "", dataReviewOwnerComment = "";
			dataReviewOwnerReviewDate = "", dataReviewOwnerWriterReview = "";

			// Read data from file
			getline(myReviewFile, dataReviewId, ':'); // read until seeing ':' character
			getline(myReviewFile, dataReviewHouseId, ':');
			getline(myReviewFile, dataReviewer, ':');
			getline(myReviewFile, dataReviewScore, ':');
			getline(myReviewFile, dataReviewComment, ':');
			getline(myReviewFile, dataReviewDate, ':');
			getline(myReviewFile, dataReviewHouseOwner, ':');
			getline(myReviewFile, dataReviewOwnerScore, ':');
			getline(myReviewFile, dataReviewOwnerComment, ':');
			getline(myReviewFile, dataReviewOwnerReviewDate, ':');
			getline(myReviewFile, dataReviewOwnerWriterReview);

			if (dataReviewId == "" || dataReviewId == "\n")
				break;

			Review* dataReview = new (std::nothrow) Review(stoi(dataReviewId), stoi(dataReviewHouseId), dataReviewer, stoi(dataReviewScore), dataReviewComment);
			dataReview->setHouseOwner(dataReviewHouseOwner);
			dataReview->setOwnerScore(stoi(dataReviewOwnerScore));
			dataReview->setOwnerComment(dataReviewOwnerComment);
			dataReview->setOwnerWriteReview(stoi(dataReviewOwnerWriterReview));

			// Extract day, month, year and store back to object
			if (dataReviewDate.find("N/A") == std::string::npos) {
				vector<string> reviewDate = split(dataReviewDate, '/');
				if (reviewDate.size() > 0)
				{
					RentDate* dataReviewDate = new (std::nothrow) RentDate();
					dataReviewDate->setDay(stoi(reviewDate[0]));
					dataReviewDate->setMonth(stoi(reviewDate[1]));
					dataReviewDate->setYear(stoi(reviewDate[2]));

					dataReview->setReviewDate(dataReviewDate);
				}
			}

			if (dataReviewOwnerReviewDate.find("N/A") == std::string::npos) {
				vector<string> ownerReviewDate = split(dataReviewOwnerReviewDate, '/');
				if (ownerReviewDate.size() > 0)
				{
					RentDate* dataOwnerReviewDate = new (std::nothrow) RentDate();
					dataOwnerReviewDate->setDay(stoi(ownerReviewDate[0]));
					dataOwnerReviewDate->setMonth(stoi(ownerReviewDate[1]));
					dataOwnerReviewDate->setYear(stoi(ownerReviewDate[2]));

					dataReview->setOwnerReviewDate(dataOwnerReviewDate);
				}
			}

			reviewImport.push_back(dataReview);
		}

		myReviewFile.close(); // Close review file

		// Update house information of a user
		for (auto u : userImport)
		{
			if (u->getUserHouseId() <= 0)
			{
				continue;
			}

			for (auto h : houseImport)
			{
				if (h->getId() == u->getUserHouseId())
				{
					u->setHouse(*h);
					break;
				}
			}
		}

		// Create vectors with corresponding data
		users = { userImport };
		houses = { houseImport };
		reviews = { reviewImport };
	}


	/*showUsersInfo(users, true);
	showBasicHouseInfo(houses);
	showHouseInfo(houses, users);
	showAvailableHouseInfo(houses);*/


	int role, featureChoice, subFeature;
	do
	{
		cout << endl
			<< endl
			<< "EEET2482/COSC2082 ASSIGNMENT" << endl;
		cout << "VACATION HOUSE EXCHANGE APPLICATION" << endl
			<< endl;
		cout << "Instructors: Mr. Linh Tran & Phong Ngo" << endl;
		cout << "Group: Group 6" << endl;
		cout << "s3877791, Nguyen Thien Dat" << endl;
		cout << "s3741297, Le Trung Hau " << endl;
		cout << "s3878693, Lai Phuc Anh " << endl;
		cout << "s3836413, Ly Anh Khoa " << endl
			<< endl;
		cout << "Use the app as 1. Guest   2. Member   3. Admin" << endl;
		cout << "0. Exit the program" << endl;
		cout << endl << "Enter your choice: ";
		cin >> role;

		// Declare variables for register features:
		string username, password, fullname, phoneNumber, houseLocation, houseDescription;
		House* house = new (std::nothrow) House();
		User* user = new (std::nothrow) User();
		House globalHouse;
		string occuppierName;
		bool flag = false, adminFlag = false;
		int houseId;
		int maxHouseId = 0;
		int count = 0, adminCount = 0;

		bool found = false;
		bool isOccupied = false;
		int occupiedHouseId = 0;
		int maxReviewId = 0;
		bool isReviewed = false;

		switch (role)
		{
		case 1:
			int guestChoice;

			cout << endl
				<< "You use the app as Guest." << endl
				<< "-------------------- Guest's choice --------------------" << endl;
			cout << "1. Register" << endl;
			cout << "2. Seach and view house detail" << endl;
			cout << "3. Back to main features" << endl;
			cout << "Enter your choice: ";
			cin >> guestChoice;

			switch (guestChoice)
			{
			case 1: // A non-member can register to become a member (information is recorded)
				username = "", password = "", phoneNumber = "";

				cout << endl;
				cin.ignore();
				do
				{
					cout << "Enter username: ";
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

				user->setUsername(username);
				user->setPassword(password);
				user->setFullname(fullname);
				user->setPhoneNumber(phoneNumber);
				user->setRatingScore(0);

				int houseChoice;
				cout << endl
					<< endl
					<< "-------------------- Guest's choice --------------------" << endl;
				cout << "1. Register your house information" << endl;
				cout << "2. Skip" << endl;
				cout << "Enter your choice: ";
				cin >> houseChoice;

				switch (houseChoice)
				{
				case 1: // House registration for member
					maxHouseId = findMaxHouseId(houses) + 1;
					house->setId(maxHouseId);

					cin.ignore();
					do
					{
						cout << "Enter your house location (location must be: 'Ha Noi', 'Hue', 'HCM'): ";
						getline(cin, houseLocation);
						house->setLocation(houseLocation);
					} while (!validateHouseInput(*house));

					cout << "Enter house description: ";
					getline(cin, houseDescription);
					house->setDescription(houseDescription);
					house->setUsername(user->getUsername());
					user->setHouse(*house);
					houses.push_back(house);
					break;
				case 2: // If member does not want to register house
					break;
				}

				// Validate input from user
				cout << "> Register successfully!" << endl;
				user->setRole(2);
				user->setCreditPoint(500);
				users.push_back(user);
				showUsersInfo(users, true);

				break;
			case 2: // Search and view house detail
				showBasicHouseHeader();
				for (int i = 0; i < houses.size(); i++)
				{
					if (houses[i]->getStatus())
					{
						cout << endl;
						houses[i]->showBasicInfo();
						cout << ", owner of this house is ";

						for (int j = 0; j < users.size(); j++)
						{
							if (caseInsensitiveStringCompare(users[j]->getUsername(), houses[i]->getUsername()))
							{
								cout << users[j]->getFullname() << ", phone: " << users[j]->getPhoneNumber();
								break;
							}
						}
					}
				}
				break;
			case 3: // Back to main menu
				break;
			}

			// cout << "Register as member/View house details without seeing reviews or availibility" << endl;
			break;
		case 2:
			cout << endl
				<< "You use the app as Member." << endl;
			username = "", password = ""; // Reset username and password
			cin.ignore();
			do
			{
				do
				{
					cout << "Enter username: ";
					getline(cin, username);
				} while (username == "");

				do
				{
					cout << "Enter password: ";
					getline(cin, password);
				} while (password == "");

				// Checking username and password
				transform(username.begin(), username.end(), username.begin(), ::tolower);

				for (int i = 0; i < users.size(); i++)
				{
					if (caseInsensitiveStringCompare(users[i]->getUsername(), username) //
						&& caseSensitiveStringCompare(users[i]->getPassword(), password))
					{
						cout << "> Login successfully!" << endl;
						cout << "> Welcome " << username << " to the vacation house exchange app!" << endl;
						flag = true;
						user = users[i];
						break;
					}
				}

				if (flag == false)
				{
					count++;
					cout << "You have entered wrong password more than " << count << " times" << endl;
				}

				if (count >= 3)
				{
					cout << "You have entered wrong password more than " << count << " times" << endl;
					flag = true;
				}

			} while (count <= 3 && !flag);

			if (count >= 3)
			{
				cout << "Your account will be block!" << endl;
				break;
			}

			// Member section
			int memberChoice;

			do
			{
				// Check if a user occupy a house or not
				for (auto house : houses)
				{
					if (caseInsensitiveStringCompare(house->getAcceptOccupation(), user->getUsername()) //
						&& house->getRentStatus() == true)
					{
						isOccupied = true;
						occupiedHouseId = house->getId();
						break;
					}
				}

				// Check if the house owner want to give feedback about occupier
				for (auto review : reviews)
				{
					if (caseInsensitiveStringCompare(review->getHouseOwner(), user->getUsername()) //
						&& review->getOwnerWriteReview() == true)
					{
						isReviewed = true;
						break;
					}
				}

				cout << endl
					<< endl
					<< "-------------------- Member's choice --------------------" << endl;
				cout << "1. View all information" << endl;
				cout << "2. List available house to be occupied" << endl;
				cout << "3. List of requests" << endl;
				cout << "4. Unlist house" << endl;
				cout << "5. Search and request to occupy a house" << endl;
				if (isOccupied)
				{
					cout << "6. Return occupied house" << endl;
				}
				if (isReviewed)
				{
					cout << "7. House owner reviews occupier" << endl;
				}
				cout << "0. Back to main features" << endl;
				cout << endl
					<< "Enter your choice: ";
				cin >> memberChoice;

				switch (memberChoice)
				{
				case 1: // View member information
					for (int i = 0; i < users.size(); i++)
					{
						if (caseInsensitiveStringCompare(users[i]->getUsername(), username) //
							&& caseSensitiveStringCompare(users[i]->getPassword(), password))
						{
							showUserHeaderIncludeHouse();
							users[i]->showInfoIncludeHouse();
							break;
						}
					}

					break;
				case 2: // List available houses
					for (auto house : houses)
					{
						if (caseInsensitiveStringCompare(house->getUsername(), username))
						{
							if (house->getStatus() == true)
							{
								showAllHouseHeader();
								cout << endl;
								house->showAllInfo();
								break;
							}
						}
					}

					break;
				case 3: // List of requests and accept one of the occupier requests					
					for (auto house : houses)
					{
						if (caseInsensitiveStringCompare(house->getUsername(), username))
						{
							if (house->getStatus() == true)
							{
								if (house->getRequestOccupation().size() <= 0)
								{
									cout << "\nThere is no request";
									break;
								}
								// List requests
								house->showAllRequestOccupation();
								globalHouse = *house;

								cout << "Enter username that you want to accept request (type '0' if you want to escape): ";
								cin >> occuppierName;

								if (occuppierName == "0")
								{
									break;
								}

								// Accept occupier request
								for (auto request : globalHouse.getRequestOccupation())
								{
									if (caseInsensitiveStringCompare(request, occuppierName))
									{
										globalHouse.setAcceptOccupation(occuppierName);
										globalHouse.setRentStatus(true);

										// Review house and set the house owner attribute
										maxReviewId = findMaxReviewId(reviews) + 1;
										Review* review = new (std::nothrow) Review(maxReviewId, globalHouse.getId(), occuppierName, 0, "", RentDate(true));
										review->setHouseOwner(user->getUsername());
										reviews.push_back(review);

										// Accept occupier's request and set the occupier's review Id
										for (auto house : houses)
										{
											if (house->getId() == globalHouse.getId())
											{
												house->setAcceptOccupation(occuppierName);
												house->setRentStatus(true);
												house->setHouseReviewId(maxReviewId);
												cout << endl
													<< "Accept request successfully!";
												break;
											}
										}
									}
								}

								break;
							}
						}
					}

					break;
				case 4: // Unlist house (hide house)
					for (auto house : houses)
					{
						if (caseInsensitiveStringCompare(house->getUsername(), username))
						{
							if (house->getStatus() == false)
							{
								break;
							}
							else
							{
								house->setStatus(false);
							}
						}
					}
					break;
				case 5: // Search house

					cin.ignore();
					do
					{
						cout << "Enter house location (location must be 'Ha Noi', 'Hue', or 'HCM'): ";
						getline(cin, houseLocation);
					} while (houseLocation == "");

					for (auto house : houses)
					{
						if (caseInsensitiveStringCompare(house->getLocation(), houseLocation)			//
							&& user->getCreditPoint() >= house->getConsumingPoint()						//
							&& user->getRatingScore() >= house->getMinOccupierRating()					//
							&& !caseInsensitiveStringCompare(house->getUsername(), user->getUsername()) //
							&& house->getStatus() == true												//
							&& house->getRentStatus() == false)
						{
							found = true;
							break;
						}
					}

					// If true then print out all available houses
					if (found)
					{
						cout << endl
							<< "> Houses that match your demand" << endl;
						showAllHouseHeader();

						// Display houses that match your entered location
						for (auto house : houses)
						{
							if (caseInsensitiveStringCompare(house->getLocation(), houseLocation)			//
								&& user->getCreditPoint() >= house->getConsumingPoint()						//
								&& user->getRatingScore() >= house->getMinOccupierRating()					//
								&& !caseInsensitiveStringCompare(house->getUsername(), user->getUsername()) //
								&& house->getStatus() == true												//
								&& house->getRentStatus() == false)
							{
								cout << endl;
								house->showAllInfo();
							}
						}

						cout << endl
							<< endl
							<< "Enter the house's ID that you want to occupy: ";
						cin >> houseId;

						for (auto house : houses)
						{
							if (house->getId() == houseId)
							{
								// Choose house to occupy
								house->addPersonToRequestList(user->getUsername());
								cout << "> Request successfully!" << endl;
							}
						}
					}
					else
					{
						// If false then print out no available message
						cout << endl
							<< "There is no available house for this user: " << user->getUsername();
					}
					break;
				case 6: // Return house (check out)
					for (auto house : houses)
					{
						if (house->getId() == occupiedHouseId)
						{
							// Update occupier's credit point
							int remainCreditPoint = user->getCreditPoint() - house->getConsumingPoint();
							user->setCreditPoint(remainCreditPoint);

							// Update house owner's credit point
							for (auto u : users)
							{
								if (caseInsensitiveStringCompare(u->getUsername(), house->getUsername()))
								{
									u->setCreditPoint(u->getCreditPoint() + house->getConsumingPoint());
									break;
								}
							}

							for (auto u : users)
							{
								if (caseInsensitiveStringCompare(u->getUsername(), user->getUsername()))
								{
									u->setCreditPoint(remainCreditPoint);
									break;
								}
							}

							// Occupier writes review
							for (auto review : reviews)
							{
								if (review->getReviewId() == house->getHouseReviewId())
								{
									int reviewScore;
									do
									{
										cout << "Enter the review score: ";
										cin >> reviewScore;
									} while (!(reviewScore >= -10 && reviewScore <= 10));

									string reviewComment;
									cin.ignore();
									do
									{
										cout << "Enter the review comment: ";
										getline(cin, reviewComment);
									} while (reviewComment == "");

									review->setReviewId(maxReviewId + 1);
									review->setReviewHouseId(house->getId());
									review->setReviewer(user->getUsername());
									review->setReviewScore(reviewScore);
									review->setReviewComment(reviewComment);

									RentDate rendate(true);
									review->setReviewDate(rendate);

									review->setOwnerWriteReview(true);

									// Update house's rating score
									float totalHouseRatingScore = 0, countHouseRatingScore = 0;

									for (auto r : reviews) // Check how many times that occupier occupy house
									{
										if (review->getReviewHouseId() == r->getReviewHouseId())
										{
											totalHouseRatingScore += r->getReviewScore();
											countHouseRatingScore++;
										}
									}

									float averageRatingScoreOfHouse = totalHouseRatingScore / (countHouseRatingScore * 1.0);
									house->setHouseRatingScore(averageRatingScoreOfHouse);

									showAllReviewHeader();
									cout << endl;
									review->showOccupierReview();
								}
							}

							// Update house
							house->setRentStatus(false);
							house->setRequestOccupation({});
							house->setAcceptOccupation("");
							house->setHouseReviewId(0);
						}
					}
					break;

				case 7: // House owner review occupier
					for (auto review : reviews)
					{
						if (caseInsensitiveStringCompare(review->getHouseOwner(), user->getUsername()) //
							&& review->getOwnerWriteReview() == true)
						{
							int ownerReviewScore;
							do
							{
								cout << "Enter the review score: ";
								cin >> ownerReviewScore;
							} while (!(ownerReviewScore >= -10 && ownerReviewScore <= 10));

							string ownerReviewComment;
							cin.ignore();
							do
							{
								cout << "Enter the review comment: ";
								getline(cin, ownerReviewComment);
							} while (ownerReviewComment == "");

							review->setOwnerScore(ownerReviewScore);
							review->setOwnerComment(ownerReviewComment);
							RentDate rendate(true);
							review->setOwnerReviewDate(rendate);
							review->setOwnerWriteReview(false);

							showAllReviewHeader();
							cout << endl;
							review->showOwnerReview();

							// Update occupier's rating score
							float s = 0, countReviewer = 0;

							for (auto r : reviews) // Check how many times that occupier occupy house
							{
								if (caseInsensitiveStringCompare(review->getReviewer(), r->getReviewer()))
								{
									s += r->getOwnerScore();
									countReviewer++;
								}
							}

							float averageRatingScoreOfReviewer = s / (countReviewer * 1.0); // Compute the average rating score

							for (auto u : users) // Set the average rating score
							{
								if (caseInsensitiveStringCompare(u->getUsername(), review->getReviewer()))
								{
									u->setRatingScore(averageRatingScoreOfReviewer);
									break;
								}
							}
						}
					}
					break;
				}
			} while (memberChoice != 0);

			break;
		case 3:
			/* Admin section */
			username = "", password = ""; // Reset username and password
			cout << endl
				<< "You are using the app as Admin." << endl;

			cin.ignore();
			do
			{
				do
				{
					cout << "Enter username: ";
					getline(cin, username);
				} while (username == "");

				do
				{
					cout << "Enter password: ";
					getline(cin, password);
				} while (password == "");

				// Checking username and password
				transform(username.begin(), username.end(), username.begin(), ::tolower);

				for (int i = 0; i < users.size(); i++)
				{
					if (caseInsensitiveStringCompare(users[i]->getUsername(), username) //
						&& caseSensitiveStringCompare(users[i]->getPassword(), password) //
						&& users[i]->getRole() == 3)
					{
						cout << "> Login successfully!" << endl;
						cout << "> Welcome " << username << " to the vacation house exchange app!" << endl;
						adminFlag = true;
						user = users[i];
						break;
					}
				}

				if (adminFlag == false)
				{
					adminCount++;
					cout << "You have entered wrong password more than " << adminCount << " times" << endl;
				}

				if (adminCount >= 3)
				{
					cout << "You have entered wrong password more than " << adminCount << " times" << endl;
					adminFlag = true;
				}

			} while (adminCount <= 3 && !adminFlag);

			if (adminCount >= 3)
			{
				cout << "Your account will be block!" << endl;
				break;
			}

			int adminChoice;

			do
			{
				cout << endl
					<< endl
					<< "-------------------- Admin's choice --------------------" << endl;
				cout << "1. View all members' information" << endl;
				cout << "0. Back to main menu" << endl;

				cout << "Enter your choice: ";
				cin >> adminChoice;

				switch (adminChoice)
				{
				case 1: // Show all members information
					showUserHeaderIncludeHouse();
					for (auto user : users)
					{

						user->showInfoIncludeHouse();
					}
					break;
				}

			} while (adminChoice != 0);
			break;
		}

	} while (role != 0);

	/* Save data to files */
	// Save user data to file
	myUserFile.open("user.dat", std::ios::out);
	if (!myUserFile) {
		cout << "Fail to create/open file \n";
	}

	//Store user data to the user data file
	for (auto userData : users) {
		myUserFile << userData->getUsername() << ":" << userData->getPassword() << ":" << userData->getFullname() << ":" << userData->getPhoneNumber() //
			<< ":" << userData->getCreditPoint() << ":" << userData->getRatingScore() << ":" << userData->getRole() << ":" << userData->getUserHouse().getId() << "\n";
	}

	myUserFile.close();

	// Save house data to file
	myHouseFile.open("house.dat", std::ios::out);
	if (!myHouseFile) {
		cout << "Fail to create/open file \n";
	}

	// Store house data to the house data file
	for (auto houseData : houses)
	{
		std::string delim = ",";
		std::string requestOccupationList = join(houseData->getRequestOccupation(), delim);

		myHouseFile << houseData->getId() << ":" << houseData->getLocation() << ":" << houseData->getDescription() << ":" //
			<< houseData->getUsername() << ":" << houseData->getAcceptOccupation() << ":" << houseData->getStatus() << ":" << houseData->getRentStatus() << ":" //
			<< houseData->getConsumingPoint() << ":" << houseData->getMinOccupierRating() << ":" << houseData->getHouseRatingScore() << ":" << houseData->getHouseReviewId() //
			<< ":" << requestOccupationList << ":" << houseData->getRentDate().toString() << "\n";
	}

	myHouseFile.close();

	// Save review data to file
	myReviewFile.open("review.dat", std::ios::out);
	if (!myReviewFile) {
		cout << "Fail to create/open file \n";
	}

	// Store review data to the review data file
	for (auto reviewData : reviews)
	{
		myReviewFile << reviewData->getReviewId() << ":" << reviewData->getReviewHouseId() << ":" << reviewData->getReviewer() << ":" //
			<< reviewData->getReviewScore() << ":" << reviewData->getReviewComment() << ":" << reviewData->getReviewDate().toString() << ":" //
			<< reviewData->getHouseOwner() << ":" << reviewData->getOwnerScore() << ":" << reviewData->getOwnerComment() << ":" << reviewData->getOwnerReviewDate().toString() //
			<< ":" << reviewData->getOwnerWriteReview() << "\n";
	}

	myReviewFile.close();

	return 0;
}
