#include "Utils.h"


bool caseInsensitiveStringCompare(const string& str1, const string& str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }

    for (string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2)
    {
        if (tolower(static_cast<unsigned char>(*c1)) != tolower(static_cast<unsigned char>(*c2)))
        {
            return false;
        }
    }
    return true;
}

bool caseSensitiveStringCompare(const string& str1, const string& str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }

    for (string::const_iterator c1 = str1.begin(), c2 = str2.begin(); c1 != str1.end(); ++c1, ++c2)
    {
        if (static_cast<unsigned char>(*c1) != static_cast<unsigned char>(*c2))
        {
            return false;
        }
    }
    return true;
}