#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;

int main()
{
    /*
    
    
    
    */

    // Declare and input string
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, sizeof(str));

    // Declare a pointer to find the white space in the string
    char *p = strstr(str, "  ");

    // Keep only one white space between each word
    while (p != NULL)
    {
        strcpy (p, p + 1);
        p = strstr(str, "  ");
    }

    cout << "The new string is: " << str;
}