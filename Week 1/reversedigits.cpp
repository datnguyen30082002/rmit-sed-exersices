#include <iostream>
using std::cin;
using std::cout;

int main()
{
    int number;
    cout << "Input number: ";
    cin >> number;

    cout << "Output number: ";
    while (number > 0)
    {
        int x = number % 10;
        cout << x;
        number /= 10;
    }

    return 0;
}