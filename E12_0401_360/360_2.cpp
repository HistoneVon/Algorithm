// 0.27
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

int main() {
    int n;
    cin >> n;
    vector<int> vec_array; // 存储原序列
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec_array.push_back(temp);
    }
    // printVector(vec_array);
    int k;
    cin >> k;
    vector<int> vec_point; // 存储分割点
    for (int i = 0; i < k; ++i) {
        int temp;
        cin >> temp;
        vec_point.push_back(temp);
    }
    sort(vec_point.begin(), vec_point.end());
    // printVector(vec_point);
    vector<int> vec_result; // 存储小明的输出
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vec_array[j] < vec_point[i]) { // 如果小于分割点，直接存入result
                vec_result.push_back(vec_array[j]);
                vec_array[j] = 10 ^ 5 + 2;
                // printVector(vec_result);
                // printVector(vec_array);
            } else if (vec_array[j] == vec_point[i]) {
                vec_array[j] = 10 ^ 5 + 2;
            }
        }
        vec_result.push_back(vec_point[i]); // 存储分割点
        // printVector(vec_result);
    }
    for (int i = 0; i < n; ++i) {
        if (vec_array[i] < (10 ^ 5 + 1)) {
            vec_result.push_back(vec_array[i]);
        }
    }
    printVector(vec_result);
    return 0;
}