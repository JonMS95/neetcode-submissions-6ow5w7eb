class Solution {
private:
    int _countNodes(const std::vector<std::vector<int>>& edges)
    {
        std::unordered_set<int> members;

        for(const std::vector<int>& e : edges)
        {
            members.insert(e[0]);
            members.insert(e[1]);
        }

        return static_cast<int>(members.size());
    }

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

public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
    {
        const int members = this->_countNodes(edges);

        std::vector<int> parents(members);

        for(int i = 0; i < members; i++)
            parents[i] = i;
        
        std::vector<int> ret = {-1, -1};

        for(std::vector<int>& e : edges)
            if(!this->_union(e[0] - 1, e[1] - 1, parents))
                ret = e;
        
        return ret;
    }
};
