/*
Brute force: place all nodes in a vector, then reverse nodes in group
of size k. It's not that slow, but it wastes too much memory and we are
forcd to traverse the linked list at least twice.

Recursive: let's start building a simpler problem, then make it more
suitable for the current problem.

Problem 1 - Reverse linked list
Build a function that returns a pointer to a node and that takes also a
node as input parameter.
If node is equal to nullptr, then return nullptr (should not happen).
If node's next node is nullptr, then return current node.
Otherwise (current node is not null and it's not the last one either),
pick the next node. Make next node point at current node. Current node
should point at nullptr now. Return current node.

Problem 2 - Reverse linked list with head and tail
Same as above, but a pair of node pointers is returned instead of a
single pointer.
If a nullptr is found, then return {nullptr, nullptr}.
If a last node is found (no next node), return {current_node, current_node}.
Else, update tail (pairs second element) as the current node after having
modified next element (pairs first element) as in the previous function.

Problem 3 - Reverse linked list with head, tail and elements limit.
Same as the one above but with a limit. The condition to backtrack is not
to come across a node with either no next node or a limit has been reached.
Keep in mind that (just in case), the node with no next node (or the one
that reaches the limit) should have its next node as nullptr.
This function should take also a counter (number of nodes) and that's
decremented whenever the function is entered.
Example:
1 -> 2 -> 3 -> 4, k = 3
Returns:
3 -> 2 -> 1

Problem 4 - Reverse linked list with head, tail, next head and elements limit.
Same as the one above but whenever we come across a final node (the one that
exhausts) the counter, if it's not the globally last one (next node is not
null), then return the next head somewhere. A nice approach would be to
return a new class object (AuxData) which would include those 3 elements.
Example 1:
1 -> 2 -> 3 -> 4, k = 3
Returns:
3, 1, 4 (head, tail and next head).
Example 2:
1 -> 2 -> 3 -> 4, k = 5
3, 4, nullptr.
*/

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

class Solution
{
private:
    // Returns a vector containing {head, tail, next head} after reversing linked list.
    std::array<ListNode*, 3> _reverseList(ListNode* node, int counter)
    {
        // If counter has a greater than zero value, decrement it.
        if(counter)
            --counter;
        
        // Should not happen since the recursion is expected to be cut short way earlier.
        if(!node)
            return {nullptr, nullptr, nullptr};
        
        // If current node is the global ending node, then first and second elements to return are head and tail
        // (although tail is later on modified), while next head is equal to null.
        if(!node->next)
        {
            return {node, node, nullptr};
        }
        
        // If current node exhausts the counter, next head might be nullptr or not, we should include it either
        // way. Doesn't really matter, might happen that there is actually a next list or it's empty (nullptr).
        if(!counter)
        {
            return {node, node, node->next};
        }
        
        std::array<ListNode*, 3> ret = _reverseList(node->next, counter);
        ListNode* next_node = ret[1];
        next_node->next = node;
        node->next = nullptr;
        ret[1] = node;
        
        return ret;
    }

    bool _hasAtLeastSizeK(ListNode* head, const int k)
    {
        int cnt = 0;
        
        while(head)
        {
            ++cnt;

            if(cnt == k)
                return true;
            
            head = head->next;
        }

        return false;
    }

    std::array<ListNode*, 3> _getListBoundaries(ListNode* head)
    {
        std::array<ListNode*, 3> ret = {head, nullptr, nullptr};

        while(head)
        {
            ret[1] = head;
            head = head->next;
        }

        return ret;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* ret = nullptr;
        std::array<ListNode*, 3> aux = {nullptr, nullptr, nullptr};
        ListNode* prev_tail = nullptr;

        do
        {
            if(_hasAtLeastSizeK(head, k))
                aux = _reverseList(head, k);
            else
                aux = _getListBoundaries(head);
            
            if(prev_tail)
                prev_tail->next = aux[0];

            if(!ret)
                ret = aux[0];
            
            head = aux[2];

            prev_tail = aux[1];
        } while(aux[2] != nullptr);

        return ret;
    }
};
