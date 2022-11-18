#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;

bool CheckHexDecValue(string str)
{
    // Allow the hexdec to be preceded by '0x' or '0X'
    if (!(str[0] == '0' && (str[1] == 'x' || str[1] == 'X')))
        return false;

    // Check whether the hexdec is valid or not
    for (int i = 2; i < str.length(); i++)
    {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')))
            return false;
    }

    return true;
}

int doubleVal(int integer)
{
    int double_val = integer * 2;

    return double_val;
}

float doubleVal(float floatnum)
{
    float double_val = floatnum * 2;

    return double_val;
}

string doubleVal(string str)
{
    int dec = 0;
    int base = 1;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] >= 0 && str[i] <= 9)
        {
            dec += (int(str[i] - 48)) * base;
            base *= 16;
        }
        else if (str[i] >= 'A' && str[i] <= 'F')
        {
            dec += (int(str[i] - 55)) * base;
            base *= 16;
        }
    }

    return to_string(dec);
}

int main(int argc, char *argv[])
{
    int integer;
    float number;
    string str[10];

    if (argc <= 1)
        cout << "There is no argument from the command line" << endl;
    else if (argc > 1)
    {
        int k = 0;
        for (int i = 1; i < argc; ++i)
        {
            str[k++] = argv[i];
        }

        for (int i = 0; i < k; i++)
        {
            string token = str[i];

            if (CheckHexDecValue(token))
            {
                // Print hexa
                cout << "0x" << doubleVal(token) << endl;
            }
            else
            {
                // Integer or Float
                if (token.find('.') < token.length())
                {
                    number = stof(token);
                    cout << setprecision(2) << fixed << doubleVal(number) << endl;
                }
                else
                {
                    integer = stoi(token);
                    cout << doubleVal(integer) << endl;
                }
            }
        }
    }

    // Extract data from stringstream by using string stream
    // string token;
    // while (std::getline(ss, token, ' '))
    // {
    //     if (CheckHexDecValue(token))
    //     {
    //         // print for hexa
    //         cout << "0x" << doubleVal(token) << endl;
    //     }
    //     else
    //     {
    //         // integer or float
    //         if (token.find('.') < token.length())
    //         {
    //             number = stof(token);
    //             cout << setprecision(2) << fixed << doubleVal(number) << endl;
    //         }
    //         else
    //         {
    //             integer = stoi(token);
    //             cout << doubleVal(integer) << endl;
    //         }
    //     }
    // }
}