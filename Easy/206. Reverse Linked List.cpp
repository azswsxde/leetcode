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
class Solution
{
    public:
        ListNode* test;
        void settoPrevious(ListNode* node, ListNode* nextNode)
        {
            nextNode->next = node;
        }
        void checkNext(ListNode* node, ListNode* nextNode)
        {
            if (nextNode->next != nullptr)
            {
                checkNext(nextNode, nextNode->next);
                settoPrevious(node, nextNode);
                return;
            }
            settoPrevious(node, nextNode);
            test = nextNode;
        }
        ListNode* reverseList(ListNode* head)
        {
            if (head != nullptr)
            {
                if (head->next != nullptr)
                {
                    checkNext(head, head->next);
                    head->next = nullptr;
                    return test;
                }
            }
            return head;
        }
};

/*
class Solution
{
    public:
        size_t node_count = 0;
        // count node size
        void countingList(ListNode* node, size_t& node_count)
        {
            node_count++;
            if (node->next != nullptr)
            {
                return countingList(node->next, node_count);
            }
        }

        void storeval(ListNode* node, int* val_array, size_t index)
        {
            val_array[index] = node->val;
            if (node->next != nullptr)
            {
                return storeval(node->next, val_array, (index + 1));
            }
        }

        void revertVal(ListNode* node, int* val_array, size_t index)
        {
            node->val = val_array[node_count - 1 - index];
            if (node->next != nullptr)
            {
                return revertVal(node->next, val_array, (index + 1));
            }
        }

        ListNode* reverseList(ListNode* head)
        {
            if (head != nullptr)
            {
                countingList(head, node_count);
                int* val_array = new int[node_count];
                storeval(head, val_array, 0);
                revertVal(head, val_array, 0);
                delete [] val_array;
            }
            return head;
        }
};
*/
