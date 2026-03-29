class Solution {
private:    
    using vec_int = std::vector<int>;

    bool _canJump(vec_int& nums, const int idx = 0)
    {
        if(idx >= static_cast<int>(nums.size() - 1))
            return true;
        
        for(int i = nums[idx]; i > 0; i--)
            if(this->_canJump(nums, idx + i))
                return true;
        
        return false;
    }

public:
    bool canJump(vec_int& nums)
    {
        return this->_canJump(nums);
    }
};
