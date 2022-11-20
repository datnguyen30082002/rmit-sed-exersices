#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Juice
{
private:
    string name;
    int price;

public:
    Juice(string name = "", int price = 0)
    {
        this->name = name;
        this->price = price;
    }

    void setName(string name)
    {
        this->name = name;
    }

    void setPrice(int price)
    {
        this->price = price;
    }

    void info()
    {
        cout << "Juice's name: " << name << endl;
        cout << "Juice's price: " << price << endl;
    }

    Juice operator--(int)
    {
        Juice tmp = *this;
        tmp.price--;

        return tmp;
    }

    Juice operator+(Juice j1)
    {
        Juice tmp;

        if (this->name == j1.name)
        {
            tmp.name = this->name;
            tmp.price = this->price + j1.price;
        }
        else
        {
            tmp.name = "NA";
            tmp.price = 0;
        }

        return tmp;
    }

    friend Juice operator-(int n, Juice j);
};

Juice operator-(int n, Juice j)
{
    Juice temp;

    temp.name = j.name;
    temp.price = j.price - (((float)n / 100) * j.price);

    return temp;
}

int main()
{
    Juice j1("Coca", 100);
    Juice j2("Pepsi", 20);
    Juice j3("Pepsi", 100);
    Juice j4("Coca", 100);

    cout << "-----The objects info-----" << endl;
    j1.info();
    j2.info();
    j3.info();

    cout << endl << "-----The overloaded operator-------" << endl;

    Juice result = j1--;
    cout << "The object-- result: " << endl;
    result.info();

    Juice result1 = j2 + j3;
    cout << "The object + object result: " << endl;
    result1.info();
    Juice result3 = j3 + j4;
    cout << "The object + object result: " << endl;
    result3.info();

    Juice result2 = 50 - j1;
    cout << "The n - object result: " << endl;
    result2.info();

    Juice juiArr[4];
    fstream myFile;

    myFile.open("selling-juice.txt", std::ios::in);
    if (!myFile)
    {
        cout << "Fail to open/create file \n";
        return -1;
    }

    for (int i = 0; i < 4; i++)
    {
        string tempStr;
        // Read the name (up to the delimeter '\n')
        std::getline(myFile, tempStr, '\n');
        juiArr[i].setName(tempStr);

        // Read the scores
        std::getline(myFile, tempStr);

        // Declare a stringstream object with the content of tempStr
        stringstream ss;
        ss << tempStr;
        string word;
        int prices;

        // Extract stringstream content and store to prices
        while (ss >> word)
        {
            prices = stoi(word);
        }

        juiArr[i].setPrice(prices);
    }

    cout << endl << "All information read from file: " << endl;
    for (int i = 0; i < 4; i++)
    {
        juiArr[i].info();
    }

    // Close the file
    myFile.close();
}