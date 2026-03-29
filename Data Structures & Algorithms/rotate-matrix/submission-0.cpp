class Solution {
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;

    /*
    Mirror the matrix horizontally (first row <-> last row, second row <-> the one before the last row...)
    Ex.:
    1 2 3    7 8 9
    4 5 6 -> 4 5 6
    7 8 9    1 2 3
    */
    void getMirroredMatrix(mat_int& mat)
    {
        const int num_of_rows = static_cast<int>(mat.size());

        for(int i = 0; i < (num_of_rows / 2); i++)
            std::swap(mat[i], mat[num_of_rows - i - 1]);
    }

    /*
    Make rows columns (rotating each row 90º clockwise).
    Ex.:
    1 2 3    1 4 7
    4 5 6 -> 2 5 8
    7 8 9    3 6 9
    */
    void trasposeMatrix(mat_int& mat)
    {
        const int num_of_rows = static_cast<int>(mat.size());
        const int num_of_cols = static_cast<int>(mat[0].size());

        for(int i = 0; i < (num_of_rows - 1); i++)
            for(int j = (i + 1); j < num_of_cols; j++)
                std::swap(mat[i][j], mat[j][i]);
    }

public:
    /*
    Mirror the matrix horizontally, then traspose it (or viceversa).
    
    Ex.:
    1 2 3    7 8 9    7 4 1
    4 5 6 -> 4 5 6 -> 8 5 2
    7 8 9    1 2 3    9 6 3
    */
    void rotate(mat_int& matrix)
    {
        this->getMirroredMatrix(matrix);
        this->trasposeMatrix(matrix);
    }
};
