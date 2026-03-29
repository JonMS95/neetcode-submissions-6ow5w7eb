class Solution {
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;

public:
    bool searchMatrix(mat_int& matrix, int target)
    {
        const int num_of_rows = static_cast<int>(matrix.size());
        const int num_of_cols = static_cast<int>(matrix[0].size());

        int l = 0;
        int r = (num_of_rows * num_of_cols) - 1;

        int m, row, col;

        while(l <= r)
        {
            m = l + (r - l) / 2;

            row = m / num_of_cols;
            col = m % num_of_cols;

            if(matrix[row][col] == target)
                return true;
            
            if(target < matrix[row][col])
                r = m - 1;
            else
                l = m + 1;
        }

        return false;
    }
};
