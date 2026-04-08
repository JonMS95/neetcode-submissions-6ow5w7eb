class Solution {
private:
    int _getVectorSum(std::vector<int>& nums)
    {
        int ret = 0;

        for(int n : nums)
            ret += n;
        
        return ret;
    }

    inline int _makeKeyFromInts(const int a, const int b)
    {
        return ((a << 16) | b);
    }

    bool _dfs(const std::vector<int>& nums, std::unordered_map<int, int>& known, const int target, const int idx = 0)
    {
        int key = _makeKeyFromInts(target, idx);

        if(known.count(key))
            return known[key];

        bool ret;

        if(idx >= static_cast<int>(nums.size()) || target < 0)
            ret = false;
        else if(!target)
            ret = true;
        else
            ret = _dfs(nums, known, target, idx + 1) || _dfs(nums, known, target - nums[idx], idx + 1);
    
        known[key] = ret;
        return ret;
    }

public:
    bool canPartition(std::vector<int>& nums)
    {
        const int sum = _getVectorSum(nums);

        if(sum % 2 || !sum)
            return false;
        
        std::unordered_map<int, int> known;

        return _dfs(nums, known, sum / 2);
    }
};
