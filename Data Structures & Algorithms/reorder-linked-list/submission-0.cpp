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
    std::vector<ListNode*> getVectorFromLL(ListNode* head)
    {
        std::vector<ListNode*> ret;

        while(head)
        {
            ret.emplace_back(head);
            head = head->next;
        }

        return ret;
    }

public:
    void reorderList(ListNode* head)
    {
        if(!head || !head->next)
            return;

        std::vector<ListNode*> nodes = this->getVectorFromLL(head);

        const int vec_size = static_cast<int>(nodes.size());

        int l = 0;
        int r = vec_size - 1;

        std::vector<ListNode*> new_nodes;

        while(l < r)
        {
            new_nodes.emplace_back(nodes[l++]);
            new_nodes.emplace_back(nodes[r--]);
        }

        if(vec_size % 2)
            new_nodes.emplace_back(nodes[l]);

        for(int i = 0; i < (vec_size - 1); i++)
            new_nodes[i]->next = new_nodes[i + 1];
        
        new_nodes[(vec_size - 1)]->next = nullptr;
    }
};
