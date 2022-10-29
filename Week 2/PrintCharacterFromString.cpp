// C++ program to convert string
// to char array using c_str()
#include <cstring>
#include <iostream>
using namespace std;


 
// driver code
int main()
{
    char str[100];
    cout << "Enter a string: ";
    cin >> str;

    char character[100] = {};
    for (int i = 0; i < strlen(str); i++)
    {
        char str2[100] = {str[i], '\0'};
        strcat(character, str2);
    }


    cout << "The characters in string are: " ;
    for (int i = 0; i < strlen(character); i++)
    {
        cout << character[i] << " ";
    }
    
    return 0;
}