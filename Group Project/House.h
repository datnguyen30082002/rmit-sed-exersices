#pragma once
#include "Header.h"

class House
{
private:
    int id;
    string location;
    string description;
    string username;
    bool status;
    int consumingPoint;
    int minOccupierRating;
public:
    House();

    House(int id, string location, string description, bool show);

    void setId(int id);

    int getId();

    void setLocation(string location);
   
    string getLocation();
    
    void setDescription(string description);
    
    string getDescription();

    void setUsername(string username);

    string getUsername();

    void setStatus(bool status);

    bool getStatus();

    void showInfo();
};

void showHouseInfoHeader();

void showHouseInfo(vector<House*> houses);

void showAvailableHouseInfo(vector<House *> houses);

// Check house location function
bool validateHouseInput(House house);