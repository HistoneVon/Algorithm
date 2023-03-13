// 100
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> parseStringToInt(string& s) {
    vector<int> res;
    for (int i = 0; i < s.size(); ++i) {
        res.push_back(s[i] - '0');
    }
    return res;
}

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int getNum(int a, int b) {
    int i;
    for (i = 0; i < 10; ++i) {
        if (i != a && i != b) {
            break;
        }
    }
    return i;
}

int getChangeNums(vector<int> v) {
    int count = 0;
    int pre;
    int cur;
    int nxt;
    for (int i = 1; i < v.size(); ++i) {
        pre = v[i - 1];
        cur = v[i];
        if (cur != v.size() - 1) {
            nxt = v[i + 1];
            if (cur == pre) {
                ++count;
                v[i] = getNum(pre, nxt);
            }
        } else {
            if (cur == pre) {
                ++count;
                v[i] = getNum(pre, pre);
            }
        }
    }
    return count;
}

int main() {
    string s;
    cin >> s;
    vector<int> vec = parseStringToInt(s);
    // printVector(vec);
    // cout << getNum(1, 2);
    cout << getChangeNums(vec) << endl;
    return 0;
}