#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x):val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(x), left(left), right(right) {}
};


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> res;
        TreeNode* curr = root;
        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } else {
                curr = st.top();
                st.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        return res;
    }
};