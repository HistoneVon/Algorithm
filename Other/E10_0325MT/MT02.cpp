// 0.09
#include <iostream>
#include <vector>
using namespace std;

int check(vector<int>& vec) {
    int res1 = 0;
    for (int i = 0; i < vec.size(); i += 3) {
        res1 += vec[i];
    }
    int res2 = 0;
    for (int i = 1; i < vec.size(); i += 3) {
        res2 += vec[i];
    }
    int res3 = 0;
    for (int i = 2; i < vec.size(); i += 3) {
        res3 += vec[i];
    }
    int max = res1 > res2 ? res1 : res2;
    max = max > res3 ? max : res3;
    return max;
}

int main() {
    int n;
    cin >> n;
    vector<int> vec; // 糖果美味值
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        vec.push_back(t);
        if (cin.get() == '\n') {
            cout << check(vec) << endl;
        }
    }
    return 0;
}