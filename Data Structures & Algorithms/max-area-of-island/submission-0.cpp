class Solution {
private:
    using vec_int       = std::vector<int>;
    using mat_int       = std::vector<vec_int>;
    using coords        = std::pair<int, int>;
    using vec_coords    = std::vector<coords>;

    typedef enum
    {
        EXPLORED_CELL       = -1,
        SEA_CELL            = 0 ,
        UNKNOWN_LAND_CELL   = 1 ,
    } CELL_ID;

    inline bool _isCellValid(mat_int& grid, const int row, const int col)
    {
        return (row >= 0 && row < static_cast<int>(grid.size())     &&
                col >= 0 && col < static_cast<int>(grid[0].size())  );
    }

    inline bool _isNewLandCell(mat_int& grid, const int row, const int col)
    {
        return this->_isCellValid(grid, row, col) && (grid[row][col] == UNKNOWN_LAND_CELL);
    }

    inline vec_coords _getAdjacentCellCoords(mat_int& grid, const int row, const int col)
    {
        return {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
    }

    int _getIslandArea(mat_int& grid, const int row, const int col)
    {
        // Check whether current cell is valid and non-explored piece of land.
        if(!this->_isNewLandCell(grid, row, col))
            return 0;

        // Mark it as explored if conditions above have been met (cell is valid
        // and it's an unknown piece of land).
        grid[row][col] = EXPLORED_CELL;

        // Since current cell represents a piece of land, its area has to be added.
        // Do the same for adjacent cells.
        int ret = 1;

        for(coords c : this->_getAdjacentCellCoords(grid, row, col))
            ret += this->_getIslandArea(grid, c.first, c.second);
        
        return ret;
    }

public:
    int maxAreaOfIsland(mat_int& grid)
    {
        int ret = 0;
        int cur;

        for(int i = 0; i < static_cast<int>(grid.size()); i++)
            for(int j = 0; j < static_cast<int>(grid[0].size()); j++)
                if((cur = this->_getIslandArea(grid, i, j)) > ret)
                    ret = cur;


        return ret;
    }
};
