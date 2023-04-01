#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2) {
    double res = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    res = sqrt(res);
    return res;
}

struct hash_pair {
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 * hash2;
    }
};

int main() {
    int n;
    double x, y;
    cin >> n >> x >> y;
    unordered_map<pair<double, double>, double, hash_pair> umap;
    for (int i = 0; i < n; ++i) {
        double xi, yi, ri;
        cin >> xi >> yi >> ri;
        pair<double, double> temp;
        temp.first = xi;
        temp.second = yi;
        umap[temp] = ri;
    }
    double max = 0; // 半径
    for (auto c : umap) {
        double temp = calculateDistance(x, y, c.first.first, c.first.second);
        temp -= c.second;
        max = max > temp ? max : temp;
    }
    cout << max << endl;
    return 0;
}