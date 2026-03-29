class Solution {
private:
    int dp(int row, int col, const int m, const int n, std::unordered_map<int, int>& known)
    {
        const int key = row * 1000 + col;

        if(known.count(key))
            return known[key];

        // If cell is not even valid, just return 0 (no paths through target cell).
        if(row < 0 || row >= m || col < 0 || col >= n)
            known[key] = 0;
        // If current coordinates equal the ones to where target belong, then return 1.
        else if(row == (m - 1) && col == (n - 1))
            known[key] = 1;
        // Otherwise, return the sum of paths from current coords + 1 row and current cords + 1 col.
        else
            known[key] = (this->dp(row + 1, col, m, n, known) + this->dp(row, col + 1, m, n, known));
    
        return known[key];
    }

public:
    int uniquePaths(int m, int n)
    {
        std::unordered_map<int, int> known;
        return this->dp(0, 0, m, n, known);
    }
};
