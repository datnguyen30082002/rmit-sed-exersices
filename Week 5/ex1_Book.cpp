#include <iostream>
#include <string>
using namespace std;

const int BOOK_SIZE = 100;

class Book
{
private:
    string name;
    int price;

public:
    Book(string nameVal = "", int priceVal = 0) : name(nameVal), price(priceVal) {}

    string GetName()
    {
        return name;
    }

    void SetName(string name)
    {
        this->name = name;
    }

    int GetPrice()
    {
        return price;
    }

    void SetPrice(int price)
    {
        this->price = price;
    }

    string toString() // Equivalent to showInfo() method
    {
        return "name = " + name + ", price = " + to_string(price);
    }
};

int main()
{
    // Create a Book object using dynamic memory allocation and initialize values for them through the constructor.
    Book *book1 = new (std::nothrow) Book("Harry Potter", 100);
    Book *book2 = new (std::nothrow) Book("Conan", 90);
    Book *book3 = new (std::nothrow) Book("Paper town", 150);

    // Check for NULL pointer to detect whether the allocation is succeeded or not.
    if (book1 == nullptr || book2 == nullptr || book3 == nullptr)
    {
        cout << "Fail to dynamically allocate memory" << endl;
    }

    // Print out all information using range-based for loop
    for (Book *book : {book1, book2, book3})
    {
        cout << book->toString() << endl;
        delete book; // Free up memory space
    }

    // Ask the user to enter a number n
    int n;

    do
    {
        cout << endl << "Enter the array's size: ";
        cin >> n;
    } while (!(n > 0));

    // Create an array of n Book objects using dynamic memory allocation and ask the user to input value for them
    Book *books = new (std::nothrow) Book[n];

    // Check for NULL pointer to detect whether the allocation is succeeded or not.
    if (books == nullptr)
    {
        cout << "Fail to dynamically allocate memory" << endl;
    }

    // Enter object attributes
    for (int i = 0; i < n; i++)
    {
        string name;
        cout << "Enter book" << i + 1 << "'s name: ";
        cin.ignore(1, '\n');
        getline(cin, name);

        int price;
        cout << "Enter book" << i + 1 << "'s price: ";
        cin >> price;

        books[i].SetName(name);
        books[i].SetPrice(price);
    }

    // Print out information of entered object
    cout << endl
         << "------Books' information------" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << books->toString() << endl;
    }

    // Print out the most expensive book
    Book *bestbook = &books[0];

    for (int i = 0; i < n; i++)
    {
        if (books[i].GetPrice() > bestbook->GetPrice())
            bestbook = &books[i];
    }

    cout << "The most expensive book is: " << bestbook->toString() << endl;

    // Free up memory space
    delete[] books;
}
