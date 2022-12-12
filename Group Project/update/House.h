#pragma once
#include "Header.h"
#include "User.h"

class House
{
private:
    string location;
    string description;
    User user;
    bool status;

public:
    House();

    House(string location, string description, bool show);
   
    void setLocation(string location);
   
    string getLocation();
    
    void setDescription(string description);
    
    string getDescription();

    void setUser(User user);

    void setStatus(bool status);

    bool getStatus();

    void showInfo();
};

void showHouseInfoHeader();

void showHouseInfo(vector<House*> houses);

// Check house location function
bool validateHouseInput(House house);