class Solution {
private:
    using vec_chr = std::vector<char>;
    using mat_chr = std::vector<vec_chr>;
    using vec_set_chr = std::vector<std::unordered_set<char>>;

public:
    bool isValidSudoku(mat_chr& board)
    {
        const int num_of_rows = 9;
        const int num_of_cols = 9;

        const int square_side = 3;

        vec_set_chr squares(9);
        vec_set_chr rows(9);
        vec_set_chr columns(9);

        for(int i = 0; i < num_of_rows; i++)
        {
            for(int j = 0; j < num_of_cols; j++)
            {
                if(board[i][j] == '.')
                    continue;

                if(squares[(i / 3) * 3 + j / 3].count(board[i][j]))
                    return false;
                else
                    squares[(i / 3) * 3 + j / 3].insert(board[i][j]);

                if(rows[i].count(board[i][j]))
                    return false;
                else
                    rows[i].insert(board[i][j]);
                
                if(columns[j].count(board[i][j]))
                    return false;
                else
                    columns[j].insert(board[i][j]);
            }
        }

        return true;
    }
};
