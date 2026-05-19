class Solution {
private:
    void _backtrack(const std::vector<int>& nums, const int target, std::vector<int>& cur, std::vector<std::vector<int>>& ret, const int start = 0)
    {
        if(target < 0)
            return;

        if(!target)
        {
            ret.emplace_back(cur);
            return;
        }

        for(int i = start; i < static_cast<int>(nums.size()); i++)
        {
            cur.emplace_back(nums[i]);
        
            _backtrack(nums, target - nums[i], cur, ret, i);

            cur.pop_back();
        }
    }

public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target)
    {
        std::vector<int> cur;
        std::vector<std::vector<int>> ret;
    
        _backtrack(nums, target, cur, ret);

        return ret;
    }
};
