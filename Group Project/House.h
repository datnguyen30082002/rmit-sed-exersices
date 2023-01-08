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

    House(int id, string location, string description, bool status);

    House(int id, string location, string description, bool status, int consumingPoint, int minOccupierRating);

    House(int id, string location, string description, bool status, int consumingPoint, int minOccupierRating, bool rentStatus);

    House(int id, string location, string description, bool status, int consumingPoint, int minOccupierRating, bool rentStatus, RentDate rentDate);

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

    friend class Review;
};

void showBasicHouseHeader();

void showAllHouseHeader();

void showBasicHouseInfo(vector<House *> houses);

void showAllHouseInfo(vector<House *> houses);

void showAvailableHouseInfo(vector<House *> houses);

// Check house location function
bool validateHouseInput(House house);