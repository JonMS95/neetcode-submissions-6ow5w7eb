class Solution {
    int _find(const int node_id, std::vector<int>& parents)
    {
        if(node_id != parents[node_id])
            parents[node_id] = this->_find(parents[node_id], parents);
        
        return parents[node_id];
    }

    void _union(const int first, const int second, std::vector<int>& parents)
    {
        int root_a = this->_find(first, parents);
        int root_b = this->_find(second, parents);

        if(root_a != root_b)
            parents[root_b] = root_a;
    }

    inline void _compress(std::vector<int>& parents)
    {
        for(int i = 0; i < static_cast<int>(parents.size()); i++)
            parents[i] = this->_find(i, parents);
    }

    int _getNumberOfDifferentParents(const std::vector<int>& parents)
    {
        std::unordered_set<int> diff_par;

        for(int p : parents)
            diff_par.insert(p);
        
        return static_cast<int>(diff_par.size());
    }

public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        std::vector<int> parents(n);

        for(int i = 0; i < n; i++)
            parents[i] = i;

        for(std::vector<int>& e : edges)
            this->_union(e[0], e[1], parents);
        
        this->_compress(parents);

        return this->_getNumberOfDifferentParents(parents);
    }
};
