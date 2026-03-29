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
private:
    ListNode* _removeNthFromEnd(ListNode* head, int& n)
    {
        if(!head)
            return nullptr;
        
        head->next = this->_removeNthFromEnd(head->next, n);
        
        n--;

        if(!n)
            return head->next;
        else
            return head;
    }

public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        return this->_removeNthFromEnd(head, n);
    }
};
