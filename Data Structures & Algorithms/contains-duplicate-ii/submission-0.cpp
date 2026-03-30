class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> hist;

        for(int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            if(!hist.count(nums[i]))
            {
                hist[nums[i]] = i;
                continue;
            }

            if(i - hist[nums[i]] <= k)
                return true;
            else
                hist[nums[i]] = i;
        }

        return false;
    }
};