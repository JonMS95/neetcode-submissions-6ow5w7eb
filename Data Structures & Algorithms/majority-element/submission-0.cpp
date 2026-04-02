class Solution {
public:
    int majorityElement(std::vector<int>& nums)
    {
        std::unordered_map<int, int> hist;

        auto org_crit = [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> bool
        {
            return a.second > b.second;
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(org_crit)> min_heap(org_crit);

        for(int n: nums)
        {
            ++hist[n];

            min_heap.push({n, hist[n]});

            if(min_heap.size() > 1)
                min_heap.pop();
        }

        return min_heap.top().first;
    }
};