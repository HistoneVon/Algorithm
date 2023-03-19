#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

long long getFac(int n) {
    long long res = 1;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res % (10 ^ 9 + 7);
}

int main() {
    int n;
    cin >> n;
    vector<int> vec;
    long long count = 0;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        vec.push_back(temp);
        if (cin.get() == '\n') {
            sort(vec.begin(), vec.end());
            // int count_son = 1; // 自己也是自己的子集
            // int factor = vec[j]; // 初始因子是最小元素
            // 应该是要动态规划的，或者回溯
            // for (int k = j + 1; k < n; ++k) {
            //     if (vec[k] % factor == 0) {
            //         ++count_son;
            //         factor = vec[k];
            //     }
            // }
            int factor = vec[0]; // 初始因子是最小元素
            while (!vec.empty()) {
                int count_son = 1; // 自己也是自己的子集
                int m = vec.size();
                for (int j = 0; j < m; ++j) {
                    
                }
            }


            cout << count << endl;
        }
    }
    return 0;
}