class Solution {
private:
    inline int _makeKey(const int h, const int l)
    {
        return ((h << 16) | l);
    }

    int _dp(const std::vector<int>& nums, const int target, std::unordered_map<int, int>& known, const int idx = 0)
    {
        const int key = this->_makeKey(target, idx);

        if(known.count(key))
            return known[key];

        if(idx == static_cast<int>(nums.size()))
            if(target == 0)
                return 1;
            else
                return 0;

        // "p" for plus, "m" for minus.
        int p = this->_dp(nums, target + nums[idx], known, idx + 1);
        int m = this->_dp(nums, target - nums[idx], known, idx + 1);
        int ret = (p + m);

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
