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
    using vec_pln = std::vector<ln*>;

public:
    ln* mergeKLists(vec_pln& lists)
    {
        ln* ret = nullptr;

        auto sort_crit = [](const ln* a, const ln* b) -> bool
        {
            return (a->val > b->val);
        };

        std::priority_queue<ln*, vec_pln, decltype(sort_crit)> pq_min(sort_crit);

        for(ln* head : lists)
            if(head)
                pq_min.push(head);

        if(pq_min.size())
        {
            ret = pq_min.top();
            pq_min.pop();
            if(ret->next)
                pq_min.push(ret->next);
        }
        else
            return ret;
        
        ln* cur = ret;

        while(!pq_min.empty())
        {
            cur->next = pq_min.top();
            pq_min.pop();
            cur = cur->next;
            
            if(cur->next)
                pq_min.push(cur->next);
        }

        return ret;
    }
};
