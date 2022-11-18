#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

class ComplNum
{
private:
    double real;
    double imag;

public:
    // Default constructor
    ComplNum() {}

    // Parameterized constructor
    ComplNum(double real, double imag)
    {
        this->real = real;
        this->imag = imag;
    }

    double getReal()
    {
        return real;
    }

    double getImag()
    {
        return imag;
    }

    // Object - object
    ComplNum operator-(ComplNum &complnum)
    {
        ComplNum result;

        result.real = this->real - complnum.real;
        result.imag = this->imag - complnum.imag;

        return result;
    }

    // Object - double
    ComplNum operator-(double num)
    {
        ComplNum tmp;
        tmp.real = this->real - num;
        tmp.imag = this->imag;

        return tmp;
    }
    //friend ComplNum operator-(ComplNum complnum, double num);

    // Double - Object
    friend ComplNum operator-(double num, ComplNum complnum);

    // Object--
    ComplNum operator--(int)
    {
        ComplNum temp = *this
        this->real--;

        return temp;
    }

    // --Obeject
    ComplNum operator--()
    {
        this->real--;

        return *this;
    }

    // Declare a non-member friend function to compute the absolute value
    friend double absolute(ComplNum complnum);

    void info()
    {
        cout << "The real part is: " << real << endl;
        cout << "The imagine part is: " << imag << "i" << endl;
    }

    // Set digit precision
    void printByPrecision(int numberOfPrecision)
    {
        cout.precision(numberOfPrecision);
        cout << "The real part is: " << fixed << real << endl;
        cout << "The imagine part is: " << fixed << imag << endl;
    }
};

// ComplNum operator-(ComplNum complnum, double num)
// {
//     ComplNum temp = complnum;
//     temp.real = temp.real - num;
//     temp.imag = this->imag;
//     return temp;
// }

ComplNum operator-(double num, ComplNum complnum)
{
    ComplNum temp = complnum;
    temp.real = num - temp.real;
    temp.imag = -temp.imag;
    return temp;
}


double absolute(ComplNum complnum)
{
    double abs = sqrt(pow(complnum.real, (double)2.0) + pow(complnum.imag, (double)2.0));

    return abs;
}

int main()
{
    ComplNum complnum1(2.44444, 1.323444);
    ComplNum complnum2(1.22222, 1.323444);

    ComplNum result0 = complnum1 - complnum2;
    ComplNum result1 = complnum1--;
    ComplNum result2 = --complnum2;
    ComplNum result3 = 2.5555 - complnum1;
    ComplNum result4 = complnum2 - 0.22222;

    cout << "Result of two complex numbers subtraction:" << endl;
    result0.info();

    cout << "Result of decreasing by 1 (object--):" << endl;
    result1.info();

    cout << "Result of decreasing by 1 (--object):" << endl;
    result2.info();

    cout << "Result of subtration between complnum1 and a double value:" << endl;
    result3.info();

    cout << "Result of subtration between complnum2 and a double value:" << endl;
    result4.printByPrecision(4);

    double abs = absolute(complnum1);
    cout << "The absolute value of this complex number is: " << abs << endl;
}