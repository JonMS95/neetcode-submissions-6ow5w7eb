class Solution {
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;

    void _dfs(const vec_int& nums, vec_int& cur, mat_int& ret, const int idx = 0)
    {
        const int nums_size = static_cast<int>(nums.size());

        ret.emplace_back(cur);

        if(idx >= nums_size)
            return;

        for(int i = idx; i < nums_size; i++)
        {
            if(i > idx && nums[i] == nums[i - 1])
                continue;
            
            cur.emplace_back(nums[i]);
            _dfs(nums, cur, ret, i + 1);
            cur.pop_back();
        }
    }

public:
    mat_int subsetsWithDup(vec_int& nums)
    {
        std::sort(nums.begin(), nums.end());

        mat_int ret;
        vec_int cur;

        _dfs(nums, cur, ret);

        return ret;
    }
};
