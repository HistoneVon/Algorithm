// 0.05
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

double calculateDistance(double x1, double y1, double x2, double y2) {
    double res = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    res = sqrt(res);
    return res;
}

int main() {
    int n;
    double x, y;
    cin >> n >> x >> y;
    vector<vector<double> > vec;
    for (int i = 0; i < n; ++i) {
        double xi, yi, ri;
        cin >> xi >> yi >> ri;
        vector<double> temp;
        temp.push_back(xi);
        temp.push_back(yi);
        temp.push_back(ri);
        vec.push_back(temp);
    }
    double max = 0; // 半径
    for (int i = 0; i < n; ++i) {
        double temp = calculateDistance(x, y, vec[i][0], vec[i][1]);
        temp -= vec[i][2];
        max = max > temp ? max : temp;
    }
    cout << max << endl;
    return 0;
}