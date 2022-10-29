#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a = 10, b = 200;

    cout << "left justified output (both a & b)\n";
    cout << left  << setw(5) 
    << a << " | " << b << '\n';    

    return 0;
}