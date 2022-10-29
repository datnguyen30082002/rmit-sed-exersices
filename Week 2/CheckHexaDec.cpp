#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using namespace std;

void EnterString(char str[16])
{
    cout << "Enter a hexadecimal value: ";
    cin >> str;
}

bool CheckHexDecValue(char str[16])
{
    int i = 0;

    if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
        i = 2;

    for (; i < strlen(str); i++)
    {
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F')))
            return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    char str[16];
    
    if (argc == 1)
        EnterString(str);
    else if (argc > 1)
        strcpy (str, argv[1]);

    int check = CheckHexDecValue(str);
    if (check == 1)
        cout << "Got valid hexadecimal value: " << str;
    else
        cout << "Got invalid hexadecimal value: " << str;

    return 0;
}