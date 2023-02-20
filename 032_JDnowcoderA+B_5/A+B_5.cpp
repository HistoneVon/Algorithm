#include <iostream>
using namespace std;

int main()
{
    int t, n, m;
    int sum;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        while (cin >> n)
        {
            sum = 0;
            for (int j = 0; j < n; ++j)
            {
                cin >> m;
                sum += m;
            }
            cout << sum << endl;
        }
    }
    return 0;
}