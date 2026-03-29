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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        int l1_num, l2_num;
        int cur_fig_sum;

        ListNode* prev = new ListNode();
        ListNode* ret = prev;

        while(l1 || l2 || carry)
        {
            if(l1)
            {
                l1_num = l1->val;
                l1 = l1->next;
            }
            else
                l1_num = 0;

            if(l2)
            {
                l2_num = l2->val;
                l2 = l2->next;
            }
            else
                l2_num = 0;            

            cur_fig_sum = l1_num + l2_num + carry;
            carry = cur_fig_sum / 10;
            cur_fig_sum %= 10;

            ListNode* new_node = new ListNode(cur_fig_sum);
            if(!ret)
                ret = new_node;
            prev->next = new_node;
            prev = prev->next;
        }

        return ret->next;
    }
};
