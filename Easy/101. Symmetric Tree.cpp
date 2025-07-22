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
    void mirror_post_order(TreeNode* node, vector<int> *vec) {
        if (!node){
            vec->push_back(-999);
            return;
        }
        if (node->right != nullptr)
            mirror_post_order(node->right, vec);
        else
            vec->push_back(-999);
        if (node->left != nullptr)
            mirror_post_order(node->left, vec);
        else
            vec->push_back(-999);

        vec->push_back(node->val);
    }
    void post_order(TreeNode* node, vector<int> *vec) {
        if (!node){
            vec->push_back(-999);
            return;
        }

        if (node->left != nullptr)
            post_order(node->left, vec);
        else
            vec->push_back(-999);
        if (node->right != nullptr)
            post_order(node->right, vec);
        else
            vec->push_back(-999);

        vec->push_back(node->val);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> left, right;
        if (root->left != nullptr)
            post_order(root->left, &left);

        if (root->right != nullptr)
            mirror_post_order(root->right, &right);

        if (left.size() != right.size())
            return false;
        for (unsigned short i = 0 ; i < left.size(); i++) {
            if (left[i] != right[i])
                return false;
        }
        return true;
    }
};