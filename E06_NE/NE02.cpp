// AC
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string source;
    string target;
    while (cin >> source >> target) {
        int n = source.find(target);
        cout << n << endl;
    }
    return 0;
}