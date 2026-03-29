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

// 1 -> 2 -> 3

class Solution {
private:
    ListNode* _revertListOrder(ListNode* head)
    {
        if(!head || !head->next)
            return head;
        
        this->_revertListOrder(head->next)->next = head;
        head->next = nullptr;
        return head;
    }

public:
    ListNode* reverseList(ListNode* head)
    {
        if(!head)
            return head;

        ListNode* aux = head;
        ListNode* ret;

        while(aux)
        {
            ret = aux;
            aux = aux->next;
        }

        this->_revertListOrder(head);

        return ret;
    }
};
