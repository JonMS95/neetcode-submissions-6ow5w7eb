class Solution {
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;
    using set_int = std::unordered_set<int>;
    using map_int_set_int = std::unordered_map<int, set_int>;

    map_int_set_int _makeMapFromMatrix(int n, mat_int& edges)
    {
        map_int_set_int ret;

        for(int i = 0; i < static_cast<int>(edges.size()); i++)
        {
            ret[edges[i][0]].insert(edges[i][1]);
            ret[edges[i][1]].insert(edges[i][0]);
        }

        for(int i = 0; i < n; i++)
            if(!ret.count(i))
                ret[i] = {};
        
        return ret;
    }

    void _traverseMap(const int node_id, map_int_set_int& node_map, set_int& visited)
    {
        if(visited.count(node_id))
            return;
        
        visited.insert(node_id);
        
        for(int next_node_id : node_map[node_id])
            this->_traverseMap(next_node_id, node_map, visited);
    }

    int _countGroups(map_int_set_int& node_map)
    {
        int ret = 0;
        set_int visited;

        for(int node_id = 0; node_id < static_cast<int>(node_map.size()); node_id++)
        {
            if(visited.count(node_id))
                continue;
            
            this->_traverseMap(node_id, node_map, visited);
            ++ret;
        }

        return ret;
    }

public:
    int countComponents(int n, mat_int& edges)
    {
        map_int_set_int node_map = this->_makeMapFromMatrix(n, edges);
        return this->_countGroups(node_map);
    }
};
