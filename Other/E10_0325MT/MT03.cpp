// 0.82
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVector(vector<int>& v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int bag(vector<int>& vec_chocolate, int weight) {
    int count = 0;
    for (int i = 0; i < vec_chocolate.size(); ++i) {
        if (vec_chocolate[i] <= weight) {
            weight -= vec_chocolate[i];
            ++count;
        } else {
            break;
        }
    }
    return count;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> vec_chocolate; // 巧克力重量
    vector<int> vec_question; // 询问数量
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t; // 巧克力边长输入
        vec_chocolate.push_back(t * t); // 直接存入巧克力重量
    }
    sort(vec_chocolate.begin(), vec_chocolate.end());
    // printVector(vec_chocolate);
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t; // 背包容量输入
        vec_question.push_back(t); // 存入背包容量
    }
    // printVector(vec_question);
    for (int i = 0; i < m; ++i) {
        cout << bag(vec_chocolate, vec_question[i]) << " ";
    }
    cout << endl;
    return 0;
}