#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int sum;
    while (cin >> n)
    {
        sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> m;
            sum += m;
        }
        cout << sum << endl;
    }

    return 0;
}