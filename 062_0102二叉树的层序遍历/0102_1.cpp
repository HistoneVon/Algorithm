#include <vector>
#include <queue>
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
    void order(TreeNode* curr, vector<vector<int> >& v, int depth) {
        if (curr == nullptr) {
            return;
        }
        if (depth == v.size()) {
            v.push_back(vector<int>());
        }
        v[depth].push_back(curr->val);
        order(curr->left, v, depth + 1);
        order(curr->right, v, depth + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        int depth = 0;
        order(root, res, 0);
        return res;
    }
};