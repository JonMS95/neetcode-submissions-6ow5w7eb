class Solution {
private:
    std::vector<int> _getRotatedVector(const std::vector<int>& nums, const int k)
    {
        const int nums_size = static_cast<int>(nums.size());
        std::vector<int> ret(nums_size);

        for(int i = 0; i < nums_size; i++)
            ret[i] = nums[(i - k + nums_size) % nums_size];
        
        return ret;
    }

public:
    void rotate(std::vector<int>& nums, int k)
    {
        nums = this->_getRotatedVector(nums, k % nums.size());
    }
};