class Solution {
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;

public:
    mat_int transpose(mat_int& matrix)
    {
        const int num_of_rows = static_cast<int>(matrix.size());
        const int num_of_cols = static_cast<int>(matrix[0].size());

        mat_int ret(num_of_cols, vec_int(num_of_rows));

        for(int i = 0; i < num_of_rows; i++)
            for(int j = 0; j < num_of_cols; j++)
                ret[j][i] = matrix[i][j];
    
        return ret;
    }
};