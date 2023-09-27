/**
 * @file reverseStr.cpp
 * @author Histone Von (fengclchn@outlook.com)
 * @brief https://www.nowcoder.com/questionTerminal/79c562297c0e4ff0952ef39ecde1bd6b
 * @version 0.1
 * @date 2023-03-04
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + n + 1);
    reverse(s.begin() + n + 1, s.end());
    cout << s << endl;
    return 0;
}