// 0.9091
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m >= n - 2) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> vec(n, 0);
    vec[0] = n;
    for (int i = 1, j = 1; j <= m; ++j, i += 2) {
        vec[i] = j;
    }
    for (int i = 1, j = m + 1; i < n; ++i) {
        if (vec[i] == 0) {
            vec[i] = j;
            ++j;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}