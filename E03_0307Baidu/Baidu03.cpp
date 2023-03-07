// 错误的
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(int n) {
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    int sum = 0;
    int l = 1;
    while (l < n) {
        sum = l + func(n - l);
        l += 2;
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    int res;
    for (int i = 0; i < n;++i) {
        int a, b;
        cin >> a >> b;
        res = func(a) * func(b);
        cout << res << endl;
    }
    return 0;
}