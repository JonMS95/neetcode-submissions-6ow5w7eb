class Solution
{
private:
    int _dfs(const std::vector<int>& nums, std::unordered_map<int, int>& known, const int idx = 0)
    {
        if(known.count(idx))
            return known[idx];
        
        int cur, ret;
        int max = 0;

        for(int i = idx + 2; i < static_cast<int>(nums.size()); i++)
            if((cur = this->_dfs(nums, known, i)) > max)
                max = cur;
        
        ret = max + nums[idx];

        known[idx] = ret;

        return ret;
    }

public:
    int rob(std::vector<int>& nums)
    {
        int ret = 0;
        int cur;
        std::unordered_map<int, int> known;

        for(int i = 0; i < static_cast<int>(nums.size()); i++)
            if((cur = this->_dfs(nums, known, i)) > ret)
                ret = cur;
        
        return ret;
    }
};
