class Solution
{
    using vec_int   = std::vector<int>;
    using mat_int   = std::vector<vec_int>;
    using u_map_int = std::unordered_map<int, int>;
    using coords    = std::pair<int, int>;

    inline bool _isCellValid(const mat_int& mat, const int row, const int col)
    {
        return  row >= 0 && row < static_cast<int>(mat.size())      &&
                col >= 0 && col < static_cast<int>(mat[0].size())   &&
                !mat[row][col];
    }

    inline int _makeKeyFromCoords(const int row, const int col)
    {
        return ((row << 8) | col);
    }

    int _getUniquePaths(const mat_int& grid, u_map_int& known_paths, const int row = 0, const int col = 0)
    {
        if(known_paths.count(this->_makeKeyFromCoords(row, col)))
            return known_paths[this->_makeKeyFromCoords(row, col)];

        int ret;

        if(!this->_isCellValid(grid, row, col))
            ret = 0;
        else if(row == static_cast<int>(grid.size() - 1) && col == static_cast<int>(grid[0].size() - 1))
            ret = 1;
        else
            ret = (this->_getUniquePaths(grid, known_paths, row + 1, col) + this->_getUniquePaths(grid, known_paths, row, col + 1));
    
        known_paths[this->_makeKeyFromCoords(row, col)] = ret;

        return ret;
    }

public:
    int uniquePathsWithObstacles(mat_int& obstacleGrid)
    {
        u_map_int known_paths;

        return this->_getUniquePaths(obstacleGrid, known_paths);
    }
};