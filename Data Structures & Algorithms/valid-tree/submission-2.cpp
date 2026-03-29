/*
What should we check:
·No loops: starting from a given node, we can't be visiting the same node twice.
·No isolated groups: all the nodes should belong to the same group / have the same parent.
*/

class Solution
{
    int _find(const int node_id, std::vector<int>& parents)
    {
        if(node_id != parents[node_id])
            parents[node_id] = this->_find(parents[node_id], parents);
        
        return parents[node_id];
    }

    bool _union(const int node_a, const int node_b, std::vector<int>& parents)
    {
        const int root_a = this->_find(node_a, parents);
        const int root_b = this->_find(node_b, parents);

        if(root_a == root_b)
            return false;

        parents[root_b] = root_a;
        
        return true;
    }

    void _compress(std::vector<int>& parents)
    {
        for(int i = 0; i < static_cast<int>(parents.size()); i++)
            parents[i] = this->_find(i, parents);
    }

    int _countDiffParents(const std::vector<int>& parents)
    {
        std::unordered_set<int> diff;

        for(int p : parents)
            diff.insert(p);
        
        return static_cast<int>(diff.size());
    }

public:
    bool validTree(int n, std::vector<std::vector<int>>& edges)
    {
        std::vector<int> parents(n);

        for(int i = 0; i < n; i++)
            parents[i] = i;

        for(const std::vector<int>& e : edges)
            if(!this->_union(e[0], e[1], parents))
                return false;

        this->_compress(parents);

        if(this->_countDiffParents(parents) != 1)
            return false;

        return true;
    }
};
