class Solution {
private:
    void saveZerosForRowAndColumn(  std::vector<bool>& rows ,
                                    std::vector<bool>& cols ,
                                    const int row           ,
                                    const int col           )
    {
        rows[row] = true;
        cols[col] = true;
    }

    void eraseSingleRow(vector<vector<int>>& matrix, const int row)
    {
        for(int i = 0; i < matrix[0].size(); i++)
            matrix[row][i] = 0;
    }

    void eraseSingleCol(vector<vector<int>>& matrix, const int col)
    {
        for(int i = 0; i < matrix.size(); i++)
            matrix[i][col] = 0;
    }

    void eraseRows(vector<vector<int>>& matrix, std::vector<bool>& rows)
    {
        for(int i = 0; i < rows.size(); i++)
            if(rows[i])
                eraseSingleRow(matrix, i);
    }

    void eraseCols(vector<vector<int>>& matrix, std::vector<bool>& cols)
    {
        for(int i = 0; i < cols.size(); i++)
            if(cols[i])
                eraseSingleCol(matrix, i);
    }

public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        // Couple of vector below will be used to save the rows and cols to be erased afterwards.
        std::vector<bool> rows_to_erase(matrix.size(), false);
        std::vector<bool> cols_to_erase(matrix[0].size(), false);

        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                if(!matrix[i][j])
                    this->saveZerosForRowAndColumn(rows_to_erase, cols_to_erase, i, j);
        
        this->eraseRows(matrix, rows_to_erase);
        this->eraseCols(matrix, cols_to_erase);
    }
};
