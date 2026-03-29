class Solution {
private:
    void setZerosForRowAndColumn(vector<vector<int>>& mat, const int row, const int col)
    {
        for(int i = 0; i < mat.size(); i++)
            mat[i][col] = 0;
        
        for(int i = 0; i < mat[0].size(); i++)
            mat[row][i] = 0;
    }

public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<vector<int>> aux = matrix;

        for(int i = 0; i < aux.size(); i++)
            for(int j = 0; j < aux[0].size(); j++)
                if(!aux[i][j])
                    this->setZerosForRowAndColumn(matrix, i, j);
    }
};
