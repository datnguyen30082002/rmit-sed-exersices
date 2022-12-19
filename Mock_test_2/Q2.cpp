#include <iostream>
#include <string>
using namespace std;

class Broker
{
public:
    string name;
    int buyPrice;
    Broker* nextBuyer = nullptr;

    Broker(string name = "", int buyPrice = 0) : name(name), buyPrice(buyPrice) {};
};

// Traversal function
void traversal(Broker* head)
{
    // Show linked list
    Broker* tmp = head;

    cout << tmp->name << ": initially bought the house for " << tmp->buyPrice << endl;
    while (tmp != nullptr)
    {
        if (tmp->nextBuyer != nullptr)
        {
            cout << tmp->name << " --> " << tmp->nextBuyer->name << " : price = $" << tmp->nextBuyer->buyPrice << endl;
        }

        tmp = tmp->nextBuyer;
    }
}

// Find lowest profit function
void printLowestProfit(Broker* head)
{
    Broker* tmp = head;

    int MinProfit;
    if (head->nextBuyer != nullptr)
    {
        MinProfit = head->nextBuyer->buyPrice - head->buyPrice;
    }

    while (tmp != nullptr)
    {
        if (tmp->nextBuyer != nullptr)
        {
            int currentProfit = tmp->nextBuyer->buyPrice - tmp->buyPrice;
            if (currentProfit < MinProfit)
            {
                MinProfit = currentProfit;
            }
        }

        tmp = tmp->nextBuyer;
    }

    cout << ", MinProfit = " << MinProfit << endl;
    
    tmp = head;
    while (tmp != nullptr)
    {
        if (tmp->nextBuyer != nullptr)
        {
            int currentProfit = tmp->nextBuyer->buyPrice - tmp->buyPrice;
            if (currentProfit == MinProfit)
            {
                cout << tmp->name << " Buy price: " << tmp->buyPrice << ", sell price: " << tmp->nextBuyer->buyPrice << " Profit: " << MinProfit << endl;
            }
        }

        tmp = tmp->nextBuyer;
    }
}

int main()
{
    Broker person1("David", 800), person2("John", 1000), person3("Peter", 1200),
        person4("Luna", 1800), person5("Sophia", 3500);

    Broker* head = &person1;

    person1.nextBuyer = &person2;
    person2.nextBuyer = &person3;
    person3.nextBuyer = &person4;
    person4.nextBuyer = &person5;
    person5.nextBuyer = nullptr;

    //traversal(head);

    printLowestProfit(head);
}