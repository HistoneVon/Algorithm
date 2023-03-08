/**
 * @file 0151.cpp
 * @author Histone Von (fengclchn@outlook.com)
 * @brief 047_0151翻转字符串里的单词（ACM模式重写）
 * @version 0.1
 * @date 2023-03-08
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void removeExtraSpaces(string& s) {
    int slow = 0;
    for (int fast = 0; fast < s.size(); ++fast) {
        if (s[fast] != ' ') {
            if (slow != 0) {
                s[slow] = ' ';
                ++slow;
            }
            while (fast < s.size() && s[fast] != ' ') {
                s[slow] = s[fast];
                ++fast;
                ++slow;
            }
        }
    }
    s.resize(slow);
}

/**
 * @brief 反转字符串（左闭右闭）
 * @param s 字符串引用
 * @param start 起始字符索引
 * @param end 末尾字符索引
 */
void reverseStr(string& s, int start, int end) {
    for (int i = start, j = end; i < j; ++i, --j) {
        swap(s[i], s[j]);
    }
}

string reverseWords(string s) {
    removeExtraSpaces(s);
    reverseStr(s, 0, s.size() - 1);
    int start = 0;
    for (int i = 0; i <= s.size(); ++i) {
        if (' ' == s[i] || i == s.size()) {
            reverseStr(s, start, i - 1);
            start = i + 1;
        }
    }
    return s;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << endl;
    return 0;
}