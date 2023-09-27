// 测试过了，最终没过
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(int n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * func(n - 1);
}

void printVector(vector<int> v) {
    for (int i = 0; i < v.size();++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int getSequence(vector<int>& v) {
    // 没有1的情况
    int pos_1 = -1;
    for (int i = 0; i < v.size();++i) {
        if (v[i] == 1) {
            pos_1 = i;
            break;
        }
    }
    if (pos_1 == -1) {
        return 0;
    }
    // 如果有1
    int count = 0; // 统计的排列数
    bool flag = false; // 标记有没有经过计算1 之前的输入
    // 1及之前的!!!
    if (pos_1 != 0) {
        for (int i = 0; i < pos_1; ++i) { // 1 以后的
            vector<int> tempSequence(v.begin() + pos_1 - i, v.begin() + pos_1 + 1);
            sort(tempSequence.begin(), tempSequence.end());
            // cout << "i = " << i << " | ";
            // printVector(tempSequence);
            if (tempSequence[i] == i + 1) {
                count += 1;
            }
        }
    }
    for (int i = pos_1; i < v.size(); ++i) { // 1 以后的
        vector<int> tempSequence(v.begin(), v.begin() + i + 1);
        sort(tempSequence.begin(), tempSequence.end());
        // cout << "i = " << i << " | ";
        // printVector(tempSequence);
        if (tempSequence[i] == i + 1) {
            count += 1;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t; // T组数据，最多2
    while (t--) {
        int n;
        cin >> n; // 原始排列大小
        vector<int> vec;
        for (int i = 0; i < n; ++i) {
            int t;
            cin >> t;
            vec.push_back(t);
        }
        cout << getSequence(vec) << endl;
    }

    return 0;
}