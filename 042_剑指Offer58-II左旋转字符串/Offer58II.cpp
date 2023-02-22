#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    void reverseStr(string& s, int start, int end) {
        for (int i = start, j = end; i < j; ++i, --j) {
            swap(s[i], s[j]);
        }
    }
    string reverseLeftWords(string s, int n) {
        reverseStr(s, 0, n - 1);
        reverseStr(s, n, s.size() - 1);
        reverseStr(s, 0, s.size() - 1);
        return s;
    }
};