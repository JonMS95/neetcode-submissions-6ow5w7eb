class Solution {
private:
    const char char_visited_ = '#';

    inline bool _areCoordsValid(std::vector<std::vector<char>>& board, const int row, const int col)
    {
        return ((row >= 0)                                  &&
                (row < static_cast<int>(board.size()))      &&
                (col >= 0)                                  &&
                (col < static_cast<int>(board[0].size()))   );
    }

    inline std::vector<std::pair<int, int>> _getNextCoords(const int row, const int col)
    {
        return {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
    }

    bool _backtrack(std::vector<std::vector<char>>& board, const int row, const int col, std::string& word)
    {
        // Check whether word size is already null.
        if(!word.size())
            return true;
        
        // Check whether coordinates are out of boundaries.
        if(!_areCoordsValid(board, row, col))
            return false;

        // Store the leading leter.
        char letter = word[0];

        // If the leading letter is not the one on the current coordinates, then return immediately.
        if(board[row][col] != letter)
            return false;

        // Erase the leading letter from word.
        word.erase(word.begin());

        // If word is already null, then return true immediately.
        if(!word.size())
            return true;
        
        // Otherwise, mark current cell as visited
        board[row][col] = char_visited_;

        // Traverse the grid towards adjacent valid coordinates.
        for(std::pair<int, int>& c : _getNextCoords(row, col))
            if(_backtrack(board, c.first, c.second, word))
                return true;

        // Set previous character again on the board.
        board[row][col] = letter;

        // Restore word (first letter must be grid letter again).
        word.insert(word.begin(), letter);

        return false;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        for(int r = 0; r < static_cast<int>(board.size()); r++)
            for(int c = 0; c < static_cast<int>(board[0].size()); c++)
                if(_backtrack(board, r, c, word))
                    return true;
        
        return false;
    }
};
