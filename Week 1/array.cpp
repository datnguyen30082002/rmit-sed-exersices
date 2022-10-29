#include <iostream>
using std::cin;
using std::cout;
using namespace std;
const int SIZE = 255;

void EnterSize(int &size)
{
    do
    {
        cout << "Please enter the size of the array: ";
        cin >> size;
    } while (!(size > 0));
}

void InputArray(int arr[SIZE], int size)
{
    cout << "Enter the array elements: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

void MaxElement(int arr[SIZE], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
        if (arr[i] > max)
            max = arr[i];
    }
    cout << "The maximum value of the array elements is: " << max << endl;
}

int main()
{
    int num, arr[SIZE];
    
    EnterSize(num);
    InputArray(arr, num);
    MaxElement(arr, num);

    return 0;
}