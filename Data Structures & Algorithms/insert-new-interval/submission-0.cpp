class Solution {
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;

public:
    mat_int insert(mat_int& intervals, vec_int& newInterval)
    {
        auto sort_crit = [](const vec_int& a, const vec_int& b) -> bool
        {
            return a[0] < b[0];
        };

        intervals.emplace_back(newInterval);

        std::sort(intervals.begin(), intervals.end(), sort_crit);

        mat_int ret;
        const int inter_size = static_cast<int>(intervals.size());

        for(int i = 0; i < inter_size; i++)
        {
            if(!ret.size())
            {
                ret.emplace_back(intervals[i]);
                continue;
            }

            if(ret[ret.size() - 1][1] >= intervals[i][0])
            {
                ret[ret.size() - 1][1] = std::max(ret[ret.size() - 1][1], intervals[i][1]);
            }
            else
            {
                ret.emplace_back(intervals[i]);
            }
        }

        return ret;
    }
};