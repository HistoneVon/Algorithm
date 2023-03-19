#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long n1 = st.top();
                st.pop();
                long long n2 = st.top();
                st.pop();
                if (tokens[i] == "+") {
                    st.push(n2 + n1);
                } else if (tokens[i] == "-") {
                    st.push(n2 - n1);
                } else if (tokens[i] == "*") {
                    st.push(n2 * n1);
                } else {
                    st.push(n2 / n1);
                }
            } else {
                st.push(stoll(tokens[i]));
            }
        }
        int res = st.top();
        st.pop();
        return res;
    }
};