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
    int checkdepth(TreeNode* node, int depth) {
        int depthLeft = 0, depthRight = 0;
        if (node->left == nullptr && node->right == nullptr)
            return depth;
        
        if (node->left != nullptr) {
            depthLeft = checkdepth(node->left, depth + 1);
            if (depthLeft == -1)
                return -1;
        }
        else depthLeft = depth;

        if (node->right != nullptr) {
            depthRight = checkdepth(node->right, depth + 1);
            if (depthRight == -1)
                return -1;
        }
        else depthRight = depth;

        if (abs(depthLeft - depthRight) > 1)
            return -1;

        if (depthLeft >= depthRight)
            return depthLeft;
        else
            return depthRight;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        return (checkdepth(root, 1) != -1);
    }
};