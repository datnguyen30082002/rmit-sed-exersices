#include "RentDate.h"
#include <ctime>

RentDate::RentDate() {};

RentDate::RentDate(bool isNow)
{
	if (isNow)
	{
		time_t now = time(0);
		tm* ltm = localtime(&now);
		this->day = ltm->tm_mday;
		this->month = 1 + ltm->tm_mon;
		this->year = 1900 + ltm->tm_year;
	}
	else
	{
		this->day = 0;
		this->month = 0;
		this->year = 0;
	}
};

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

string RentDate::toString()
{
	string strdate = "";
	if (this->day > 0 && this->month > 0 && this->year > 0)
	{
		strdate.append(to_string(this->day));
		strdate.append("/");
		strdate.append(to_string(this->month));
		strdate.append("/");
		strdate.append(to_string(this->year));
	}
	else
		strdate = "N/A";
	return strdate;
}