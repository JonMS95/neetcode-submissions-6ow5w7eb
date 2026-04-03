class Solution
{
public:
    std::vector<int> getConcatenation(std::vector<int>& nums)
    {
        const int nums_size = static_cast<int>(nums.size());

        std::vector<int> ret(nums_size * 2);

        for(int i = 0; i < 2; i++)
            for(int j = nums_size * i; j < nums_size * (i + 1); j++)
                ret[j] = nums[j - nums_size * i];
        
        return ret;
    }
};