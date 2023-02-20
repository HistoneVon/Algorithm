#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    string in;
    while (getline(cin, in))
    {
        stringstream ss(in);
        string t;
        vector<string> arr;
        while (getline(ss, t, ','))
        {
            arr.push_back(t);
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); ++i)
        {
            cout << arr[i];
            if (i != arr.size() - 1)
            {
                cout << ",";
            }
        }
        cout << endl;
    }
    return 0;
}