// stack
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        string s;
        string t;
        cin >> s;
        cin >> t;
        vector<char> vec;
        bool res = true;
        // 使s长于t
        if (s.size() < t.size()) {
            swap(s, t);
        }
        // stack
        
        if (res) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        vector<char>().swap(vec);
    }
    return 0;
}