class Solution
{
private:
    using vec_int       = std::vector<int>;
    using mat_int       = std::vector<vec_int>;
    using node_id       = std::pair<int, int>;
    using node_vec      = std::vector<node_id>;
    using wn_par        = std::pair<int, node_id>;
    using wn_par_vec    = std::vector<wn_par>;

    inline bool _isCellValid(const mat_int& grid, const node_id& coords)
    {
        return  coords.first >= 0                               &&
                coords.first < static_cast<int>(grid.size())    &&
                coords.second >= 0                              && 
                coords.second < static_cast<int>(grid[0].size());
    }

    inline node_vec _getNeighborCells(const node_id& coords)
    {
        return {{coords.first + 1, coords.second}, 
                {coords.first - 1, coords.second},
                {coords.first, coords.second + 1},
                {coords.first, coords.second - 1}};
    }

    int _dijkstra(const mat_int& grid)
    {
        const int num_of_rows = static_cast<int>(grid.size());
        const int num_of_cols = static_cast<int>(grid[0].size());

        mat_int dist(num_of_rows, vec_int(num_of_cols, INT_MAX));
        dist[0][0] = grid[0][0];

        auto sort_crit = [](const wn_par& a, const wn_par& b) -> bool
        {
            return a.first > b.first;
        };
        std::priority_queue<wn_par, wn_par_vec, decltype(sort_crit)> min_heap(sort_crit);

        min_heap.push({dist[0][0], {0, 0}});

        node_id u, v;
        int d, w;

        while(!min_heap.empty())
        {
            d = min_heap.top().first;
            u = min_heap.top().second;

            min_heap.pop();

            if(d > dist[u.first][u.second])
                continue;
            
            for(const node_id& next : _getNeighborCells(u))
            {
                if(!_isCellValid(grid, next))
                    continue;

                v = next;
                w = std::max(dist[u.first][u.second], grid[v.first][v.second]);

                if(w < dist[v.first][v.second])
                {
                    dist[v.first][v.second] = w;
                    min_heap.push({w, v});
                }
            }
        }

        return dist[num_of_rows - 1][num_of_cols - 1];
    }

public:
    int swimInWater(mat_int& grid)
    {
        return _dijkstra(grid);
    }
};
