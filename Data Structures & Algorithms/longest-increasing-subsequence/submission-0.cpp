class Solution {
private:
    int _lengthOfLIS(std::vector<int>& nums, const int cur_idx = -1)
    {
        int max = 0;
        int cur;

        for(int i = cur_idx + 1; i < static_cast<int>(nums.size()); i++)
        {
            if(cur_idx < 0 || nums[i] > nums[cur_idx])
            {
                cur = this->_lengthOfLIS(nums, i);

                if(cur > max)
                    max = cur;
            }
        }

        return 1 + max;
    }

public:
    int lengthOfLIS(std::vector<int>& nums)
    {
        return this->_lengthOfLIS(nums) - 1;
    }
};
