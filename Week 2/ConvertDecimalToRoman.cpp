#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	int num;

	char symbol[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
	int value[] = { 1, 5, 10, 50, 100, 500, 1000 };

	if (argc == 1)
    {
        do
	    {
		    cout << "Enter an integer: ";
		    cin >> num;
	    } while (!(num > 0));
    } else if (argc > 1)
        num = atoi(argv[1]);

	cout << "The converted Roman number is: ";

	while (num > 0)
	{
		int i = 0; // Initialize variable i equal to 0

		while (num >= value[i] && i <= 6) // Scan if num has a greater value than value[i]
		{
			i++; // Increasing i to get the element position stored in the array
		}
		
        cout << symbol[i - 1]; // Print out the symbol that has a value equivalent to num
		num -= value[i - 1]; // Update num 
	}
}