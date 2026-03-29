/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    Node* traverseGraph(Node* node, std::unordered_map<Node*, Node*>& visited)
    {
        if(!node)
            return node;

        if(visited.count(node))
            return visited[node];

        std::cout << node->val << std::endl;

        Node* new_node = new Node(node->val);

        visited[node] = new_node;

        for(Node* p_node : node->neighbors)
            new_node->neighbors.emplace_back(this->traverseGraph(p_node, visited));
        
        return new_node;
    }

public:
    Node* cloneGraph(Node* node)
    {
        std::unordered_map<Node*, Node*> visited_nodes;
        return this->traverseGraph(node, visited_nodes);
    }
};
