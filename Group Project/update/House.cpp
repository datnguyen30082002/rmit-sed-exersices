#include "House.h"
#include "Utils.h"

House::House() {};

House::House(string location, string description)
{
	this->location = location;
	this->description = description;
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

void House::showInfo()
{
	cout.width(HOUSE_LOCATION);
	cout << left << location;
	cout.width(HOUSE_DESCRIPTION);
	cout << left << description;
    cout << endl;
}


void showHouseInfoHeader()
{
    cout << "-------------------- House's info --------------------" << endl;
    cout.width(HOUSE_LOCATION);
    cout << left << "Location";
    cout.width(HOUSE_DESCRIPTION);
    cout << left << "Description";
    cout << endl;
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