#pragma once
#include "Header.h"

bool caseInsensitiveStringCompare(const string &str1, const string &str2);
bool caseSensitiveStringCompare(const string &str1, const string &str2);

bool isLeap(int year);

// Returns true if given
// year is valid or not.
bool isValidDate(int d, int m, int y);
