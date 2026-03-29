class Solution {
/*
intervals: [1, 3], [2, 5], [6, 7]
 -- --
  --
i = 0, ret = {} -> ret = {[1, 3]}
i = 1, ret = {[1, 3]} -> ret = {[1, 5]}
i = 2, ret = {[1, 3]} -> ret = {[1, 5], [6, 7]}
*/
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        auto sort_crit = [](const std::vector<int>& a, const std::vector<int>& b) -> bool
        {
            return a[0] < b[0];
        };

        std::sort(intervals.begin(), intervals.end(), sort_crit);

        vector<vector<int>> ret;

        for(int i = 0; i < static_cast<int>(intervals.size()); i++)
        {
            if(!ret.size())
            {
                ret.emplace_back(intervals[i]);
                continue;
            }

            if(ret[ret.size() - 1][1] >= intervals[i][0])
                ret[ret.size() - 1][1] = std::max(ret[ret.size() - 1][1], intervals[i][1]);
            else
                ret.emplace_back(intervals[i]);
        }

        return ret;
    }
};
