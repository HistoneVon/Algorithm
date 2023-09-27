// 100%
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int parseFiveToDec(string s) {
    string src = "";
    for (unsigned long i = 0; i < s.size(); ++i) {
        switch (s[i]) {
        case 'o':
            src += '0';
            break;
        case 'y':
            src += '1';
            break;
        case 'e':
            src += '2';
            break;
        case 'a':
            src += '3';
            break;
        case 's':
            src += '4';
            break;
        default:
            break;
        }
    }
    char* stop;
    return strtol(src.c_str(), &stop, 5);

}

string intToA(int n, int radix) {
    string res = "";
    for (; n != 0;) {
        int t = n % radix;
        if (t >= 0 && t <= 9) {
            res += t + '0';
        } else {
            res += t - 10 + 'a';
        }
        n /= radix;
    }
    reverse(res.begin(), res.end());
    return res;
}

string parseDecToFive(string s) {
    string res;
    char* stop;
    int src = strtol(s.c_str(), &stop, 10);
    string temp = intToA(src, 5);
    for (unsigned long i = 0; i < temp.size(); ++i) {
        switch (temp[i]) {
        case '0':
            res += 'o';
            break;
        case '1':
            res += 'y';
            break;
        case '2':
            res += 'e';
            break;
        case '3':
            res += 'a';
            break;
        case '4':
            res += 's';
            break;
        default:
            break;
        }
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        string s;
        cin >> s;
        if (s[0] >= '0' && s[0] <= '9') {
            cout << parseDecToFive(s) << endl;
        } else {
            cout << parseFiveToDec(s) << endl;
        }
    }
    return 0;
}