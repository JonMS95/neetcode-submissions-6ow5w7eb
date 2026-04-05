/*
Approach: opposite of "Merge intervals".

In merge intervals, we had to keep track of the previous interval. If the previous interval
overlapped with the current (after sorting by first element), then we had to modify the
previous element by setting the end of the previous as the maximum between the current's
and the prior's.

In this case, the logic is pretty much inverse. Store the first interval. Then, for the
following interval, check whether it overlaps. If it does, remove the most prone to being
conflictive among those two, it's to say, the one that ends last (since it's more likely
to come across any other upcoming interval's head). If that's the case, keep previous "as
is", otherwise, update previous with current interval.
*/

class Solution
{
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals)
    {
        int ret = 0;

        if(!intervals.size())
            return ret;

        auto sort_crit = [](const std::vector<int>& a, const std::vector<int>& b) -> bool
        {
            return a[0] < b[0];
        };

        std::sort(intervals.begin(), intervals.end(), sort_crit);

        std::vector<int> prev = intervals[0];

        for(int i = 1; i < static_cast<int>(intervals.size()); i++)
        {
            // if they don't overlap, just update previous interval as the current one.
            if(prev[1] <= intervals[i][0])
            {
                prev = intervals[i];
                continue;
            }

            // Otherwise, remove the interval with furthest end and increment removal count.
            ++ret;
            if(prev[1] > intervals[i][1])
                prev = intervals[i];
        }

        return ret;
    }
};
