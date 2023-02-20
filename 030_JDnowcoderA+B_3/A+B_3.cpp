#include <iostream>
using namespace std;

int main() {
    int n, m;
    while (cin >> n >>m) {
        if (n == 0 && m == 0) {
            break;
        } else {
            cout << n + m << endl;
        }
    }
    return 0;
}