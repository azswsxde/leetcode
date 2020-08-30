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
    bool uninit; //for init result ListNode
    void remakeList(ListNode* result, ListNode* node){
        if (node == nullptr){
            return;
        }

        // if result is uninited init it first
        if (uninit){
            // copy node to result and return
            uninit = false;
            result->val = node->val;
            result->next = node->next;
            return;
        }
        else{
            //because l1 or l2 is sorted, pointer result's next to node
            result->next = node;
            return;
        }
    }
    void linknode(ListNode* result, ListNode* noUse, ListNode* Use){
        // if result is uninited init it first
        // else return remakelist
        if (uninit){
            // copy Use ListNode val
            // and call remakeList with Use's next ListNode
            uninit = false;
            result->val = Use->val;
            return remakeList(result, noUse, Use->next);
        }
        else{
            // let result's next equal Use
            // and call remakeList with Use's next ListNode
            result->next = Use;
            return remakeList(result->next, noUse, Use->next);
        }
    }
    void remakeList(ListNode* result, ListNode* l1, ListNode* l2){
        // if l1 or l2 is null pointer do remakelist with another ListNode
        if (l1 == nullptr)
        {
            return remakeList(result, l2);
        }
        if (l2 == nullptr)
        {
            return remakeList(result, l1);
        }

        // if l1 point to ListNode's value less then l2's do linknode, use l2 pointer as noUse l1 pointer as Use
        // else use l1 pointer as noUse l2 pointer as Use
        if (l1->val < l2->val){
            return linknode(result, l2, l1);
        }
        else{
            return linknode(result, l1, l2);
        }
    }
    // leetcode run this function
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* ans = new ListNode;
        uninit = true;
        if (l1 == nullptr && l2 == nullptr){
            return nullptr;
        }
        remakeList(ans ,l1, l2);
        ListNode* test = ans;
        return ans;
    }
};