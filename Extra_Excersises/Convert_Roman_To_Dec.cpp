#include <iostream>
#include <cstring>
using namespace std;

char symbol[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
int value[] = { 1, 5, 10, 50, 100, 500, 1000 };

bool isValidRomanNumber(char roman[255])
{
	for (int i = 0; i < strlen(roman); i++)
	{
		if (!(roman[i] == 'I' || roman[i] == 'V' || roman[i] == 'X' || roman[i] == 'L' || roman[i] == 'C' || roman[i] == 'D' || roman[i] == 'M'))
			return false;
	}
	return true;
}

void InputRomanNumber(char roman[255])
{
	do
	{
		cout << "Enter the Roman number: ";
		cin >> roman;
	} while (!isValidRomanNumber(roman));
}

int findPositionOfRomanCharacter(char symbol[], char character) // To find the position of input Roman character in the symbol array
{
	for (int i = 0; i < strlen(symbol); i++)
	{
		if (symbol[i] == character)
			return i;
	}
	return -1;
}

int ConvertRomanToDec(char symbol[], int value[], int n, char roman[255]) // n is the length of symbol and value arrayf
{
	int dec = 0;

	for (int i = 0; i < strlen(roman); i++)
	{
		int pos = findPositionOfRomanCharacter(symbol, roman[i]);
		if (pos != -1)
		{
			dec += value[pos];
		}
	}
	
	return dec;
}

int main()
{
	char roman[20];
	InputRomanNumber(roman);

	int result = ConvertRomanToDec(symbol, value, 7, roman);
	cout << "The converted number is: " << result;
}