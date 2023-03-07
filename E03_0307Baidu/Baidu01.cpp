// 0.2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<double> vec;
    for (int i = 0; i < n; ++i) {
        double temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    int c = 0;
    double sum = 0;
    double sum_2 = 0;
    int count = 0;
    for (c = 0; c < k - 1; ++c) {
        sum += vec[c];
    }
    for (;c < n; ++c) {
        sum_2 += vec[c];
        ++count;
    }
    double res = sum + sum_2 / count;
    cout << res << endl;
    return 0;
}