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
    void genpath(TreeNode* node, vector<string> *vecs, string s) {
        if (!node)
            return;
        string value = to_string(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            s += value;
            vecs->push_back(s);
            return;
        }

        s += value + "->";
        if (node->left != nullptr)
            genpath(node->left, vecs, s);

        if (node->right != nullptr)
            genpath(node->right, vecs, s);

        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root)
            return result;
        genpath(root, &result, "");
        return result;
    }
};