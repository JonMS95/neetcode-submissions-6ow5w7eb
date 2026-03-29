class Solution {
private:
    using vec_int = std::vector<int>;

public:
    int search(vec_int& nums, int target) 
    {
        int l = 0;
        int r = static_cast<int>(nums.size() - 1);
        int m;

        while(l <= r)
        {
            m = l + (r - l) / 2;

            if(nums[m] == target)
                return m;

            if(target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        }

        return -1;
    }
};
