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

    int _heapSolution(const std::vector<int> nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::less<int>> max_heap(nums.begin(), nums.end());
        
        --k;

        while(k > 0)
        {
            max_heap.pop();
            --k;
        }
        
        return max_heap.top();
    }

public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        // return this->_sortingSolution(nums, k);
        return this->_heapSolution(nums, k);
    }
};
