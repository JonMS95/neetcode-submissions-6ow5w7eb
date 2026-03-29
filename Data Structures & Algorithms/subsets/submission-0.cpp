class Solution
{
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;

    void _backtrack(vec_int& nums, mat_int& ret, vec_int& cur, const int start = 0)
    {        
        ret.emplace_back(cur);
        
        for(int i = start; i < static_cast<int>(nums.size()); i++)
        {
            cur.emplace_back(nums[i]);
            this->_backtrack(nums, ret, cur, i + 1);
            cur.pop_back();
        }
    }

public:
    mat_int subsets(vec_int& nums)
    {
        mat_int ret;
        vec_int cur;
        this->_backtrack(nums, ret, cur);
        return ret;
    }
};
