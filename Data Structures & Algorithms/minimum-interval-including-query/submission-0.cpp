class Solution {
private:
    int _getMinIntervalSize(const int query, const std::vector<std::vector<int>>& intervals)
    {
        int best = INT_MAX;
    
        int idx = 0;
        int cur;

        while(idx < (static_cast<int>(intervals.size())) && intervals[idx][0] <= query)
        {
            if(intervals[idx][1] < query)
            {
                ++idx;
                continue;
            }

            if((cur = intervals[idx][1] - intervals[idx][0] + 1) < best)
                best = cur;
            
            ++idx;
        }

        if(best == INT_MAX)
            return -1;

        return best;
    }

public:
    std::vector<int> minInterval(std::vector<std::vector<int>>& intervals, std::vector<int>& queries)
    {
        // Sort intervals by their starting point.
        auto sort_crit = [](const std::vector<int>& a, const std::vector<int>& b) -> bool
        {
            return a[0] < b[0];
        };

        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) -> bool {return a[0] < b[0];});

        std::vector<int> ret;

        for(int q : queries)
            ret.emplace_back(this->_getMinIntervalSize(q, intervals));

        return ret;
    }
};
