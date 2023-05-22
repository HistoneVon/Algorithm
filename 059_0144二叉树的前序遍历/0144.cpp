#include <vector>
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
    void traversal(TreeNode* curr, vector<int>& v) {
        if (curr == nullptr) {
            return;
        }
        v.push_back(curr->val);
        traversal(curr->left, v);
        traversal(curr->right, v);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};