/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
private:
    Node* _dfs(Node* head, std::unordered_map<Node*, Node*>& known)
    {
        if(!head)
            return head;

        if(known.count(head))
            return known[head];
        
        Node* new_node = new Node(head->val);

        known[head] = new_node;

        if(head->next)
            new_node->next = _dfs(head->next, known);
        
        if(head->random)
            new_node->random = _dfs(head->random, known);

        return new_node;
    }
    
public:
    Node* copyRandomList(Node* head)
    {
        std::unordered_map<Node*, Node*> known;
        return _dfs(head, known);
    }
};
