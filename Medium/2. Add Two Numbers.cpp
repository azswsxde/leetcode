/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#define MAX_VALUE_LENGTH 50

class Solution
{
    public:
        void check_augend_addend(ListNode* node, ListNode* augend, ListNode* addend)
        {
            ListNode* temp = new ListNode;
            if (augend->next != nullptr)
            {
                if (addend->next != nullptr)
                {
                    node->next = temp;
                    gen_result(node->next, augend->next, addend->next);
                }
                else
                {
                    node->next = temp;
                    gen_result(node->next, augend->next, nullptr);
                }
            }
            else
            {
                if (addend->next != nullptr)
                {
                    node->next = temp;
                    gen_result(node->next, addend->next, nullptr);
                }
                else
                {
                    gen_result(node->next, nullptr, nullptr);
                }
            }
        }
        void gen_result(ListNode* node, ListNode* augend, ListNode* addend)
        {
            if (augend == nullptr && addend == nullptr)
            {
                return;
            }
            else
            {
                if (augend != nullptr && addend != nullptr)
                {
                    node->val = augend->val + addend->val;
                    if (node->val > 9)
                    {
                        if (augend->next != nullptr)
                        {
                            augend->next->val += (node->val / 10);
                        }
                        else
                        {
                            ListNode* temp = new ListNode;
                            augend->next = temp;
                            temp->val = (node->val / 10);
                        }
                        node->val = node->val % 10;
                        check_augend_addend(node, augend, addend);
                    }
                    else
                    {
                        check_augend_addend(node, augend, addend);
                    }
                }
                else
                {
                    ListNode* temp = new ListNode;
                    node->val = augend->val;
                    if (node->val > 9)
                    {
                        node->next = temp;
                        if (augend->next != nullptr)
                        {
                            augend->next->val += (node->val / 10);
                        }
                        else
                        {
                            ListNode* temp2 = new ListNode;
                            augend->next = temp2;
                            temp2->val = (node->val / 10);
                        }
                        node->val = node->val % 10;
                        return gen_result(node->next, augend->next, addend);
                    }
                    else if (augend->next != nullptr)
                    {
                        node->next = temp;
                        return gen_result(node->next, augend->next, addend);
                    }
                }
            }
        }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            ListNode* result = new ListNode;
            if (l1->val == 0 && l1->next == nullptr)
            {
                return l2;
            }
            else if (l2->val == 0 && l2->next == nullptr)
            {
                return l1;
            }

            gen_result(result, l1, l2);
            return result;
        }
};