class Solution {
private:
    using vec_int = std::vector<int>;
    using known_map = std::unordered_map<int, int>;

    int _dfs(vec_int& nums, known_map& known_max_values, const int max_idx)
    {
        int max = 0;
        int cur;

        if(known_max_values.count(max_idx))
            return known_max_values[max_idx];

        for(int i = max_idx ; i >= 0; i--)
            if(max < (cur = nums[i] + this->_dfs(nums, known_max_values, i - 2)))
                max = cur;

        known_max_values[max_idx] = max;

        return max;
    }

public:
    int rob(std::vector<int>& nums)
    {
        known_map known_max_values;

        return this->_dfs(nums, known_max_values, static_cast<int>(nums.size() - 1));
    }
};
