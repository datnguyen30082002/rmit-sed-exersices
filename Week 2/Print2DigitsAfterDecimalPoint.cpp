#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int main()
{
    double a = 1.234;
    cout << setprecision(2) << fixed << a;
}