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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        size_t result = 0;
        while(true)
        {
            if (result != 0)
                result = (result << 1) + head->val;
            else result = head->val;
            if (head->next != NULL)
                head = head->next;
            else
                break;
        }
        return result;
    }
};