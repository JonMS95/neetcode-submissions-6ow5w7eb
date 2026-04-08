class Solution {
private:
    inline int _makeKeyFromBoolAndInt(const bool b, const int x)
    {
        return (((b ? 1 : 0) << 16) | x);
    }

    int _dfs(const std::vector<int>& prices, std::unordered_map<int, int>& known, const bool own = false, int idx = 0)
    {
        int key = _makeKeyFromBoolAndInt(own, idx);
        if(known.count(key))
            return known[key];

        int ret = 0;

        if(idx >= static_cast<int>(prices.size()))
            ret = 0;
        else
            if(!own)
                ret = std::max(_dfs(prices, known, false, idx + 1), _dfs(prices, known, true, idx + 1) - prices[idx]);
            else
                ret = std::max(_dfs(prices, known, true, idx + 1), _dfs(prices, known, false, idx + 2) + prices[idx]);
    
        known[key] = ret;
        return ret;
    }

public:
    int maxProfit(std::vector<int>& prices)
    {
        std::unordered_map<int, int> known;
        return _dfs(prices, known);
    }
};
