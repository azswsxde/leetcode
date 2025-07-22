/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void revert(TreeNode* node) {
        if (!node)
            return;
        TreeNode* temp;
        if (node->left != nullptr)
            revert(node->left);
        if (node->right != nullptr)
            revert(node->right);
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root)
            return root;
        revert(root);
        return root;
    }
};