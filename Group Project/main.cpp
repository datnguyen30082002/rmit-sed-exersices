#include "Header.h"
#include "House.h"
#include "User.h"
#include "Utils.h"
#include <string>
#include <algorithm>
#include <cctype>
#include <fstream>

int main()
{
     User *admin1 = new (std::nothrow) User("admin1", "123456", "ADMIN 1", "0912000111", 500);
     User *admin2 = new (std::nothrow) User("admin2", "123456", "ADMIN 2", "0912333555", 500);
     User *user1 = new (std::nothrow) User("user1", "123456", "User 1", "0823248508", 500);
     User *user2 = new (std::nothrow) User("user2", "456789", "User 2", "0855764200", 500);
     User *user3 = new (std::nothrow) User("user3", "789123", "User 3", "0955764201", 500);

     House *house1 = new (std::nothrow) House(1, "HCM", "house 1", true);
     House *house2 = new (std::nothrow) House(2, "Ha Noi", "house 2", true);
     House *house3 = new (std::nothrow) House(3, "Hue", "house 3", true);
     House *house4 = new (std::nothrow) House(4, "Ha Noi", "house 4", false);
     House *house5 = new (std::nothrow) House(5, "Hue", "house 5", false);

     admin1->setRole(3);
     admin2->setRole(3);
     user1->setRole(2);
     user2->setRole(2);
     user3->setRole(2);

     user1->setHouse(*house1);
     user2->setHouse(*house2);
     user3->setHouse(*house3);

     house1->setUsername(user1->getUsername());
     house2->setUsername(user2->getUsername());
     house3->setUsername(user3->getUsername());

     vector<User *> users = {admin1, admin2, user1, user2, user3};
     vector<House *> houses = {house1, house2, house3, house4, house5};

     showUsersInfo(users, true);
     showHouseInfo(houses);
     // showAvailableHouseInfo(houses);

     // fstream myFile;
     // string userFile = "user.dat";
     // string houseFile = "house.dat";

     // /* Create user data file and write to that file*/
     // myFile.open(userFile, std::ios::out); // open file

     // // If file cannot open then print out meaningful message
     // if (!myFile)
     // {
     //      std::cerr << "Fail to open file \n";
     // }

     // for (auto u : users)
     // {
     //      myFile << u->getUsername() << ',' << u->getFullname() << ',' << u->getPassword() << u->getPhone_number() << ',' << u->getCredit_point() << '\n';
     // }
     // std::cout << "Saved user data to file !" << endl;

     // myFile.close(); // close file

     /* Create house data file and write to that file*/
     // myFile.open(houseFile, std::ios::out); // open file

     // // If file cannot open then print out meaningful message
     // if (!myFile)
     // {
     //      std::cerr << "Fail to open file \n";
     // }

     // for (auto h : houses)
     // {
     //      myFile << h->getLocation() << ',' << h->getDescription() << '\n';
     // }
     // std::cout << "Saved house data to file !" << endl;

     // myFile.close(); // close file

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
     cout << "\n\n\n\tEEET2482/COSC2082 ASSIGNMENT" << endl;
     cout << "\tVACATION HOUSE EXCHANGE APPLICATION" << endl
          << endl;
     cout << "\tInstructors: Mr. Linh Tran & Phong Ngo" << endl;
     cout << "\tGroup: Group 6" << endl;
     cout << "\ts3877791, Nguyen Thien Dat" << endl;
     cout << "\tsXXXXXXX, Student Name" << endl;
     cout << "\tsXXXXXXX, Student Name" << endl;
     cout << "\tsXXXXXXX, Student Name" << endl
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
               user.setRole(2);
               user.setCredit_point(500);
               users.push_back(&user);
               showUsersInfo(users, true);

               break;
          case 2:
               showHouseInfoHeader();
               for (int i = 0; i < houses.size(); i++)
               {
                    if (houses[i]->getStatus())
                         houses[i]->showInfo();
                    cout << ", owner of this house is ";

                    for (int i = 0; i < users.size(); i++)
                    {
                         if (caseInsensitiveStringCompare(users[i]->getUsername(), houses[i]->getUsername()))
                         {
                              cout << users[i]->getFullname() << ", phone: " << users[i]->getPhone_number();
                              break;
                         }
                    }
               }

               break;
          case 3:
               break;
          }

          // cout << "Register as member/View house details without seeing reviews or availibility" << endl;
          break;
     case 2:
          cout << "You use the app as Member." << endl;

          string username, password;
          bool flag = false;
          int count = 0;

          do
          {
               do
               {
                    cout << "Enter username: ";
                    cin.ignore();
                    getline(cin, username);
               } while (username == "");

               do
               {
                    cout << "Enter password: ";
                    getline(cin, password);
               } while (password == "");

               transform(username.begin(), username.end(), username.begin(), ::tolower);

               cout << "\n username = " << username << ", password = " << password << endl;

               for (int i = 0; i < users.size(); i++)
               {
                    if (caseInsensitiveStringCompare(users[i]->getUsername(), username) //
                        && caseSensitiveStringCompare(users[i]->getPassword(), password))
                    {
                         cout << "> Login successfully" << endl;
                         users[i]->setRole(2);
                         showUserHeaderIncludeHouse();
                         users[i]->showInfoIncludeHouse();
                         flag = true;
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
               cout << "Your account will be block" << endl;

          // Member menu
          int memberChoice;
          cout << "1. View all information" << endl;
          cout << "2. List available house to be occupied (with consuming points, and minimum required occupier rating)" << endl;
          cout << "3. Unlist house" << endl;
          cout << "Enter your choice: ";
          cin >> memberChoice;

          // switch (memberChoice)
          // {
          // case 1:
          //      user.showInfo();
          //      break;
          // case 2:
          //      break;
          // case 3:
          //      break;
          // }

          break;
     }

     return 0;
}