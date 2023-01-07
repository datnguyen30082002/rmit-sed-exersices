#include "House.h"
#include "Utils.h"
#include "RentDate.h"

House::House() {};

House::House(int id, string location, string description, bool status)
{
	this->id = id;
	this->location = location;
	this->description = description;
	this->status = status;
}

House::House(int id, string location, string description, bool status, int consumingPoint, int minOccupierRating)
{
	this->id = id;
	this->location = location;
	this->description = description;
	this->status = status;
	this->consumingPoint = consumingPoint;
	this->minOccupierRating = minOccupierRating;
}

House::House(int id, string location, string description, bool status, int consumingPoint, int minOccupierRating, bool rentStatus)
{
	this->id = id;
	this->location = location;
	this->description = description;
	this->status = status;
	this->consumingPoint = consumingPoint;
	this->minOccupierRating = minOccupierRating;
	this->rentStatus = rentStatus;
}

House::House(int id, string location, string description, bool status, int consumingPoint, int minOccupierRating, bool rentStatus, RentDate rentDate)
{
	this->id = id;
	this->location = location;
	this->description = description;
	this->status = status;
	this->consumingPoint = consumingPoint;
	this->minOccupierRating = minOccupierRating;
	this->rentStatus = rentStatus;
	this->rentDate = rentDate;
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

void House::setAcceptOccupation(string acceptOccupation)
{
	this->acceptOccupation = acceptOccupation;
}

string House::getAcceptOccupation()
{
	return acceptOccupation;
}

void House::addPersonToRequestList(string name)
{
	this->requestOccupation.push_back(name);
	cout << endl
		<< "name = " << name << ", house id = " << this->id << ", requestOccupation's size changed = " << this->requestOccupation.size();
	cout << endl;
}

void House::setRequestOccupation(vector<string> requestOccupation)
{
	this->requestOccupation = requestOccupation;
}

vector<string> House::getRequestOccupation()
{
	return requestOccupation;
}

void House::setStatus(bool status)
{
	this->status = status;
}

bool House::getStatus()
{
	return status;
}

void House::setRentStatus(bool rentStatus)
{
	this->rentStatus = rentStatus;
}

bool House::getRentStatus()
{
	return this->rentStatus;
}

void House::setConsumingPoint(int consumingPoint)
{
	this->consumingPoint = consumingPoint;
}

int House::getConsumingPoint()
{
	return consumingPoint;
}

void House::setMinOccupierRating(int minOccupierRating)
{
	this->minOccupierRating = minOccupierRating;
}

int House::getMinOccupierRating()
{
	return minOccupierRating;
}

void House::setRentDate(RentDate rentDate)
{
	this->rentDate = rentDate;
}

int House::getHouseReviewId()
{
	return this->reviewId;
}

void  House::setHouseReviewId(int reviewId)
{
	this->reviewId = reviewId;
}

void House::showBasicInfo()
{
	cout.width(HOUSE_ID);
	cout << left << id;
	cout.width(HOUSE_LOCATION);
	cout << left << location;
	cout.width(HOUSE_DESCRIPTION);
	cout << left << description;
}

void House::showAllInfo()
{
	showBasicInfo();
	cout.width(HOUSE_CONSUMING_POINT);
	cout << left << consumingPoint;
	cout.width(HOUSE_OCCUPIER_RATING);
	cout << left << minOccupierRating;
	cout.width(HOUSE_RENT_STATUS);
	if (rentStatus == true)
		cout << left << "Not available";
	else
		cout << left << "Available";
	cout.width(HOUSE_RENT_DATE);
	if (rentDate.getDay() <= 0 && rentDate.getMonth() <= 0 && rentDate.getYear() <= 0)
		cout << "N/A" << endl;
	else
		this->rentDate.showDateInfo();
}

void House::showAllRequestOccupation()
{
	cout << endl;
	cout << "------ Name of request Occupation --------------------" << endl;
	for (int i = 0; i < this->requestOccupation.size(); i++)
	{
		cout << "-- " << i + 1 << ", name: " << requestOccupation[i] << endl;
	}
}

void showBasicHouseHeader()
{
	cout << endl;
	cout << "-------------------- House's info --------------------" << endl;
	cout.width(HOUSE_ID);
	cout << left << "ID";
	cout.width(HOUSE_LOCATION);
	cout << left << "Location";
	cout.width(HOUSE_DESCRIPTION);
	cout << left << "Description";
}

void showAllHouseHeader()
{
	cout << endl;
	cout << "-------------------- House's info --------------------" << endl;
	cout.width(HOUSE_ID);
	cout << left << "ID";
	cout.width(HOUSE_LOCATION);
	cout << left << "Location";
	cout.width(HOUSE_DESCRIPTION);
	cout << left << "Description";
	cout.width(HOUSE_CONSUMING_POINT);
	cout << left << "Consuming Point";
	cout.width(HOUSE_OCCUPIER_RATING);
	cout << left << "Occupier Rating";
	cout.width(HOUSE_RENT_STATUS);
	cout << left << "Renting Status";
	cout.width(HOUSE_RENT_DATE);
	cout << left << "Renting Date";
}

// Show house info function
void showBasicHouseInfo(vector<House*> houses)
{
	showBasicHouseHeader();
	for (int i = 0; i < houses.size(); i++)
	{
		cout << endl;
		houses[i]->showBasicInfo();
	}
}

void showAllHouseInfo(vector<House*> houses)
{
	showAllHouseHeader();
	for (int i = 0; i < houses.size(); i++)
	{
		cout << endl;
		houses[i]->showAllInfo();
	}
}

void showAvailableHouseInfo(vector<House*> houses)
{
	showBasicHouseHeader();
	for (int i = 0; i < houses.size(); i++)
	{
		if (houses[i]->getStatus())
			houses[i]->showBasicInfo();
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