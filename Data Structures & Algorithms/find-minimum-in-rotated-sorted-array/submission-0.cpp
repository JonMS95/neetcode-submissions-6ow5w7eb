/*
3 possible scenarios, depending on how nums[l], nums[m] == nums[(l + r)/2] and nums[r]
are related to each other:
    ·Not rotated (or rotated 0 positions in either direction): nums[l] < nums[m] < nums[r]
        0 1 2 3 4 5 6 -> m = r - 1
    ·Rotated in such way that the minimum is found before m: nums[l] > nums[m] < nums[r]
        5 6 0 1 2 3 4 -> m = r - 1
    ·Rotated in such way that the minimum is found after m: nums[l] < nums[m] > nums[r]
        3 4 5 6 0 1 2 -> m = l + 1
    
    However, it might happen that nums[m] < nums[r] just because nums[m] is the minimum
    itself. Hence, m itself should be kept for the following halving: m = r.
    
    As we may have already noticed, left/lower half is selected in first two cases, since
    minimum value is found bvefore m for both of them.
*/

class Solution
{
public:
    int findMin(std::vector<int>& nums)
    {
        int l = 0;
        int r = static_cast<int>(nums.size() - 1);
        int m;

        while(l < r)
        {        
            m = (l + r) / 2;

            if(nums[m] < nums[r])
                r = m;
            else
                l = m + 1;
        }

        return nums[l];
    }
};
