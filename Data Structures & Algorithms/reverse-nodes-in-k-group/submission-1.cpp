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
    std::vector<ListNode*> _getLinkedListAsVector(ListNode* head)
    {
        std::vector<ListNode*> ret;
        
        while(head)
        {
            ret.emplace_back(head);
            head = head->next;
        }

        return ret;
    }

    inline void _swapBetweenBoundaries(std::vector<ListNode*>& nodes, int l, int r)
    {
        while(l < r)
            std::swap(nodes[l++], nodes[r--]);
    }

    void _swapInGroups(std::vector<ListNode*>& nodes, const int k)
    {
        int number_of_groups = static_cast<int>(nodes.size()) / k;

        for(int i = 0; i < number_of_groups; i++)
            _swapBetweenBoundaries(nodes, i * k, (i + 1) * k - 1);
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        std::vector<ListNode*> vec = _getLinkedListAsVector(head);
        _swapInGroups(vec, k);

        for(int i = 0; i < static_cast<int>(vec.size() - 1); i++)
            vec[i]->next = vec[i + 1];
        
        vec[static_cast<int>(vec.size()) - 1]->next = nullptr;

        return vec[0];
    }
};
