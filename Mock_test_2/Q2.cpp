#include <iostream>
#include <string>
using namespace std;

class Broker
{
public:
    string name;
    string buyPrice;
    Broker *nextBuyer = nullptr;

    Broker(string name = "", string buyPrice = "") : name(name), buyPrice(buyPrice){};
};

// Traversal function
void traversal(Broker *head)
{
    // Show linked list
    Broker *tmp = head;

    cout << "David: initially bought the house for $800" << endl;
    while (tmp != nullptr)
    {
        cout << tmp->name;
        tmp = tmp->nextBuyer;

        if (tmp != nullptr)
            cout << " ---> ";
    }
}

// Find lowest profit function


int main()
{
    Broker person1("David", "$800"), person2("John", "$1000"), person3("Peter", "$1200"),
        person4("Luna", "$1800"), person5("Sophia", "$3500");

    Broker *head = &person1;

    person1.nextBuyer = &person2;
    person2.nextBuyer = &person3;
    person3.nextBuyer = &person4;
    person4.nextBuyer = &person5;
    person5.nextBuyer = nullptr;

    traversal(head);
}