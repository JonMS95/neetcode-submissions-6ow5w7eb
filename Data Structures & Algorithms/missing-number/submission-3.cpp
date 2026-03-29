class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        const int nums_size = static_cast<int>(nums.size());
        
        int fast_sum = (nums_size * (nums_size + 1)) / 2;

        int slow_sum = 0;

        for(int n : nums)
            slow_sum += n;
        
        return (fast_sum - slow_sum);
    }
};
