class Solution {
private:
    using mat_char = std::vector<std::vector<char>>;
    using str = std::string;

    bool areCoordsValid(mat_char& board, const int row, const int col)
    {
        const int board_rows = static_cast<int>(board.size());
        const int board_cols = static_cast<int>(board[0].size());

        return (row >= 0 && row < board_rows && col >= 0 && col < board_cols);
    }

    bool traverseBoard( mat_char& board         ,
                        const int row           ,
                        const int col           ,
                        const str& word         ,
                        const int word_idx = 0  )
    {
        // Check first whether provided coordinates are valid.
        if(!this->areCoordsValid(board, row, col))
            return false;

        // Check whether it has been already visited or not.
        if(board[row][col] == '0')
            return false;

        // Then, check whether provided coordinates match current word index letter.
        if(board[row][col] != word[word_idx])
            return false;
        
        // Now that we are sure current index is valid, have we reached the end?
        if(word_idx == static_cast<int>(word.size() - 1))
            return true;
        
        const char cell_value = board[row][col];

        board[row][col] = '0'; // Mark it as visited.
        
        if(this->traverseBoard(board, row - 1, col, word, word_idx + 1))
            return true;
        
        if(this->traverseBoard(board, row + 1, col, word, word_idx + 1))
            return true;
        
        if(this->traverseBoard(board, row, col - 1, word, word_idx + 1))
            return true;

        if(this->traverseBoard(board, row, col + 1, word, word_idx + 1))
            return true;
        
        board[row][col] = cell_value; // Set it back to its original value before leaving.

        return false;
    }

public:
    bool exist(mat_char& board, str word)
    {
        for(int i = 0; i < static_cast<int>(board.size()); i++)
            for(int j = 0; j < static_cast<int>(board[0].size()); j++)
                if(board[i][j] == word[0] && this->traverseBoard(board, i, j, word))
                    return true;

        return false;
    }
};
