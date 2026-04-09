class Solution {
private:
    using table         = std::vector<std::string>;
    using table_set     = std::vector<table>;
    using known_set     = std::unordered_set<int>;
    using known_sets    = std::vector<known_set>;

    typedef enum
    {
        COLS        = 0,
        SDIAG       = 1, // Identificable as row - col
        IDIAG       = 2, // Identificable as row + col
        TOTAL_IDCS  = 3,
    } VISITED_INDEX;

    inline bool _validCell(const known_sets& known, const int row, const int col)
    {
        if( known[COLS].count(col)          ||
            known[SDIAG].count(row - col)   ||
            known[IDIAG].count(row + col)   )
            return false;
        else
            return true;
    }

    void _saveKnownCoords(known_sets& known, const int row, const int col)
    {
        known[COLS].insert(col);
        known[SDIAG].insert(row - col);
        known[IDIAG].insert(row + col);
    }

    void _eraseKnownCoords(known_sets& known, const int row, const int col)
    {
        known[COLS].erase(col);
        known[SDIAG].erase(row - col);
        known[IDIAG].erase(row + col);
    }

    void _backtrack(table& t, table_set& ret, known_sets& known, int remaining)
    {
        if(!remaining)
        {
            ret.emplace_back(t);
            return;
        }

        const int t_size = static_cast<int>(t.size());

        // Since the solution forces us to have just a single queen per row, then we can
        // force the current row to have a queen, then choose a column if any of them is suitable.
        int row = t_size - remaining;

        for(int col = 0; col < t_size; col++)
        {
            if(!_validCell(known, row, col))
                continue;
            
            _saveKnownCoords(known, row, col);
            t[row][col] = 'Q';
            _backtrack(t, ret, known, remaining - 1);
            t[row][col] = '.';
            _eraseKnownCoords(known, row, col);
        }
    }

public:
    table_set solveNQueens(int n)
    {
        known_sets known(TOTAL_IDCS);
    
        table t(n, std::string(n, '.'));
        table_set ret;

        _backtrack(t, ret, known, n);

        return ret;
    }
};
