// 100% 复制二叉树
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @return TreeNode类
     */
    TreeNode* copyTree(TreeNode* root) {
        // write code here
        TreeNode* newRoot = new TreeNode(0);
        if (root == nullptr) {
            return newRoot;
        }
        TreeNode* rightChild = new TreeNode(root->val);
        copyTraversal(root, rightChild);
        newRoot->left = root;
        newRoot->right = rightChild;
        return newRoot;
    }

    void copyTraversal(TreeNode* oldTree, TreeNode* newTree) {
        if (oldTree == nullptr) {
            return;
        }
        if (oldTree->left) {
            TreeNode* newLeft = new TreeNode(oldTree->left->val);
            newTree->left = newLeft;
        }
        if (oldTree->right) {
            TreeNode* newRight = new TreeNode(oldTree->right->val);
            newTree->right = newRight;
        }
        copyTraversal(oldTree->left, newTree->left);
        copyTraversal(oldTree->right, newTree->right);
    }
};