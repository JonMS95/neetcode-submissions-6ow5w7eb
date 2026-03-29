class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> known_values;

        // Given a number (n), check whether (target - n) exists within our known values unordered set.
        for(int i = 0; i < static_cast<int>(nums.size()); i++)
            if(known_values.count((target - nums[i])))
                return {known_values[(target - nums[i])], i};
            else
                known_values[nums[i]] = i;
        
        return {0, 0};
    }
};
