// 0.18
#include <iostream>
#include <vector>
using namespace std;

int check(vector<int>& v, int k) {
    int res = 0;
    bool flag = false; // 标记上一轮循环是不是挨着
    for (int i = 0; i < v.size() && k!=0;) {
        if (v[i] < v[i + 1]) {
            res += v[i + 1];
            // i += 1;
            i += 2;
            flag = true;
        } else {
            res += v[i];
            i += 2;
            // --k;
            flag = false;
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> vec; // 通过美味值
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        vec.push_back(t);
    }
    cout << check(vec, k) << endl;
    return 0;
}