class Solution
{
private:
    std::pair<int, int> _find(  const std::pair<int, int> coords                        ,
                                std::vector<std::vector<std::pair<int, int>>>& parents  )
    {
        std::pair<int, int> cur = parents[coords.first][coords.second];

        if(coords != cur)
            parents[coords.first][coords.second] = _find(cur, parents);
        
        return parents[coords.first][coords.second];
    }

    void _union(const std::pair<int, int> coords_a                      ,
                const std::pair<int, int> coords_b                      ,
                std::vector<std::vector<std::pair<int, int>>>& parents  )
    {
        std::pair<int, int> root_a = _find(coords_a, parents);
        std::pair<int, int> root_b = _find(coords_b, parents);

        if(root_a != root_b)
            parents[root_b.first][root_b.second] = root_a;
    }

    void _compress(std::vector<std::vector<std::pair<int, int>>>& parents)
    {
        for(int i = 0; i < static_cast<int>(parents.size()); i++)
            for(int j = 0; j < static_cast<int>(parents[0].size()); j++)
                parents[i][j] = _find({i, j}, parents);
    }

    inline int _getKeyFromCoords(const std::pair<int, int> coords)
    {
        return ((coords.first << 16) | coords.second);
    }

    int _getDifferentParents(   const std::vector<std::vector<char>>& grid                  ,
                                const std::vector<std::vector<std::pair<int, int>>>& parents)
    {
        std::unordered_set<int> diff_parents;

        for(int i = 0; i < static_cast<int>(parents.size()); i++)
            for(int j = 0; j < static_cast<int>(parents[0].size()); j++)
                if(grid[i][j] == '1')
                    diff_parents.insert(_getKeyFromCoords(parents[i][j]));
    
        return static_cast<int>(diff_parents.size());
    }

public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        const int num_of_rows = static_cast<int>(grid.size());
        const int num_of_cols = static_cast<int>(grid[0].size());

        std::vector<std::vector<std::pair<int, int>>> parents(num_of_rows, std::vector<std::pair<int, int>>(num_of_cols));

        for(int i = 0; i < num_of_rows; i++)
            for(int j = 0; j < num_of_cols; j++)
                parents[i][j] = {i, j};
        
        for(int row = 0; row < num_of_rows; row++)
        {
            for(int col = 0; col < num_of_cols; col++)
            {
                if(grid[row][col] == '0')
                    continue;

                if(row > 0 && grid[row - 1][col] == '1')
                    _union({row, col}, {row - 1, col}, parents);
                
                if(col > 0 && grid[row][col - 1] == '1')
                    _union({row, col}, {row, col - 1}, parents);
            }
        }

        _compress(parents);

        return _getDifferentParents(grid, parents);
    }
};
