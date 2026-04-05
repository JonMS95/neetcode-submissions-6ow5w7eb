class Solution
{
private:
    using vec_chr = std::vector<char>;
    using mat_chr = std::vector<vec_chr>;
    using set_int = std::unordered_set<int>;
    using par_int = std::pair<int, int>;
    using q_par   = std::queue<par_int>;
    using vec_par = std::vector<par_int>;

    inline int _makeKeyFromCoords(int row, int col)
    {
        return (row << 16) | col;
    }

    inline bool _isCellValid(const mat_chr& grid, int row, int col)
    {
        return row >= 0 && row < (int)grid.size() &&
               col >= 0 && col < (int)grid[0].size();
    }

    inline vec_par _getSurroundingCoords(int row, int col)
    {
        return {{row + 1, col}, {row - 1, col}, {row, col + 1}, {row, col - 1}};
    }

    // Collect all border 'O's
    set_int _getBorderCircles(const mat_chr& grid)
    {
        set_int ret;
        int rows = grid.size();
        int cols = grid[0].size();

        // Top & Bottom
        for (int j = 0; j < cols; j++)
        {
            if (grid[0][j] == 'O')
                ret.insert(this->_makeKeyFromCoords(0, j));

            if (grid[rows - 1][j] == 'O')
                ret.insert(this->_makeKeyFromCoords(rows - 1, j));
        }

        // Left & Right
        for (int i = 0; i < rows; i++)
        {
            if (grid[i][0] == 'O')
                ret.insert(this->_makeKeyFromCoords(i, 0));

            if (grid[i][cols - 1] == 'O')
                ret.insert(this->_makeKeyFromCoords(i, cols - 1));
        }

        return ret;
    }

    // BFS from border 'O's
    set_int _bfs(const mat_chr& grid)
    {
        set_int visited = this->_getBorderCircles(grid);
        q_par q;

        // Initialize queue
        for (int key : visited)
        {
            int r = key >> 16;
            int c = key & 0xFFFF;
            q.push({r, c});
        }

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (const auto& [nr, nc] : this->_getSurroundingCoords(r, c))
            {
                if (!this->_isCellValid(grid, nr, nc))
                    continue;

                if (grid[nr][nc] == 'X')
                    continue;

                int key = this->_makeKeyFromCoords(nr, nc);

                if (!visited.count(key))
                {
                    visited.insert(key);
                    q.push({nr, nc});
                }
            }
        }

        return visited;
    }

public:
    void solve(mat_chr& board)
    {
        if(board.empty())
            return;

        set_int safe = this->_bfs(board);

        int rows = static_cast<int>(board.size());
        int cols = static_cast<int>(board[0].size());

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                if(board[i][j] == 'O' && !safe.count(_makeKeyFromCoords(i, j)))
                    board[i][j] = 'X';
    }
};