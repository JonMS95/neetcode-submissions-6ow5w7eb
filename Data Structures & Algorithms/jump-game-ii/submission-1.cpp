class Solution {
private:
    using vec_int = std::vector<int>;

    int _jump(vec_int& nums, const int idx = 0)
    {
        if(idx >= static_cast<int>(nums.size() - 1))
            return 0;
        
        int ret = INT_MAX;
        int cur;

        for(int i = nums[idx]; i > 0; i--)
        {
            cur = 1 + this->_jump(nums, idx + i);
            
            if(ret < 0 || cur > 0 && cur < ret)
                ret = cur;
        }

        return ret;
    }

public:
    int jump(vec_int& nums)
    {
        return this->_jump(nums);
    }
};
