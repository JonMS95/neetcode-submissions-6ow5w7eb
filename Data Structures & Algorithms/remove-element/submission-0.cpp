class Solution {
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        const int nums_size = static_cast<int>(nums.size());
    
        for(int i = (nums_size - 1); i >= 0; i--)
            if(nums[i] == val)
                nums.erase(nums.begin() + i);
        
        return static_cast<int>(nums.size());
    }
};