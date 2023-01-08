#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

const int USER_USERNAME_WIDTH = 12;
const int USER_FULLNAME_WIDTH = 12;
const int USER_PHONE_NUMBER_WIDTH = 15;
const int USER_CREDIT_POINT_WIDTH = 15;
const int USER_ROLE_WIDTH = 10;
const int USER_RATING_SCORE_WIDTH = 15;

const int HOUSE_ID = 5;
const int HOUSE_LOCATION = 10;
const int HOUSE_DESCRIPTION = 18;
const int HOUSE_CONSUMING_POINT = 17;
const int HOUSE_OCCUPIER_RATING = 22;
const int HOUSE_RATING_SCORE = 15;
const int HOUSE_RENT_STATUS = 15;
const int HOUSE_RENT_DATE = 15;

const int REVIEW_ID = 12;
const int REVIEW_HOUSE_ID = 17;
const int REVIEWER = 10;
const int REVIEW_SCORE = 15;
const int REVIEW_COMMENT = 18;
const int REVIEW_DATE = 20;

// Define default locations
const vector<string> defaultLocations = { "Ha Noi", "Hue", "HCM" };
