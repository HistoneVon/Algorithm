/**
 * @file 0344.cpp
 * @author Histone Von (fengclchn@outlook.com)
 * @brief 反转字符串（ACM模式重写）
 * @version 0.1
 * @date 2023-03-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> parseStringToVector(const string& s) {
    vector<char> res;
    for (int i = 0; i < s.size(); ++i) {
        res.push_back(s[i]);
    }
    return res;
}

void reverseStr(vector<char>& v) {
    for (int i = 0, j = v.size() - 1; i < v.size() / 2; ++i, --j) {
        v[i] ^= v[j];
        v[j] ^= v[i];
        v[i] ^= v[j];
        // swap(v[i], v[j]); // algorithm
    }
}

void printVector(vector<char>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    string s;
    cin >> s;
    vector<char> vec;
    vec = parseStringToVector(s);
    reverseStr(vec);
    printVector(vec);
    return 0;
}