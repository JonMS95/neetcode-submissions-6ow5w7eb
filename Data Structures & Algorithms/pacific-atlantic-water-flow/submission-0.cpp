class Solution {
private:
    using mat_int = std::vector<std::vector<int>>;
    using u_set_i = std::unordered_set<int>;

    inline bool isCellValid(mat_int& cells, const int row, const int col)
    {
        return row >= 0 && row < static_cast<int>(cells.size()) && col >= 0 && col < static_cast<int>(cells[0].size());
    }

    void dfs(mat_int& cells, const int row, const int col, u_set_i& reach_values)
    {
        // Avoid endless loops by simply writing a -1 into them.
        // Store cell's coordinates in reach_values.
        // Since reachability is checked beforehand, every
        // visited valid cell is added to reach_values.

        if(!this->isCellValid(cells, row, col) || reach_values.count(10000 * row + col))
            return;
        
        reach_values.insert((10000 * row + col));

        std::vector<std::pair<int, int>> next_coords =
        {
            {row - 1,   col     }, // Up
            {row + 1,   col     }, // Down
            {row    ,   col - 1 }, // Left
            {row    ,   col + 1 }, // Right
        };

        for(std::pair<int, int>& coords : next_coords)
            if( this->isCellValid(cells, coords.first, coords.second)   &&
                cells[row][col] <= cells[coords.first][coords.second]             )
                    this->dfs(cells, coords.first, coords.second, reach_values);
    }

public:
    mat_int pacificAtlantic(mat_int& heights)
    {
        std::unordered_set<int> known_pac, known_atl;
        mat_int ret;

        const int num_rows = static_cast<int>(heights.size());
        const int num_cols = static_cast<int>(heights[0].size());

        for(int i = 0; i < num_cols; i++)
            this->dfs(heights, 0, i, known_pac);
        
        for(int i = 0; i < num_rows; i++)
            this->dfs(heights, i, 0, known_pac);
        
        for(int i = 0; i < num_cols; i++)
            this->dfs(heights, (num_rows - 1), i, known_atl);
        
        for(int i = 0; i < num_rows; i++)
            this->dfs(heights, i, (num_cols - 1), known_atl);
        
        for(int coord : known_pac)
            if(known_atl.count(coord))
                ret.push_back({coord / 10000, coord % 10000});
        
        return ret;
    }
};
