class Solution
{
private:
    bool isPosValid(std::vector<std::vector<char>>& grid, const int row, const int col)
    {
        const int row_num = static_cast<int>(grid.size());
        const int col_num = static_cast<int>(grid[0].size());

        if(row < 0 || col < 0 || row >= row_num || col >= col_num)
            return false;
        
        return true;
    }

    void traverseIsland(std::vector<std::vector<char>>& grid, const int row, const int col)
    {
        if(!this->isPosValid(grid, row, col))
            throw std::runtime_error("Invalid coordinates found");

        grid[row][col] = '2';    // Mark them as explored.

        std::vector<std::pair<int, int>> next_coords =
        {
            {row - 1, col       }, // up 
            {row    , col - 1   }, // left
            {row + 1, col       }, // down
            {row    , col + 1   }, // right
        };

        for(std::pair<int, int>& p : next_coords)
            if(this->isPosValid(grid, p.first, p.second) && grid[p.first][p.second] == '1')
                this->traverseIsland(grid, p.first, p.second);
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int island_counter = 0;

        /*
            For each cell within the map, and land is found (1 == explored land), then start by
            incrementing island counter. Immediately afterwards, traverse recursively all adjacent
            islands by marking them with 2 (== visited land) so as to skip them later.
        */

        for(int i = 0; i < static_cast<int>(grid.size()); i++)
        {
            for(int j = 0; j < static_cast<int>(grid[0].size()); j++)
            {
                if(grid[i][j] == '1')
                {
                    ++island_counter;
                    this->traverseIsland(grid, i, j);
                }
            }
        }

        return island_counter;
    }
};
