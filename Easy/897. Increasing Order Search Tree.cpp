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
    void inorder(TreeNode* node, TreeNode*& result) {
        if (!node)
            return;
        if (node->left != nullptr)
            inorder(node->left, result);

        result->right = new TreeNode(node->val);
        result = result->right;

        if (node->right != nullptr)
            inorder(node->right, result);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode dummy(-1); // Dummy head
        TreeNode* result = &dummy;

        inorder(root, result);

        return dummy.right;
    }
};