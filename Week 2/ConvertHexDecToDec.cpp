#include <iostream>
#include <cstring>
using namespace std;

// Input hexadecimal function
void EnterString(char str[16])
{
    cout << "Enter a hexadecimal value: ";
    cin >> str;
}

// Check valid input function
bool CheckValidHexDec(char str[16])
{
    int i = 0;

    if(str[0] == '0' && (str[1] == 'x' || str[1] =='X'))
        i = 2;
    
    for (;i < strlen(str); i++)
    {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')))
            return false;
    }

    return true;
}

// Converting function
int ConvertHexDecToDec(char str[16])
{
    // Declare variables with its value
    int base = 1;
    int decimal = 0;

    // Scan the input string from right to left
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        if (str[i] >= '0' && str[i] <= '9') // Converting '0' to '9' back to decimal by subtracting 48 from the ASCII value
        {
            decimal += (int(str[i] - 48)) * base;
            base *= 16; // Incresing base value
        }
        else if (str[i] >= 'A' && str[i] <= 'F') // Converting 'A' to 'F' back to decimal by subtracting 55 from the ASCII value
        {
            decimal += (int(str[i] - 55)) * base;
            base *= 16; // Incresing base value
        }
    }

    return decimal;
}

int main()
{
    char str[16]; 
    int result;

    EnterString(str);

    int check = CheckValidHexDec(str);

    // Only convert if the input is valid
    if (check == 1)
    {
        result = ConvertHexDecToDec(str);
        cout << "The converted decimal value: " << result;
    }
    else 
    {
        cout << "Please enter the hexadecimal value again";
    }

    return 0;
}