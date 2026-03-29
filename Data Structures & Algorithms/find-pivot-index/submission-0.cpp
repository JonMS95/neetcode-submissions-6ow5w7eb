class Solution {
private:
    using vec_int = std::vector<int>;

public:
    int pivotIndex(std::vector<int>& nums) 
    {
        const int nums_size = static_cast<int>(nums.size());
        
        // left_sum[i] = sum(nums[0] ... nums[i - 1])
        // right_sum[i] = sum(nums[i + 1] ... nums[nums_size - 1])
        vec_int left_sum(nums_size);
        vec_int right_sum(nums_size);

        left_sum[0] = 0;
        right_sum[nums_size - 1] = 0;

        for(int i = 1; i < nums_size; i++)
            left_sum[i] = left_sum[i - 1] + nums[i - 1];
        
        for(int i = (nums_size - 2); i >= 0; i--)
            right_sum[i] = right_sum[i + 1] + nums[i + 1];

        for(int i = 0; i < nums_size; i++)
            if(left_sum[i] == right_sum[i])
                return i;
        
        return -1;
    }
};