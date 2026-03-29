class Solution {
private:
    typedef enum
    {
        EMPTY   = 0,
        FRESH   = 1,
        ROTTEN  = 2,
    } CELL_STATUS;

    // Returns {number of fresh fruits, queue including all rotten fruit coordinates}
    std::pair<int, std::queue<std::pair<int, int>>> _initialData(const std::vector<std::vector<int>>& grid)
    {
        int fresh = 0;
        std::queue<std::pair<int, int>> rotten;
    
        for(int row = 0; row < static_cast<int>(grid.size()); row++)
        {
            for(int col = 0; col < static_cast<int>(grid[0].size()); col++)
            {
                if(grid[row][col] == FRESH)
                {
                    ++fresh;
                    continue;
                }

                if(grid[row][col] == ROTTEN)
                    rotten.push({row, col});
            }
        }

        return {fresh, rotten};
    }

    bool _isCellValid(const std::vector<std::vector<int>>& grid, const int row, const int col)
    {
        return row >= 0 && row < static_cast<int>(grid.size()) && col >= 0 && col < static_cast<int>(grid[0].size());
    }

    std::vector<std::pair<int, int>> _getNextCoordinates(const int row, const int col)
    {
        return {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
    }

void _expand(std::vector<std::vector<int>>& grid, std::queue<std::pair<int,int>>& rotten,
             int& fresh, int& time)
{
    if(rotten.empty())
        return;
    
    int num_elem = rotten.size();
    int row, col;

    while(!rotten.empty())
    {
        for(int i = 0; i < num_elem; i++)
        {
            row = rotten.front().first;
            col = rotten.front().second;

            if(grid[row][col] == FRESH)
            {
                grid[row][col] = ROTTEN;

                fresh--;
                if(!fresh)
                    return;
            }
            
            for(std::pair<int, int> new_coords : this->_getNextCoordinates(row, col))
                if(this->_isCellValid(grid, new_coords.first, new_coords.second) && grid[new_coords.first][new_coords.second] == FRESH)
                    rotten.push({new_coords.first, new_coords.second});
        
            rotten.pop();
        }

        ++time;

        num_elem = rotten.size();
    }
}

public:
    int orangesRotting(std::vector<std::vector<int>>& grid)
    {
        std::pair<int, std::queue<std::pair<int, int>>> initial_data = this->_initialData(grid);

        int fresh_counter = initial_data.first;

        std::cout << fresh_counter;
        std::queue<std::pair<int, int>> rotten_queue = initial_data.second;
        int time = 0;

        if(!fresh_counter && rotten_queue.empty())
            return 0;

        if(rotten_queue.empty())
            return -1;

        if(!fresh_counter)
            return 0;

        this->_expand(grid, rotten_queue, fresh_counter, time);

        if(fresh_counter)
            return -1;
        
        return time;
    }
};
