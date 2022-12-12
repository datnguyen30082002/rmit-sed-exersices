#pragma once
#include "Header.h"

class House
{
private:
    string location;
    string description;

public:
    House();

    House(string location, string description);
   
    void setLocation(string location);
   
    string getLocation();
    
    void setDescription(string description);
    
    string getDescription();

    void showInfo();
};