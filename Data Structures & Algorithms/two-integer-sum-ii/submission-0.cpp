class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        // Two indices: 0 and size - 1. This way, we have the biggest possible sum.
        // There are two ways to modify current sum:
        // ·Move leftmost index rightwards -> Increases sum value.
        // ·Move rightmost index leftwards -> Decreases sum value.
        // Example:
        // 1 3 7 10 15, l = 0, r = 4. Initial sum = 1 + 15 = 16.
        // Moving left pointer rightwards (l = 1, r = 4),
        // sum = 3 + 15 = 18.
        // Moving right pointer leftwards (l = 1, r = 3),
        // sum = 3 + 10 = 15.

        int l = 0;
        int r = static_cast<int>(numbers.size() - 1);
        int cur;

        while(l < r)
        {
            cur = numbers[l] + numbers[r];
            
            if(cur == target)
                return {l + 1, r + 1};
            
            if(cur < target) // Need to increase the sum -> move left pointer rightwards.
                ++l;
            else
                --r;
        }

        return {-1, -1};
    }
};
