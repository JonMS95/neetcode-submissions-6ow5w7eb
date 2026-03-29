class Solution {
private:
    int dp(int row, int col, const int m, const int n)
    {
        // If cell is not even valid, just return 0 (no paths through target cell).
        if(row < 0 || row >= m || col < 0 || col >= n)
            return 0;
        
        // If current coordinates equal the ones to where target belong, then return 1.
        if(row == (m - 1) && col == (n - 1))
            return 1;
        
        // Otherwise, return the sum of paths from current coords + 1 row and current cords + 1 col.
        return (this->dp(row + 1, col, m, n) + this->dp(row, col + 1, m, n));
    }

public:
    int uniquePaths(int m, int n)
    {
        return this->dp(0, 0, m, n);
    }
};
