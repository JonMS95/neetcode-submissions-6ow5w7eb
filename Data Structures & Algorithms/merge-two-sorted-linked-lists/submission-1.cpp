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
    void addNodesToVector(std::vector<ListNode*>& vec_nodes, ListNode* head)
    {
        while(head)
        {
            vec_nodes.emplace_back(head);
            head = head->next;
        }
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if(!list1 && !list2)
            return nullptr;

        if(list1 && !list2)
            return list1;
        
        if(!list1 && list2)
            return list2;

        std::vector<ListNode*> vec_nodes;
        
        this->addNodesToVector(vec_nodes, list1);
        this->addNodesToVector(vec_nodes, list2);

        auto sort_crit = [](ListNode* a, ListNode* b) -> bool
        {
            return a->val < b->val;
        };

        std::sort(vec_nodes.begin(), vec_nodes.end(), sort_crit);

        for(int i = 0; i < static_cast<int>(vec_nodes.size() - 1); i++)
            vec_nodes[i]->next = vec_nodes[i + 1];
        
        vec_nodes[static_cast<int>(vec_nodes.size() - 1)] = nullptr;

        return vec_nodes[0];
    }
};
