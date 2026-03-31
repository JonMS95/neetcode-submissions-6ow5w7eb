class Solution {
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;
    using par_int = std::pair<int, int>;
    using vec_par = std::vector<par_int>;
    using mat_par = std::vector<vec_par>;

    mat_par _getAdjacencyMatrix(const mat_int& times, const int n)
    {
        // The variable to be returned is a matrix. In that matrix, each row is
        // a vector of integer pairs.
        mat_par ret(n);
        
        int u, v, w;

        for(int i = 0; i < static_cast<int>(times.size()); i++)
        {
            u = times[i][0] - 1;
            v = times[i][1] - 1;
            w = times[i][2];

            ret[u].push_back({v, w});
        }

        return ret;
    }

    vec_int _dijkstra(mat_par& adj_mat, const int src)
    {
        // Get number of involved nodes.
        const int num_of_nodes = static_cast<int>(adj_mat.size());
    
        // Create a vector of distances from src.
        vec_int dist(num_of_nodes, INT_MAX);
        dist[src] = 0;

        // Create a heap to store {distance from source, node_id} pairs.
        auto org_crit = [](const par_int& a, const par_int& b) -> bool
        {
            return a.first > b.first;
        };

        std::priority_queue<par_int, vec_par, decltype(org_crit)> min_heap(org_crit);
    
        // Push the {distance to from source to source, source} pair to the min heap.
        min_heap.push({dist[src], src});

        // Create variables for cur node, adj node, cur node distance, next node weight.
        int u, v, d, w;

        while(!min_heap.empty())
        {
            // Extract current node from heap.
            d = min_heap.top().first;
            u = min_heap.top().second;

            // Pop it now, don't wait for later (all necessary elements are already retrieved).
            min_heap.pop();

            // If it does not improve already stored distance, continue to the following element.
            if(d > dist[u])
                continue;
            
            // Explore adjacent nodes (use adjacency matrix).
            for(par_int& adj_node : adj_mat[u])
            {
                v = adj_node.first;
                w = adj_node.second;

                // If distance to current node + weight to the following improves distance, then
                // set distance as the sum of both.
                if(dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    min_heap.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    int _getMaxInVector(const vec_int& vec)
    {
        int ret = -1;

        for(int n : vec)
            if(n > ret)
                ret = n;
        
        return ret;
    }

public:
    int networkDelayTime(mat_int& times, int n, int k)
    {
        mat_par adj_mat = this->_getAdjacencyMatrix(times, n);

        vec_int dist = this->_dijkstra(adj_mat, k - 1);

        int max_time = this->_getMaxInVector(dist);

        if(max_time == -1 || max_time == INT_MAX)
            return -1;

        return max_time;        
    }
};
