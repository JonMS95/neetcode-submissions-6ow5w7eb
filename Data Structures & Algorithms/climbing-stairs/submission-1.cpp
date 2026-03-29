class Solution {
private:
    int _climbStairs(int n, std::unordered_map<int, int>& known)
    {
        if(n == 0)
            return 1;
        
        if(n < 0)
            return 0;

        if(!known.count(n))
            known[n] = this->_climbStairs(n - 1, known) + this->_climbStairs(n - 2, known);
        
        return known[n];
    }

public:
    int climbStairs(int n)
    {
        std::unordered_map<int, int> known;
        return this->_climbStairs(n, known);
    }
};
