class Solution {
public:
    int minSubArrayLen(int target, std::vector<int>& nums)
    {
        int fast = 0;
        int slow = 0;
        int sum  = 0;
        int ret  = -1;

        const int nums_size = static_cast<int>(nums.size());

        while(fast < nums_size)
        {
            // Increment sum with current fast-pointed number.
            sum += nums[fast];

            // If sum has not reached its target yet, then keep incrementing fast index.
            if(sum < target)
            {
                ++fast;
            }
            // Otherwise, keep incrementing slow (subtract slow-pointed-number in the
            // meanwhile) and keep checking new ret values (go for min value).
            else
            {
                while(sum >= target)
                {
                    if(ret < 0 || ret > (fast - slow + 1))
                        ret = fast - slow + 1;
                    
                    sum -= nums[slow++];
                }

                ++fast;
            }
        }

        if(ret < 0)
            ret = 0;

        return ret;
    }
};