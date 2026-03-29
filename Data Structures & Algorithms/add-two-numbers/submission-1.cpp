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
    using ln = ListNode;

    ln* _addTwoNumbers(ln* l1, ln* l2, int carry = 0)
    {
        int sum = 0;
        int num_l1 = (l1 ? l1->val : 0);
        int num_l2 = (l2 ? l2->val : 0);

        if(l1)
            l1 = l1->next;
        
        if(l2)
            l2 = l2->next;

        sum = carry + num_l1 + num_l2;
        carry = sum / 10;
        sum %= 10;

        ln* new_node = new ln(sum);

        if(l1 || l2 || carry)
            new_node->next = this->_addTwoNumbers(l1, l2, carry);
        
        return new_node;
    }

public:
    ln* addTwoNumbers(ln* l1, ln* l2)
    {
        return this->_addTwoNumbers(l1, l2);
    }
};
