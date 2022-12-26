#include "House.h"
#include "Utils.h"

House::House(){};

House::House(int id, string location, string description, bool status)
{
    this->id = id;
    this->location = location;
    this->description = description;
    this->status = status;
}

void House::setId(int id)
{
    this->id = id;
}

int House::getId()
{
    return id;
}

void House::setLocation(string location)
{
    this->location = location;
}

string House::getLocation()
{
    return location;
}

void House::setDescription(string description)
{
    this->description = description;
}

string House::getDescription()
{
    return description;
}

void House::setUsername(string username)
{
    this->username = username;
}

string House::getUsername()
{
    return username;
}

void House::setStatus(bool status)
{
    this->status = status;
}

bool House::getStatus()
{
    return status;
}

void House::showInfo()
{
    // cout << endl;
    cout.width(HOUSE_ID);
    cout << left << id;
    cout.width(HOUSE_LOCATION);
    cout << left << location;
    cout.width(HOUSE_DESCRIPTION);
    cout << left << description;
    // cout << endl;
}

void showHouseInfoHeader()
{   
    cout << endl;
    cout << "-------------------- House's info --------------------" << endl;
    cout.width(HOUSE_ID);
    cout << left << "ID";
    cout.width(HOUSE_LOCATION);
    cout << left << "Location";
    cout.width(HOUSE_DESCRIPTION);
    cout << left << "Description";
    //cout << endl;
}

// Show house info function
void showHouseInfo(vector<House *> houses)
{
    showHouseInfoHeader();
    for (int i = 0; i < houses.size(); i++)
    {
        houses[i]->showInfo();
    }
}

void showAvailableHouseInfo(vector<House *> houses)
{
    showHouseInfoHeader();
    for (int i = 0; i < houses.size(); i++)
    {
        if (houses[i]->getStatus())
            houses[i]->showInfo();
    }
}

// Check house location function
bool validateHouseInput(House house)
{
    for (int i = 0; i < defaultLocations.size(); i++)
    {
        // if (caseInsensitiveStringCompare(defaultLocations[i], house.getLocation()))
        {
            return true;
        }
    }
    return false;
}