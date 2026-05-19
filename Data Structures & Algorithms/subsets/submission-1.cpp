class Solution {
private:
    void _backtrack(const std::vector<int>& nums, std::vector<int>& cur, const int start, std::vector<std::vector<int>>& ret)
    {
        ret.emplace_back(cur);

        const int nums_size = static_cast<int>(nums.size());

        if(start == nums_size)
            return;

        for(int i = start; i < nums_size; i++)
        {
            cur.emplace_back(nums[i]);
            _backtrack(nums, cur, i + 1, ret);
            cur.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<int> cur;
        std::vector<std::vector<int>> ret;
        
        _backtrack(nums, cur, 0, ret);

        return ret;
    }
};
