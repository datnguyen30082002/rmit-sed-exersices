#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Please enter a, b, c: ";
    cin >> a >> b >> c;

    int delta = b * b - 4 * a * c;
    int x1, x2;

    if (delta > 0)
    {
        x1 = - b + sqrt(delta) / 2 * a;
        x2 = - b - sqrt(delta) / 2 * a;
        cout << "The quadratic equation has 2 roots: " << "x1 = " << x1 << " x2 = " << x2 << endl;
    } else if (delta == 0)
    {
        x1 = -b / 2 * a;
        cout << "The quadratic equation only has 1 root: " << "x1 = x2 = " << x1 << endl;
    } else if (delta < 0)
        cout << "The quadratic equation has no roots" << endl;

    return 0;
}