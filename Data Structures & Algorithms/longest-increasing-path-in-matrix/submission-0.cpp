class Solution {
private:
    using vec_int   = std::vector<int>;
    using mat_int   = std::vector<vec_int>;
    using umap_int  = std::unordered_map<int, int>;
    using coord     = std::pair<int, int>;
    using vec_coord = std::vector<coord>;

    inline bool _isCellValid(const mat_int& matrix, const int row, const int col)
    {
        return row >= 0 && row < static_cast<int>(matrix.size()) && col >= 0 && col < static_cast<int>(matrix[0].size());
    }

    inline vec_coord _getNextCells(const int row, const int col)
    {
        return {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
    }

    inline int _getKeyFromCoords(const int row, const int col)
    {
        return ((row << 16) | col);
    }

    int _traversal(const mat_int& matrix, umap_int& known_cells, const int row, const int col)
    {
        if(!this->_isCellValid(matrix, row, col))
            return 0;
            // throw std::runtime_error("Current coordinates are out of bounds");
        
        int key = this->_getKeyFromCoords(row, col);

        if(known_cells.count(key))
            return known_cells[key];
        
        known_cells[key] = -1;

        int ret = 0;
        int cur;

        for(coord c : this->_getNextCells(row, col))
        {
            if(!this->_isCellValid(matrix, c.first, c.second))
                continue;
            
            if(matrix[c.first][c.second] > matrix[row][col])
                if((cur = this->_traversal(matrix, known_cells, c.first, c.second)) > ret)
                    ret = cur;
        }

        ++ret;

        known_cells[key] = ret;

        return ret;
    }

public:
    int longestIncreasingPath(mat_int& matrix)
    {
        umap_int known_cells;
        int ret = 0;
        int cur;
        
        for(int i = 0; i < static_cast<int>(matrix.size()); i++)
            for(int j = 0; j < static_cast<int>(matrix[0].size()); j++)
                if((cur = this->_traversal(matrix, known_cells, i, j)) > ret)
                    ret = cur;
        
        return ret;
    }
};
