// 100%
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool check(vector<int>& in, vector<int>& out) {
    stack<int> S;
    // cout << "size: " << in.size() << " " << out.size() << endl;
    int i = 0; // in
    int j = 0; // out
    for (; i < in.size(); ++i) {
        // cout << "in[i] == " << in[i] << endl;
        S.push(in[i]);
        // cout << "top: " << S.top() << endl;
        // cout << "out[j] == " << out[j] << endl;
        while (!S.empty() && S.top() == out[j]) {
            ++j;
            S.pop();
        }
    }
    return S.empty();
}

int main() {
    int T; // 数据组数
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        vector<int> vec_in;
        vector<int> vec_out;
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            vec_in.push_back(x);
        }
        for (int j = 0; j < n; ++j) {
            int y;
            cin >> y;
            vec_out.push_back(y);
        }
        if (check(vec_in, vec_out)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}