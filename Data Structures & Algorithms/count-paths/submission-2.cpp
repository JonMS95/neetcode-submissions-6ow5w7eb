class Solution {
private:
    inline bool _isCellValid(const int r, const int c, const int m, const int n)
    {
        return ((r >= 0) && (r < m) && (c >= 0) && (c < n));
    }

    inline int _makeKeyFromCoords(const int r, const int c)
    {
        return ((r << 16) | c);
    }

    // A tile has at most two possible next destinations: down, right.
    // If tile's coordinates are equal to bottom-right, then there's no possible next tile.
    // Also, if out of boundaries, next right or next down tile may not be accessed.
    int _dp(const int r, const int c, const int m, const int n, std::unordered_map<int, int>& known)
    {
        const int key = _makeKeyFromCoords(r, c);
        
        if(known.count(key))
            return known[key];

        int ret;

        if(!_isCellValid(r, c, m, n))
            ret = 0;
        else if(r == (m - 1) && c == (n - 1))
            ret = 1;
        else
            ret = _dp(r + 1, c, m, n, known) + _dp(r, c + 1, m, n, known);

        known[key] = ret;

        return ret;
    }

public:
    int uniquePaths(int m, int n)
    {
        std::unordered_map<int, int> known;

        return _dp(0, 0, m, n, known);
    }
};
