#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    vector<string> arr;
    while (cin >> str)
    {
        arr.push_back(str);
        if (cin.get() == '\n')
        {
            sort(arr.begin(), arr.end());
            for (int i = 0; i < arr.size(); ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            vector<string>().swap(arr);
        }
    }
    return 0;
}