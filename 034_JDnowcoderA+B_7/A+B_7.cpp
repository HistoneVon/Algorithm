#include <iostream>
using namespace std;

int main()
{
    int m;
    int sum = 0;
    while (cin >> m)
    {
        sum += m;
        if (cin.get() == '\n')
        {
            cout << sum << endl;
            sum = 0;
        }
    }

    return 0;
}