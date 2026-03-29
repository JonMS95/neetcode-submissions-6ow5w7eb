class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::less<int>> pq_max(nums.begin(), nums.end());

        for(int i = 0; i < (k - 1); i++)
            pq_max.pop();

        return pq_max.top();
    }
};