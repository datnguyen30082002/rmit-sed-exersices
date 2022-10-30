#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
        cout << "There is only program name: " << argv[0];
    else if (argc > 1)
    {
        cout << "The command line arguments are: " << endl;
        for (int i = 0; i < argc; i++)
        {
            cout << sizeof(argv[i]) << endl;
        }
    }
}