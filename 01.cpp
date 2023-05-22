#include <iostream>
using namespace std;

int main() {
    int a[10];
    for (int i = 9; i >= 0; --i) {
        a[10 - i - 1] = i;
    }
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    // 冒泡
    for (int i = 0; i < 10 - 1; ++i) {
        for (int j = 0; j < 10 - i - 1; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j + 1], a[j]);
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        cout << a[i] << " ";
    }
    
    return 0;
}