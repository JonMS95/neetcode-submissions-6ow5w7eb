class Solution
{
public:
    std::vector<int> sortArray(std::vector<int>& nums)
    {
        const int nums_size = static_cast<int>(nums.size());

        // Let's create a min_heap.
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(nums.begin(), nums.end());

        std::vector<int> ret(nums_size);

        for(int i = 0; i < nums_size; i++)
        {
            ret[i] = min_heap.top();
            min_heap.pop();
        }

        return ret;
    }
};