/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

/*
Ex.: (0, 5), (1, 2), (3, 4)
.....
 ..
   ..

In light of the above, we should check whether any of the endings is greater
than any of the following starting points. To do so, we can simply order all
of the intervals by their starting points, then check if overlapping condition
is met at any point.
*/

class Solution {
public:
    bool canAttendMeetings(std::vector<Interval>& intervals)
    {
        auto sort_crit = [](const Interval& a, const Interval& b) -> bool
        {
            return a.start < b.start;
        };

        std::sort(intervals.begin(), intervals.end(), sort_crit);

        for(int i = 0; i < static_cast<int>(intervals.size() - 1); i++)
            if(intervals[i].end > intervals[i + 1].start)
                return false;
        
        return true;
    }
};
