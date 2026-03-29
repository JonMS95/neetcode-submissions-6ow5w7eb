class Solution {
private:
    typedef enum
    {
        SEA_CELL = '0',
        NEW_LAND = '1',
        EXPLORED = '2',
    } CELL_STATUS;

    inline bool _isCellValid(const std::vector<std::vector<char>>& grid, const int row, const int col)
    {
        return row >= 0 && row < static_cast<int>(grid.size()) && col >= 0 && col < static_cast<int>(grid[0].size());
    }

    std::vector<std::pair<int, int>> _getNextCoordinates(const int row, const int col)
    {
        return {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
    }

    void _dfs(std::vector<std::vector<char>>& grid, const int row, const int col)
    {
        if(grid[row][col] == SEA_CELL)
            throw std::runtime_error("Unexpectedly reached sea cell!");

        if(grid[row][col] == EXPLORED)
            return;
        
        grid[row][col] = EXPLORED;

        for(const std::pair<int, int> next_coords : this->_getNextCoordinates(row, col))
            if(this->_isCellValid(grid, next_coords.first, next_coords.second) && grid[next_coords.first][next_coords.second] == NEW_LAND)
                this->_dfs(grid, next_coords.first, next_coords.second);
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int ret = 0;

        for(int i = 0; i < static_cast<int>(grid.size()); i++)
        {
            for(int j = 0; j < static_cast<int>(grid[0].size()); j++)
            {
                if(grid[i][j] == NEW_LAND)
                {
                    ++ret;
                    this->_dfs(grid, i, j);
                }
            }
        }
        
        return ret;
    }
};
