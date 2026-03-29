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

class Solution {
private:
    std::pair<int, int> _getMinimumEntryHour(std::vector<Interval>& intervals)
    {
        std::pair<int, int> ret = {intervals[0].start, intervals[0].end};

        for(int i = 1; i < static_cast<int>(intervals.size()); i++)
        {
            if(intervals[i].start < ret.first)
                ret.first = intervals[i].start;
            
            if(intervals[i].end > ret.second)
                ret.second = intervals[i].end;
        }
        
        return ret;
    }

public:
    int minMeetingRooms(std::vector<Interval>& intervals)
    {
        if(!intervals.size())
            return 0;
        
        const std::pair<int, int> time_boundaries = this->_getMinimumEntryHour(intervals);
        const int max_time_diff = time_boundaries.second - time_boundaries.first + 1;

        std::vector<int> meetings_per_hour(max_time_diff, 0);

        int ret = 0;

        for(Interval ival : intervals)
        {
            ival.start -= time_boundaries.first;
            ival.end -= time_boundaries.first;

            for(int i = ival.start; i < ival.end; i++)
            {
                ++meetings_per_hour[i];
                
                if(ret < meetings_per_hour[i])
                    ret = meetings_per_hour[i];
            }
        }

        return ret;
    }
};
