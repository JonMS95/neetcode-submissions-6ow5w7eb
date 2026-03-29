class Solution {
private:
    int _dp(const std::vector<int>& nums, const int target, std::unordered_map<int, int>& known, const int idx = 0)
    {
        const int key = ((target << 16) | idx);

        if(known.count(key))
            return known[key];

        if(idx == static_cast<int>(nums.size()))
            if(target == 0)
                return 1;
            else
                return 0;

        int ret =   this->_dp(nums, target + nums[idx], known, idx + 1) +
                    this->_dp(nums, target - nums[idx], known, idx + 1);

        known[key] = ret;

        return ret;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> known;
        return this->_dp(nums, target, known);
    }
};
