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

    int _getMaxChoice(std::vector<int>& nums)
    {
        int ret = 0;
        int cur;
        std::unordered_map<int, int> known;

        for(int i = 0; i < static_cast<int>(nums.size()); i++)
            if((cur = this->_dfs(nums, known, i)) > ret)
                ret = cur;
        
        return ret;
    }

public:
    int rob(std::vector<int>& nums)
    {
        // If nums' size is one, we should not remove any element, just return the single element within.
        if(nums.size() == 1)
            return nums[0];

        // All but first/last.
        std::vector<int> abl(nums.begin(), nums.end() - 1);
        std::vector<int> abf(nums.begin() + 1, nums.end());

        return std::max(this->_getMaxChoice(abl), this->_getMaxChoice(abf));
    }
};
