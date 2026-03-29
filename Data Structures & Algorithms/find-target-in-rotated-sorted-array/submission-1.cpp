class Solution {
public:
    /*
    [4,5,6,7,8,9,0,1,2,3], target = 6 (rotated 6 times rightwards).

    l = 0, r = 9, m = 4

    If target was 1, then choosing right interval would be best.
    If it's 6 (as in the example) then left interval should be chosen next.
    Obviously, if nums[m] == target, then m should be returned.
    Also, if l > r, then -1 should be returned.
    
    Question is: is target between nums[l] and nums[m] or nums[m] and nums[r]?
    */
    int search(vector<int>& nums, int target)
    {
        int l = 0;
        int r = static_cast<int>(nums.size() - 1);
        int m;

        while (l <= r)
        {
            m = l + ((r - l) / 2);
            
            if(nums[m] == target)
                return m;
            
            // Now there are three possible scenarios:
            // nums[l] < nums[m] < nums[r] (normal). Execute as always.
            // nums[l] > nums[m] < nums[r] (Lowest value before m).
            // nums[l] < nums[m] > nums[r] (Lowest after m).
        
            // Min before m
            if(nums[l] >= nums[m] && nums[m] <= nums[r])
            {
                if(target >= nums[m] && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
            //Min after m
            else if(nums[l] <= nums[m] && nums[m] >= nums[r])
            {
                if(target >= nums[l] && target <= nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }
            // Min at l, max at r (non-rotated)
            else
            {
                if(nums[m] < target)
                    l = m + 1;
                else
                    r = m - 1;
            }
        }

        return -1;
    }
};
