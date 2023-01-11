#pragma once
#include "Header.h"
#include "RentDate.h"

class House
{
private:
    int id = 0;
    string location;
    string description;
    string username;
    string acceptOccupation;
    vector<string> requestOccupation;
    bool status;
    bool rentStatus = false;
    int consumingPoint = 0;
    int minOccupierRating = 0;
    float houseRatingScore = 0;
    RentDate rentDate;
    int reviewId = 0;

public:
    House();

    // Parameterized constructor
    House(int id, string location, string description, bool status, int consumingPoint, int minOccupierRating);

    House(int id, string location, string description, bool status, int consumingPoint, int minOccupierRating, bool rentStatus);


    // Get/Set methods
    void setId(int id);

    int getId();

    void setLocation(string location);

    string getLocation();

    void setDescription(string description);

    string getDescription();

    void setUsername(string username);

    string getUsername();

    void setAcceptOccupation(string acceptOccupation);

    string getAcceptOccupation();

    void addPersonToRequestList(string name);

    void setRequestOccupation(vector<string> requestOccupation);

    vector<string> getRequestOccupation();

    void setStatus(bool status);

    bool getStatus();

    void setRentStatus(bool rentStatus);

    bool getRentStatus();

    void setConsumingPoint(int consumingPoint);

    int getConsumingPoint();

    void setMinOccupierRating(int minOccupierRating);

    int getMinOccupierRating();

    void setHouseRatingScore(float houseRatingScore);

    float getHouseRatingScore();

    RentDate getRentDate();

    void setRentDate(RentDate rentDate);

    int getHouseReviewId();

    void setHouseReviewId(int reviewId);

    void showBasicInfo();

    void showAllInfo();

    void showAllRequestOccupation();

    // Declare a review friend class
    friend class Review;
};

// Show basic house header function
void showBasicHouseHeader();

// Show all header function
void showAllHouseHeader();

// Show basic house info function
void showBasicHouseInfo(vector<House *> houses);

// Show all house info function
void showAllHouseInfo(vector<House *> houses);

// Show available house info function
void showAvailableHouseInfo(vector<House *> houses);

// Check house location function
bool validateHouseInput(House house);