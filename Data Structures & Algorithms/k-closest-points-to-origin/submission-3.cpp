class Solution
{
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k)
    {
        auto sort_crit = [](const std::vector<int>& a, const std::vector<int>& b) -> bool
        {
            auto calc_sq_dist = [](const std::vector<int>& coords) -> int
            {
                return ((coords[0] * coords[0]) + (coords[1] * coords[1]));
            };
        
            return calc_sq_dist(a) < calc_sq_dist(b);
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(sort_crit)> min_heap;
    
        for(const std::vector<int>& p : points)
        {
            min_heap.push(p);

            while(min_heap.size() > k)
                min_heap.pop();
        }

        std::vector<std::vector<int>> ret;

        while(!min_heap.empty())
        {
            ret.emplace_back(min_heap.top());
            min_heap.pop();
        }

        return ret;
    }
};
