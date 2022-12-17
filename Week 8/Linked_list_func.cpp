#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Household
{
public:
    string name;
    Household *next = nullptr; // Declare next pointer

    Household(string name = "") : name(name) {}
};

// Traversal function
void traversal(Household *oriHousehold)
{
    // Show linked list
    Household *tmp = oriHousehold;

    while (tmp != nullptr)
    {
        cout << tmp->name;
        tmp = tmp->next;

        if (tmp != nullptr)
            cout << " ---> ";
    }
}

// Search by name function
Household findByName(Household *oriHousehold, string name)
{
    if (oriHousehold == nullptr)
    {
        cout << "\n List is empty";
        return Household("");
    }

    Household *tmp = oriHousehold;

    while (tmp != nullptr)
    {
        if (tmp->name.compare(name) == 0)
            return *tmp;

        tmp = tmp->next;
    }

    return Household("");
}

// Search by index function
Household findByIndex(Household *oriHousehold, int index)
{
    if (oriHousehold == nullptr)
    {
        cout << "\n List is empty";
        return Household("");
    }

    Household *tmp = oriHousehold;
    int position = 0;

    while (tmp != nullptr)
    {
        if (position == index)
            return *tmp;

        tmp = tmp->next;
        position++;
    }

    return Household("");
}

/*Add node function*/
// Add element at begin
void addElementAtBegin(Household *oriHousehold, Household node1)
{
    node1.next = oriHousehold;
    oriHousehold = &node1;

    // Show linked list
    Household *tmp = oriHousehold;

    while (tmp != nullptr)
    {
        cout << tmp->name;
        tmp = tmp->next;

        if (tmp != nullptr)
            cout << " ---> ";
    }
}

int main()
{
    // Initialize nodes
    Household household1("House hold 1"), household2("House hold 2"), household3("House hold 3");

    // Set house hold 1 as the original household
    Household *oriHousehold = &household1;

    // Connect nodes
    household1.next = &household2;
    household2.next = &household3;
    household3.next = nullptr;

    // traversal(oriHousehold);

    // Household find = findByName(oriHousehold, "House hold 1");
    // if (find.name.compare("") == 0)
    //     cout << "\n Not found";
    // else
    //     cout << "\n Found";

    // Household find2 = findByIndex(oriHousehold, 666);
    // if (find2.name.compare("") == 0)
    //     cout << "\n Not found";
    // else
    //     cout << "\n Found, name = " << find2.name;

    Household household0("New element");

    addElementAtBegin(oriHousehold, household0);
}