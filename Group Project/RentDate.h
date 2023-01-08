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

    RentDate(bool isNow);

    RentDate(int day, int month, int year);

    int getDay();

    void setDay(int day);

    int getMonth();

    void setMonth(int month);

    int getYear();

    void setYear(int year);

    void showDateInfo();

    friend class House;

    string toString();
};