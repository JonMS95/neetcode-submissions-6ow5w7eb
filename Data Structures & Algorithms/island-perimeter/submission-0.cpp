/*
Each cell's perimeter is closely related to the number of surrounding cells.
SC's    Per
0       4
1       3
2       2
3       1
4       0

Therefore, we can state island perimeter is equal to 4 - (num of surrounding cells).

The proper approach is quite straightforward from this point: just get to a land 
cell (any of them is okay, it's guaranteed to exist just a single island), then
traverse the whole island recursively (from a cell to its neighbors). Keep track of
the visited cells so as to avoid loops and increment a global counter to return
afterwards representing island's total perimeter (can also be done using the grid
itself since it's stated nowhere we cannot do so).

Both DFS and BFS are likely to work here.
*/

class Solution
{
private:
    typedef enum
    {
        SEA = 0,
        NEW = 1,
        OLD = -1,
    } CELL_STATUS;

    const int mp_ = 4;

    inline bool _isCellValid(const std::vector<std::vector<int>>& grid, const int row, const int col)
    {
        return row >= 0 && row < static_cast<int>(grid.size()) && col >= 0 && col < static_cast<int>(grid[0].size());
    }

    inline std::vector<std::pair<int, int>> _getNeighborCoordinates(const int row, const int col)
    {
        return {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
    }

    int _dfs(std::vector<std::vector<int>>& grid, const int row, const int col)
    {
        if(grid[row][col] == OLD || grid[row][col] == SEA)
            return 0;
        
        grid[row][col] = OLD;

        int ret = mp_;

        for(const std::pair<int, int>& coords : _getNeighborCoordinates(row, col))
            if(_isCellValid(grid, coords.first, coords.second) && grid[coords.first][coords.second])
                ret += (_dfs(grid, coords.first, coords.second) - 1);
        
        return ret;
    }

    std::pair<int, int> _getFirstLandCoordinates(const std::vector<std::vector<int>>& grid)
    {
        for(int r = 0; r < static_cast<int>(grid.size()); r++)
            for(int c = 0; c < static_cast<int>(grid[0].size()); c++)
                if(grid[r][c] == NEW)
                    return {r, c};
        
        return {-1, -1};
    }

public:
    int islandPerimeter(std::vector<std::vector<int>>& grid)
    {
        std::pair<int, int> start = _getFirstLandCoordinates(grid);

        if(start == std::pair<int, int>({- 1, - 1}))
            throw std::runtime_error("No island was found while it was guaranteed to exist");
        
        return _dfs(grid, start.first, start.second);
    }
};
















