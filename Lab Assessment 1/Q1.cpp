/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2022-3
  Lab Assessment: 1
  Author: Nguyen Thien Dat
  ID: s3877791
  Compiler used: g++ 8.1.0
  Created  date: 26/11/2022
  Acknowledgement: None
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

const int ITEM_SIZE = 100;

class Item
{
private:
  string name;
  int price;

public:
  Item(string name = "", int price = 0)
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

  string getName()
  {
    return name;
  }

  int getPrice()
  {
    return price;
  }

  void info()
  {
    cout << "Item's name: " << name << endl;
    cout << "Item's price: " << price << endl;
  }
};

void EnterSize(int &n)
{
  do
  {
    cout << "Please enter the number of items: ";
    cin >> n;
  } while (!(n > 0 && n < ITEM_SIZE));
}

void InputItem(Item items[ITEM_SIZE], int n)
{
  for (int i = 0; i < n; i++)
  {
    string name;
    int price;

    cout << "Enter item's " << i + 1 << " name: ";
    cin.ignore(1, '\n');
    getline(cin, name);

    cout << "Enter item's " << i + 1 << " price: ";
    cin >> price;

    items[i].setName(name);
    items[i].setPrice(price);
  }
}

void OutputItem(Item items[ITEM_SIZE], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << endl
         << "--------- Item " << i + 1 << "'s info ----------" << endl;
    items[i].info();
  }
}

void findSmallestPrice(Item items[ITEM_SIZE], int n)
{
  Item min = items[0];
  for (int i = 0; i < n; i++)
  {
    if (items[i].getPrice() < min.getPrice())
      min = items[i];
  }
  min.info();
}

int main(int argc, char *argv[])
{
  Item items[ITEM_SIZE];
  int n;
  std::fstream myfile; // declare an ofstream object
  string str1 = "-w";
  string str2 = "-r";
  string str3 = "-s";

  if (argc == 1)
    cout << "There is no argument from the command line";

  if (argc > 1)
  {
    if (argv[1] == str1)
    {
      EnterSize(n);
      InputItem(items, n);
      OutputItem(items, n);

      /* Create and write to file*/

      string filename = "sellingItems.dat"; // Declare file name
      myfile.open(filename, std::ios::out); // Open file

      if (!myfile)
      {
        std::cerr << "Fail to open file \n";
      }

      // Write data to file
      for (int i = 0; i < n; i++)
      {
        myfile << items[i].getName() << ":"
               << items[i].getPrice() << endl;
      }

      std::cout << endl
                << "Saved your answers to file !";

      myfile.close(); // close file
    }
    else if (argv[1] == str2)
    {
      char buff[256] = {};

      ifstream myfile("sellingItems.dat", ios::in | ios::binary);
      if (!myfile)
      {
        cout << "Cannot open file sellingItems.dat" << endl;
        return 0;
      }

      while (!myfile.eof())
      { // runs until end of file
        myfile.getline(buff, sizeof(buff));
        cout << buff << endl;
      }

      myfile.close();
    else if (argv[1] == str3)
    {
    }
    else
      cout << "There is an error related to input argument (not -w, -r, -s)";
  }
  return 0;
}