#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string str;
    vector<string> arr;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> str;
        arr.push_back(str);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
}