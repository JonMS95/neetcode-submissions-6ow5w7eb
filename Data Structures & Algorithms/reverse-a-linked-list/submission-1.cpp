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
    ListNode* reverseList(ListNode* head)
    {
        if(!head)
            return head;

        std::stack<ListNode*> st;

        while(head)
        {
            st.push(head);
            head = head->next;
        }

        ListNode* ret = st.top(); st.pop();
        ListNode* aux = ret;

        while(!st.empty())
        {
            aux->next = st.top(); st.pop();
            aux = aux->next;
        }

        aux->next = nullptr;

        return ret;
    }
};
