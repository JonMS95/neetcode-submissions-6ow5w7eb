class Solution {
private:
    int _sortingSolution(std::vector<int> nums, const int k)
    {
        auto sort_crit = [](const int& a, const int& b) -> bool
        {
            return a > b;
        };

        std::sort(nums.begin(), nums.end(), sort_crit);

        return nums[k - 1];
    }

public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        return this->_sortingSolution(nums, k);
    }
};
