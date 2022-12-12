#include "House.h"

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
}