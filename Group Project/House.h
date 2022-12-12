#include <iostream>
#include <string>
using namespace std;

class House
{
private:
    string location;
    string description;

public:
    House(string location, string description);
   
    void setLocation(string location);
   
    string getLocation();
    
    void setDescription(string description);
    
    string getDescription();

    void showInfo();
};