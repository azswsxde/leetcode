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
    void makestack(TreeNode* temp, stack<short> *stack) {
        if (temp->left == nullptr && temp->right == nullptr) {
            stack->push(temp->val);
            return ;
        }
        if (temp->left != nullptr) {
            makestack(temp->left, stack);
        }
        else {
            stack->push(SHRT_MIN);
        }
        if (temp->right != nullptr) {
            makestack(temp->right, stack);
        }
        else {
            stack->push(SHRT_MIN);
        }
        stack->push(temp->val);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<short> p_stack, q_stack;
        if (p != nullptr) {
            makestack(p, &p_stack);
        }
        if (q != nullptr) {
            makestack(q, &q_stack);
        }

        if (p_stack.empty() && q_stack.empty())
            return true;
        if (p_stack.size() != q_stack.size())
            return false;
        while (!p_stack.empty()) {
            if (p_stack.top() != q_stack.top())
                return false;
            p_stack.pop();
            q_stack.pop();
        }
        return true;
    }
};