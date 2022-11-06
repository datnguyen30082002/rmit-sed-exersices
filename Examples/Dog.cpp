#include <iostream>

class Dog // The class
{ 
    public: // Access specifier
    int age; // Attributes (variables)
    bool hungry = true;
    bool happy;

    void eat() {// Method (function)
        hungry = false; happy = true;
    }

    void info() {// Method (function)
        std::cout << "age = " << age
        << " hungry = " << hungry
        << " happy = " << happy << "\n";
    }
};

int main() 
{
    Dog Dog1, Dog2; //Create objects of Dog

    //Access their variables and functions
    Dog1.age = 5;
    Dog1.eat(); 
    std::cout << "Dog 1's info: "; 
    Dog1.info();

    Dog2.age = 10;
    std::cout << "Dog 2's info: "; 
    Dog2.info();
    
    return 0;
}
