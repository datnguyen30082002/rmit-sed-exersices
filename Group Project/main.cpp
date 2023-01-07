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

using namespace std;

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



int main()
{
	User* admin1 = new (std::nothrow) User("admin1", "1", "ADMIN 1", "0912000111", 500);
	User* admin2 = new (std::nothrow) User("admin2", "1", "ADMIN 2", "0912333555", 500);
	User* user1 = new (std::nothrow) User("user1", "1", "User 1", "0823248508", 500, 9);
	User* user2 = new (std::nothrow) User("user2", "1", "User 2", "0855656565", 500, 3);
	User* user3 = new (std::nothrow) User("user3", "1", "User 3", "0955764201", 500, 5);
	User* user4 = new (std::nothrow) User("user4", "1", "User 4", "0955764202", 500, 7);
	User* user5 = new (std::nothrow) User("user5", "1", "User 5", "0955764202", 500, 7);
	User* user6 = new (std::nothrow) User("user6", "1", "User 6", "0955764202", 500, 7);
	User* user7 = new (std::nothrow) User("user7", "1", "User 7", "0955764202", 500, 7);


	House* house1 = new (std::nothrow) House(1, "HCM", "house of user 1", true, 100, 5, false);
	House* house2 = new (std::nothrow) House(2, "Ha Noi", "house of user 2", true, 120, 6, false);
	House* house3 = new (std::nothrow) House(3, "Hue", "house of user 3", true, 150, 7, true);
	House* house4 = new (std::nothrow) House(4, "Ha Noi", "house of user 4", false, 110, 4, false);
	House* house5 = new (std::nothrow) House(5, "Hue", "house of user 5", false, 190, 8, false);
	House* house6 = new (std::nothrow) House(6, "Ha Noi", "house of user 6", true, 150, 5, false);
	House* house7 = new (std::nothrow) House(7, "Hue", "house of user 7", true, 120, 0, false);

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

	// for testing
	/*house2->setAcceptOccupation("user1");
	house2->setRentStatus(true);
	house2->setHouseReviewId(1);*/
	Review* review1 = new (std::nothrow) Review();
	/*review1->setReviewId(1);
	review1->setReviewHouseId(2);
	review1->setReviewer("user1");
	review1->setReviewScore(0);
	review1->setReviewComment("");
	review1->setReviewDate(RentDate(3, 1, 2023));

	review1->setHouseOwner("user2");
	review1->setOwnerWriteReview(true);
	review1->setOwnerReviewDate(RentDate(5, 1, 2023));*/


	showAllHouseHeader();
	cout << endl;
	house1->showAllInfo();

	// house1->addPersonToRequestList("name");
	// cout << "\n size = ";
	// house1->getRequestOccupation().size();

	vector<User*> users = { admin1, admin2, user1, user2, user3, user4, user5, user6, user7 };
	vector<House*> houses = { house1, house2, house3,house4, house5, house6, house7 };
	vector<Review*> reviews = { review1 };

	showUsersInfo(users, true);
	showBasicHouseInfo(houses);
	showHouseInfo(houses, users);
	// showAvailableHouseInfo(houses);

	fstream myFile;
	string userFile = "user.dat";
	string houseFile = "house.dat";

	/* Create user data file and write to that file*/
	myFile.open(userFile, std::ios::out); // open file

	// If file cannot open then print out meaningful message
	if (!myFile)
	{
		cerr << "Fail to open file \n";
	}

	for (auto u : users)
	{
		myFile << u->getUsername() << ':' << u->getFullname() << ':'
			<< u->getPassword() << u->getPhoneNumber() << ':' << u->getCreditPoint() << endl;
	}
	cout << endl
		<< endl
		<< "Saved user data to file!" << endl;

	myFile.close(); // close file

	/* Create house data file and write to that file*/
	myFile.open(houseFile, std::ios::out); // open file

	// If file cannot open then print out meaningful message
	if (!myFile)
	{
		std::cerr << "Fail to open file \n";
	}

	for (auto h : houses)
	{
		myFile << h->getId() << ":" << h->getLocation() << ':' << h->getDescription() << endl;
	}
	std::cout << "Saved house data to file!" << endl;

	myFile.close(); // close file

	// // Read user data and store back to user object
	// vector<User *> myUsers;

	// myFile.open(userFile, std::ios::in);

	// if (!myFile)
	// {
	//      cerr << "Fail to open file \n";
	// }

	// // char *s = new char[100];
	// // while (myFile.good())
	// // {
	// //      myFile.getline(s, 100, ',');
	// //      myUsers.push_back(s);
	// // }

	// myFile.close();

	// std::vector<std::string>::iterator it;
	// for (it = myvector.begin(); it != myvector.end(); it++)
	//      std::cout << *it << std::endl;

	// while (!myFile.eof())
	// {
	//      // 1. read by a line
	//      // 2. split by ; delimiter
	//      // 3. parse to variable values
	//      // 4. User *user1 = new (std::nothrow) User();
	//      // user1.setUsername(usename) from varible
	// }

	int role, featureChoice, subFeature;
	do
	{
		cout << "\n\n\tEEET2482/COSC2082 ASSIGNMENT" << endl;
		cout << "\tVACATION HOUSE EXCHANGE APPLICATION" << endl
			<< endl;
		cout << "\tInstructors: Mr. Linh Tran & Phong Ngo" << endl;
		cout << "\tGroup: Group 6" << endl;
		cout << "\ts3877791, Nguyen Thien Dat" << endl;
		cout << "\ts3741297, Le Trung Hau " << endl;
		cout << "\ts3878693, Lai Phuc Anh " << endl;
		cout << "\ts3836413, Ly Anh Khoa " << endl
			<< endl;
		cout << "Use the app as 1. Guest   2. Member   3. Admin" << endl;
		cout << "0. Exit the program" << endl;
		cout << "Enter your choice: ";
		cin >> role;

		// Declare variables for register features:
		string username, password, fullname, phoneNumber, houseLocation, houseDescription;
		// Review* review1 = new (std::nothrow) Review();
		House* house = new (std::nothrow) House();
		User* user = new (std::nothrow) User();
		House globalHouse;
		string occuppierName;
		bool flag = false;
		int houseId;
		int maxHouseId = 0;
		int count = 0;

		bool found = false;
		bool isOccupied = false;
		int occupiedHouseId = 0;
		int maxReviewId = 0;
		bool isReviewed = false;

		switch (role)
		{
		case 1:
			cout << "You use the app as Guest." << endl;
			int guestChoice;
			cout << "1. Register" << endl;
			cout << "2. Seach and view house detail" << endl;
			cout << "3. Back to main features" << endl;
			cout << "Enter your choice: ";
			cin >> guestChoice;

			switch (guestChoice)
			{
			case 1: // A non-member can register to become a member (information is recorded)
				username = "", password = "", phoneNumber = "";

				do
				{
					cout << "Enter username: ";
					getline(cin, username, '\n');
				} while (!validateUsernameOfUser(users, username));

				cout << "Enter fullname: ";
				getline(cin, fullname);

				do
				{
					cout << "Enter password: ";
					getline(cin, password, '\n');
				} while (!validatePasswordOfUser(users, password));

				do
				{
					cout << "Enter phone number: ";
					getline(cin, phoneNumber, '\n');
				} while (!validatePhoneNumberOfUser(users, phoneNumber));

				user->setUsername(username);
				user->setPassword(password);
				user->setFullname(fullname);
				user->setPhoneNumber(phoneNumber);
				user->setRatingScore(0);

				int houseChoice;
				cout << "1. Register your house information" << endl;
				cout << "2. Skip" << endl;
				cout << "Enter your choice: ";
				cin >> houseChoice;

				switch (houseChoice)
				{
				case 1: // House registration for member
					maxHouseId = findMaxHouseId(houses) + 1;
					house->setId(maxHouseId);

					do
					{
						cout << "Enter your house location (location must be: 'Ha Noi', 'Hue', 'HCM'): ";
						// cin.ignore();
						getline(cin, houseLocation, '\n');
						house->setLocation(houseLocation);
					} while (!validateHouseInput(*house));

					cout << "Enter house description: ";
					getline(cin, houseDescription, '\n');
					house->setDescription(houseDescription);

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
			cout << "You use the app as Member." << endl;
			username = "", password = ""; // Reset username and password

			do
			{
				do
				{
					cout << "Enter username: ";
					getline(cin, username, '\n');
				} while (username == "");

				do
				{
					cout << "Enter password: ";
					getline(cin, password, '\n');
				} while (password == "");

				// Checking username and password
				transform(username.begin(), username.end(), username.begin(), ::tolower);

				cout << "\n username = " << username << ", password = " << password << endl; // for testing

				for (int i = 0; i < users.size(); i++)
				{
					if (caseInsensitiveStringCompare(users[i]->getUsername(), username) //
						&& caseSensitiveStringCompare(users[i]->getPassword(), password))
					{
						cout << "> Login successfully!" << endl;
						cout << "> Welcome " << username << " to the vacation house exchange app!" << endl;
						// users[i]->setRole(2);
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
				cout << "Your account will be block!" << endl;

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
				cout << endl
					<< "1. View all information" << endl;
				cout << "2. List available house to be occupied / List of requests" << endl;
				cout << "3. Unlist house" << endl;
				cout << "4. Search and request to occupy a house" << endl;
				if (isOccupied)
				{
					cout << "5. Return occupied house" << endl;
				}
				if (isReviewed)
				{
					cout << "6. House owner reviews occupier" << endl;
				}
				cout << "0. Back to main features" << endl;
				cout << "Enter your choice: ";
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
					cout << endl
						<< "username = " << username << endl;
					for (auto house : houses)
					{
						if (caseInsensitiveStringCompare(house->getUsername(), username))
						{
							cout << "\n status = " << house->getStatus();
							if (house->getStatus() == true)
							{
								showAllHouseHeader();
								cout << endl;
								house->showAllInfo();
								house->showAllRequestOccupation();
								globalHouse = *house;
								break;
							}
						}
					}

					
					cout << "Enter username that you want to accept request: ";
					cin >> occuppierName;

					// Accept occupier request
					for (auto request : globalHouse.getRequestOccupation())
					{
						if (caseInsensitiveStringCompare(request, occuppierName))
						{
							globalHouse.setAcceptOccupation(occuppierName);
							globalHouse.setRentStatus(true);

							// Review house and set the house owner attribute
							maxReviewId = findMaxReviewId(reviews);
							Review review(maxReviewId + 1, globalHouse.getId(), occuppierName, 0, "", RentDate());
							review.setHouseOwner(user->getUsername());
							reviews.push_back(&review);

							// Accept occupier's request and set the occupier's review Id
							for (auto house : houses)
							{
								if (house->getId() == globalHouse.getId())
								{
									house->setAcceptOccupation(occuppierName);
									house->setRentStatus(true);
									house->setHouseReviewId(maxReviewId);
									break;
								}
							}
						}
					}

					break;
				case 3: // Unlist house (hide house)
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
				case 4: // Search house
					do
					{
						cout << "Enter house location: ";
						getline(cin, houseLocation, '\n');
					} while (houseLocation == "");

					for (auto house : houses)
					{
						if (caseInsensitiveStringCompare(house->getLocation(), houseLocation) //
							&& user->getCreditPoint() >= house->getConsumingPoint()            //
							&& user->getRatingScore() >= house->getMinOccupierRating() //
							&& !caseInsensitiveStringCompare(house->getUsername(), user->getUsername()) //
							&& house->getStatus() == true //
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
							if (caseInsensitiveStringCompare(house->getLocation(), houseLocation) //
								&& user->getCreditPoint() >= house->getConsumingPoint()            //
								&& user->getRatingScore() >= house->getMinOccupierRating()         //
								&& !caseInsensitiveStringCompare(house->getUsername(), user->getUsername()) //
								&& house->getStatus() == true //
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
								cout << "Request successfully!" << endl;
								house->setRentStatus(true);
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
				case 5: // Return house (check out)
					for (auto house : houses)
					{
						if (house->getId() == occupiedHouseId)
						{
							user->setCreditPoint(user->getCreditPoint() - house->getConsumingPoint());
							for (auto u : users)
							{
								if (caseInsensitiveStringCompare(u->getUsername(), user->getUsername()))
								{
									u->setCreditPoint(u->getCreditPoint() - house->getConsumingPoint());
									break;
								}
							}
							house->setRentStatus(false);

							// Occupier writes review 
							for (auto review : reviews)
							{
								if (review->getReviewId() == house->getHouseReviewId())
								{
									int reviewScore;
									cout << "Enter the review score: ";
									cin >> reviewScore;

									string reviewComment;
									do
									{
										cout << "Enter the review comment: ";
										getline(cin, reviewComment, '\n');
									} while (reviewComment == "");

									review->setReviewId(maxReviewId + 1);
									review->setReviewHouseId(house->getId());
									review->setReviewer(user->getUsername());
									review->setReviewScore(reviewScore);
									review->setReviewComment(reviewComment);

									time_t now = time(0);
									tm* ltm = localtime(&now);
									RentDate rendate(ltm->tm_mday, ltm->tm_mon, ltm->tm_year);
									review->setReviewDate(rendate);

									review->setOwnerWriteReview(true);

									showAllReviewHeader();
									cout << endl;
									review->showOccupierReview();
								}
							}
						}
					}
					break;

				case 6: // House owner review occupier
					for (auto review : reviews)
					{
						if (caseInsensitiveStringCompare(review->getHouseOwner(), user->getUsername()))
						{
							int ownerReviewScore;
							cout << "Enter the review score: ";
							cin >> ownerReviewScore;

							string ownerReviewComment;
							do
							{
								cout << "Enter the review comment: ";
								getline(cin, ownerReviewComment, '\n');
							} while (ownerReviewComment == "");

							review->setOwnerScore(ownerReviewScore);
							review->setOwnerComment(ownerReviewComment);
							review->setReviewId(maxReviewId + 1);
							review->setReviewHouseId(house->getId());
							review->setReviewer(user->getUsername());
							review->setReviewScore(ownerReviewScore);
							review->setReviewComment(ownerReviewComment);

							time_t now = time(0);
							tm* ltm = localtime(&now);
							RentDate rendate(ltm->tm_mday, ltm->tm_mon, ltm->tm_year);
							review->setReviewDate(rendate);
							review->setOwnerWriteReview(false);

							showAllReviewHeader();
							cout << endl;
							review->showOwnerReview();
						}
					}
					break;
				}
			} while (memberChoice != 0);

			break;
		case 3:
			/* Admin section */
			username = "", password = ""; // Reset username and password
			cout << "You are using the app as Admin." << endl;

			do
			{
				cout << "Enter username: ";
				getline(cin, username, '\n');
			} while (username == "");

			do
			{
				cout << "Enter password: ";
				getline(cin, password, '\n');
			} while (password == "");

			// Checking username and password
			transform(username.begin(), username.end(), username.begin(), ::tolower);

			cout << "\n username = " << username << ", password = " << password << endl; // for testing

			for (int i = 0; i < users.size(); i++)
			{
				if (caseInsensitiveStringCompare(users[i]->getUsername(), username) //
					&& caseSensitiveStringCompare(users[i]->getPassword(), password))
				{
					cout << "> Login successfully!" << endl;
					break;
				}
			}

			int adminChoice;

			do
			{
				cout << endl
					<< "1. View all members' information" << endl;
				cout << "0. Back to main menu" << endl;

				cout << "Enter your choice: ";
				cin >> adminChoice;

				switch (adminChoice)
				{
				case 1: // Show all members information
					showUserHeaderIncludeHouse();
					for (auto user : users)
					{

						// cout << endl;
						user->showInfoIncludeHouse();
					}
					break;
				}

			} while (adminChoice != 0);
			break;
		}

	} while (role != 0);

	return 0;
}

