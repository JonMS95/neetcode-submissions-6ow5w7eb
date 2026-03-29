#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        const int row_num   = static_cast<int>(matrix.size());
        const int col_num   = static_cast<int>(matrix[0].size());
        const int mat_elems = row_num * col_num;

        // Initialize four corners
        int ulr = 0, ulc = 0;             // upper-left
        int urr = 0, urc = col_num - 1;   // upper-right
        int drr = row_num - 1, drc = col_num - 1; // down-right
        int dlr = row_num - 1, dlc = 0;   // down-left
    
        vector<int> ret;

        // Handle single row
        if(row_num == 1) {
            for(int c = 0; c < col_num; ++c)
                ret.push_back(matrix[0][c]);
            return ret;
        }

        // Handle single column
        if(col_num == 1) {
            for(int r = 0; r < row_num; ++r)
                ret.push_back(matrix[r][0]);
            return ret;
        }

        // Spiral traversal
        while(ret.size() < mat_elems)
        {
            // ul -> ur (top row)
            for(int i = ulc; i <= urc && ret.size() < mat_elems; ++i)
                ret.push_back(matrix[ulr][i]);
            
            // ur -> dr (right column)
            for(int i = urr + 1; i <= drr && ret.size() < mat_elems; ++i)
                ret.push_back(matrix[i][urc]);
            
            // dr -> dl (bottom row, right to left)
            for(int i = drc - 1; i >= dlc && ret.size() < mat_elems; --i)
                ret.push_back(matrix[drr][i]);
            
            // dl -> ul (left column, bottom to top)
            for(int i = dlr - 1; i > ulr && ret.size() < mat_elems; --i)
                ret.push_back(matrix[i][dlc]);
            
            // Move corners inward for next layer
            ++ulr; ++ulc;
            ++urr; --urc;
            --drr; --drc;
            --dlr; ++dlc;
        }

        return ret;
    }
};