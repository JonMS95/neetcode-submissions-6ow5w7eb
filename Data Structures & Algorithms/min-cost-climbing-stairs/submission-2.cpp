class Solution {
private:
    int _dfs(std::vector<int>& cost, std::unordered_map<int, int>& known_values, const int idx = -1)
    {
        if(known_values.count(idx))
            return known_values[idx];

        int ret;
        
        const int cost_size = static_cast<int>(cost.size());

        if(idx == cost_size)
        {
            ret = 0;
        }
        else
        {
            int cur = 0;

            if(idx >= 0)
                cur = cost[idx];

            if(idx == cost_size - 1)
                ret = cur + this->_dfs(cost, known_values, idx + 1);
            else
                ret = cur + std::min(this->_dfs(cost, known_values, idx + 1), this->_dfs(cost, known_values, idx + 2));
        }

        known_values[idx] = ret;
        
        return ret;
    }

public:
    int minCostClimbingStairs(std::vector<int>& cost)
    {
        std::unordered_map<int, int> known_values;
        return this->_dfs(cost, known_values);
    }
};
