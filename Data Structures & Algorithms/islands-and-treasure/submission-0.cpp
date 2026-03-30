/*
Let's perform a BFS starting from the treasure cells and until no active cells are found.
*/

class Solution
{
private:
    typedef enum
    {
        WATER       = -1,
        TREASURE    = 0,
        LAND        = 2147483647,
    } LAND_TYPE;

    inline std::vector<std::pair<int, int>> _getNextCoordinates(const int row, const int col)
    {
        return {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
    }

    inline bool _isCellValid(const std::vector<std::vector<int>>& grid, const int row, const int col)
    {
        return row >= 0 && row < static_cast<int>(grid.size()) && col >= 0 && col < static_cast<int>(grid[0].size());
    }

    std::vector<std::pair<int, int>> _getTreasureCoords(const std::vector<std::vector<int>>& grid)
    {
        std::vector<std::pair<int, int>> ret;

        for(int i = 0; i < static_cast<int>(grid.size()); i++)
            for(int j = 0; j < static_cast<int>(grid[0].size()); j++)
                if(grid[i][j] == TREASURE)
                    ret.push_back({i, j});
        
        return ret;
    }

    void _bfs(const std::vector<std::pair<int, int>>& start_coords, std::vector<std::vector<int>>& grid)
    {
        std::queue<std::pair<int, int>> next_coords;
        std::unordered_set<int> known;

        for(int i = 0; i < static_cast<int>(start_coords.size()); i++)
            next_coords.push(start_coords[i]);

        int time = -1;
        int queue_size;

        while(!next_coords.empty())
        {
            queue_size = static_cast<int>(next_coords.size());
            ++time;

            for(int i = 0; i < queue_size; i++)
            {
                if(grid[next_coords.front().first][next_coords.front().second] == LAND)
                {
                    known.insert((next_coords.front().first << 16) | next_coords.front().second);
                    grid[next_coords.front().first][next_coords.front().second] = time;
                }

                for(const std::pair<int, int> next : this->_getNextCoordinates(next_coords.front().first, next_coords.front().second))
                    if(!this->_isCellValid(grid, next.first, next.second) || known.count((next.first << 16) | next.second) || grid[next.first][next.second] != LAND)
                        continue;
                    else
                        next_coords.push({next.first, next.second});

                next_coords.pop();
            }
        }
    }

public:
    void islandsAndTreasure(vector<vector<int>>& grid)
    {
        this->_bfs(this->_getTreasureCoords(grid), grid);
    }
};
