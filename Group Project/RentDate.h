#pragma once
#include "Header.h"

class RentDate
{
private:
    int day;
    int month;
    int year;

public:
    RentDate();

    // Parameterized constructor
    RentDate(bool isNow);

    RentDate(int day, int month, int year);

    // Get/Set methods
    int getDay();

    void setDay(int day);

    int getMonth();

    void setMonth(int month);

    int getYear();

    void setYear(int year);

    void showDateInfo();

    // Declare a House friend class
    friend class House;

    // Convert number to string function
    string toString();
};