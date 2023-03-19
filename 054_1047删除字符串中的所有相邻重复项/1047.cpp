#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); ++i) {
            if (st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else {
                st.pop();
            }
        }
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};