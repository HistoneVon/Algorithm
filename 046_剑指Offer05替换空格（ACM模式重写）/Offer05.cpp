/**
 * @file Offer05.cpp
 * @author Histone Von (fengclchn@outlook.com)
 * @brief 046_剑指Offer05替换空格（ACM模式重写）
 * @version 0.1
 * @date 2023-03-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int count = 0; // 空格个数
    int oldSize = s.size();
    for (int i = 0; i < oldSize; ++i) {
        if (' ' == s[i]) {
            ++count;
        }
    }
    int newSize = oldSize + count * 2;
    s.resize(newSize);
    for (int i = oldSize - 1, j = newSize - 1; i < j; --i, --j) {
        if (' ' != s[i]) {
            s[j] = s[i];
        } else {
            s[j] = '0';
            s[j - 1] = '2';
            s[j - 2] = '%';
            j -= 2;
        }
    }
    cout << s << endl;
    return 0;
}