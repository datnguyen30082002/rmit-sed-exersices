#include <iostream>
#include <string>
using namespace std;

class Broker
{
public:
    string name;
    int buyPrice;
    Broker *nextBuyer = nullptr;

    Broker(string name = "", int buyPrice = 0) : name(name), buyPrice(buyPrice){};
};

// Traversal function
void traversal(Broker *head)
{
    // Show linked list
    Broker *tmp = head;

    cout << tmp->name << ": initially bought the house for $" << tmp->buyPrice << endl;
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
void printLowestProfit(Broker *head)
{
    Broker *tmp = head;

    // Find minimum profit
    int MinProfit;
    if (head->nextBuyer != nullptr)
    {
        MinProfit = head->nextBuyer->buyPrice - head->buyPrice;
    }

    // Find other brokers with the same min profit
    while (tmp != nullptr)
    {
        if (tmp->nextBuyer != nullptr)
        {
            int currentProfit = tmp->nextBuyer->buyPrice - tmp->buyPrice;

            if (currentProfit < MinProfit) // Change "<" to ">" to find max profit
            {
                MinProfit = currentProfit;
            }
        }

        tmp = tmp->nextBuyer;
    }

    cout << "----Brokers with lowest profit----" << endl;
    cout << "MinProfit = " << MinProfit << endl;

    // Print out all brokers with min profit
    tmp = head;
    while (tmp != nullptr)
    {
        if (tmp->nextBuyer != nullptr)
        {
            int currentProfit = tmp->nextBuyer->buyPrice - tmp->buyPrice;

            if (currentProfit == MinProfit)
            {
                cout << tmp->name << ", buy price = " << tmp->buyPrice << ", sell price = " << tmp->nextBuyer->buyPrice << ", profit = " << MinProfit << endl;
            }
        }

        tmp = tmp->nextBuyer;
    }
}

void printSecondLowestProfit(Broker *head)
{
    Broker *tmp = head;

    // Find lowest profit
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

    // Find second lowest profit
    int SecondMinProfit = 0;
    tmp = head;
    while (tmp != nullptr)
    {
        if (tmp->nextBuyer != nullptr)
        {
            int currentProfit = tmp->nextBuyer->buyPrice - tmp->buyPrice;

            if (currentProfit > MinProfit)
            {
                SecondMinProfit = currentProfit;
                break;
            }
        }

        tmp = tmp->nextBuyer;
    }

    tmp = head;
    while (tmp != nullptr)
    {
        if (tmp->nextBuyer != nullptr)
        {
            int currentProfit = tmp->nextBuyer->buyPrice - tmp->buyPrice;

            if (currentProfit < SecondMinProfit && currentProfit > MinProfit)
            {
                SecondMinProfit = currentProfit;
            }
        }

        tmp = tmp->nextBuyer;
    }

    cout << "-----Brokers with second lowest profit-----" << endl;
    cout << "SecondMinProfit = " << SecondMinProfit << endl;

    while (tmp != nullptr)
    {
        if (tmp->nextBuyer != nullptr)
        {
            int currentProfit = tmp->nextBuyer->buyPrice - tmp->buyPrice;
            
            if (currentProfit == SecondMinProfit)
            {
                cout << tmp->name << ", buy price = " << tmp->buyPrice << ", sell price = " << tmp->nextBuyer->buyPrice << ", profit = " << SecondMinProfit << endl;
            }
        }

        tmp = tmp->nextBuyer;
    }

}

int main()
{
    Broker person1("David", 800), person2("John", 1000), person3("Peter", 1200),
        person4("Luna", 1800), person5("Sophia", 3500);

    Broker *head = &person1;

    person1.nextBuyer = &person2;
    person2.nextBuyer = &person3;
    person3.nextBuyer = &person4;
    person4.nextBuyer = &person5;
    person5.nextBuyer = nullptr;

    // traversal(head);

    printLowestProfit(head);
    // printSecondLowestProfit(head);
}