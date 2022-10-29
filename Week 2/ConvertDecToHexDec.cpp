#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using namespace std;

char HexDec[16] = { '0', '1', '2', '3', '4', '5', '6', '7','8', '9', 'A', 'B', 'C', 'D' , 'E', 'F' };

void EnterNumber(int &num)
{
    do
    {
        cout << "Enter a number: ";
        cin >> num;
    } while (!(num >= 0));
}

void ConvertDecToHexDec(int num)
{
	char str[16] = ""; // Declare empty string

	/*
		Idea: 
		Step 1: Take the remaining value of the input number when dividing by 16 then store to variable x
		Step 2: Declare a new string with the value of Hexdec[i]
		Step 3: Concatenate that string character to the empty string
		Step 4: Update the number by dividing that number by 16
		Step 5: Print out the reverse converted hexadecimal string

		Example: input a number = 100
		x = 100 % 16 = 4 => Hexdec[4] = '4' => str[16] = 0x4; num = 100 / 16 = 6;
		repeat the process until num = 0, x = 6 % 16 = 6 => Hexdec[6] = '6' => str[16] = 0x46; num 6 / 16 = 0;
		print the reverse converted hexadecimal string => str[16] = 0x64
	*/

	while (num > 0)
	{
		int x = num % 16; // Get the remaining 

		char str2[2] = { HexDec[x] , '\0' }; // Declare a new string with the value of HexDec[x]
		strcat(str, str2); // Concatenate str2 to str

		num /= 16; // Update the number 
	}

    cout << "The converted hexadecimal value: 0x";
	for (int i = strlen(str) - 1; i >= 0; i--) // Print the reverse string
	{
		cout << str[i];
	}
}

int main()
{
    int num;
    
	// Call functions
    EnterNumber(num);
    ConvertDecToHexDec(num);

    return 0;
}