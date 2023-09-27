// 0，应该是dp
#include <iostream>
#include <string>
using namespace std;

// 查询最长的1多长及其位置
void searchOne(string s, int n, int& max, int& pos) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++count;
            int temp_max = max;
            max = max > count ? max : count;
            if (temp_max != max) {
                pos = i;
            }
        } else {
            count = 0;
        }
    }
}

// 计算子串个数
int calculateSubString(int n, int max, int pos) {
    int left = 1;
    int end = pos + 1; // 1的结束，从1开始数，包含
    int start = end - max + 1; // 1的开始，从1开始数，包含
    // 计算左边
    for (int i = 0; i < start - 1; ++i) {
        left = (left + left * 2) % (10 ^ 9 + 7);
    }
    int right = 1;
    for (int i = 0; i < n - end; ++i) {
        right = (right + right * 2) % (10 ^ 9 + 7);
    }
    return left * right % (10 ^ 9 + 7);
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int max = 0;
    int pos = 0;
    searchOne(s, n, max, pos);
    cout << calculateSubString(n, max, pos);
    return 0;
}