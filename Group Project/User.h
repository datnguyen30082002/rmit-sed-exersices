#include <iostream>
#include <string>
#include "House.h"
using namespace std;


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
    // Parameterized constructor
    User(string username, string fullname, string phone_number, int credit_point)
    
    User(string username, string password, string fullname, string phone_number, House house)
    

    // Get/Set method
    string getUsername();
    

    void setUsername(string username);
   
    string getPassword();
    

    void setPassword(string password);
    

    string getFullname();
    
    void setFullname(string fullname);
    

    string getPhone_number()
    {
        return phone_number;
    }

    void setPhone_number(string phone_number);
    
    int getCredit_point();
    
    void setCredit_point(int credit_point);
    
    void setHouse(House house);
    
    bool registerMember(User user);
   
    void showInfo();
};