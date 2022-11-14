#include <iostream>
#include <string>
using namespace std;

void ReverseString(string &str)
{
    cout << "The reverse string is: ";
    for (int i = str.length() - 1; i >= 0; i--)
    {
        cout << str[i];
    }
}

void ConvertCharacter(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (islower(str[i]))
            str[i] = toupper(str[i]);
        else if (isupper(str[i]))
            str[i] = tolower(str[i]);
    }

    cout << endl << "The converted string is: " << str;
}

int main()
{
    string str1, str2;
    cout << "Enter a string 1: ";
    getline(cin, str1);
    cout << "Enter a string 2: ";
    getline(cin, str2);

    ReverseString(str1);
    ConvertCharacter(str2);
}