#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (int i = 0; i < s.size(); ++i) {
            if (res.empty() || res.back() != s[i]) {
                res.push_back(s[i]);
            } else {
                res.pop_back();
            }
        }
        return res;
    }
};