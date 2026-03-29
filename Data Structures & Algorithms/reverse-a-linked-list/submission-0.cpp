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
            return nullptr;

        std::vector<ListNode*> vec;

        while(head)
        {
            vec.emplace_back(head);
            head = head->next;
        }

        for(int i = 0; i < static_cast<int>(vec.size() / 2); i++)
            std::swap(vec[i], vec[static_cast<int>(vec.size() - i - 1)]);
        
        for(int i = 0; i < static_cast<int>(vec.size() - 1); i++)
            vec[i]->next = vec[i + 1];
        
        vec[static_cast<int>(vec.size() - 1)]->next = nullptr;

        return vec[0];
    }
};
