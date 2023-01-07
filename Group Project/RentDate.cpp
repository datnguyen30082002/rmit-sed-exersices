#include "RentDate.h"

RentDate::RentDate(){};

RentDate::RentDate(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

int RentDate::getDay()
{
    return this->day;
}

void RentDate::setDay(int day)
{
    this->day = day;
}

int RentDate::getMonth()
{
    return this->month;
}

void RentDate::setMonth(int month)
{
    this->month = month;
}

int RentDate::getYear()
{
    return this->year;
}

void RentDate::setYear(int year)
{
    this->year = year;
}

void RentDate::showDateInfo()
{
    cout.width(0);
    cout << left << day;
    cout << left << "/";
    cout << left << month;
    cout << "/";
    cout << left << year;
    cout << endl;
}