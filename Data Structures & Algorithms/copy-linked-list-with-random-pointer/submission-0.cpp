/*
Approach: use a hashmap to map old to new nodes. Create each mapping
in a first iteration, then link nodes in a following one.
*/

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
    // During the first iteration, just map nodes to newly created ones.
    std::unordered_map<Node*, Node*> _mapNodes(Node* head)
    {
        std::unordered_map<Node*, Node*> ret;

        while(head)
        {
            ret[head] = new Node(head->val);
            head = head->next;
        }

        return ret;
    }

    // Perform a second iteration to apply links.
    void _applyLinks(Node* head, std::unordered_map<Node*, Node*>& node_map)
    {
        while(head)
        {
            node_map[head]->next = node_map[head->next];
            node_map[head]->random = node_map[head->random];
            
            head = head->next;
        }
    }

public:
    Node* copyRandomList(Node* head)
    {
        std::unordered_map<Node*, Node*> node_map = _mapNodes(head);
        _applyLinks(head, node_map);

        return node_map[head];
    }
};
