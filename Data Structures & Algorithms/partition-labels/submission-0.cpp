/*
My approach is based on the following steps:

1 - Get a map with all character boundaries (indexes representing first and
last appearances) of each character within the given string.
2 - Transform the map into a vector of integer pairs and sort it based on
each pair's first element (start index).
3 - Merge intervals. For every interval except for the first one (which is
directly pushed to the merged intervals vector), do the following: if
previous interval's last index is greater than current intervals start index,
then set previous interval's end as the maximum between both end indices.
Otherwise (non-overlapping indices), then push the interval directly.
4 - Once intervals are already merged, pick that merged intervals vector and
return a vector featuring each intervals length (end - start + 1).
*/

class Solution
{
private:
    using str           = std::string;
    using vec_int       = std::vector<int>;
    using bounds        = std::pair<int, int>;
    using vec_bounds    = std::vector<bounds>;
    using inter_map     = std::unordered_map<int, bounds>;
    using inter_map_it  = inter_map::iterator;

    inter_map _getCharacterBoundariesAsMap(const str& s)
    {
        inter_map ret;

        for(int i = 0; i < static_cast<int>(s.size()); i++)
            if(!ret.count(s[i]))
                ret[s[i]] = {i, i};
            else
                ret[s[i]].second = i;
        
        return ret;
    }

    vec_bounds _getCharacterBoundariesAsSortedVector(const str& s)
    {
        inter_map bounds_as_map = this->_getCharacterBoundariesAsMap(s);
        vec_bounds ret;

        for(inter_map_it it = bounds_as_map.begin(); it != bounds_as_map.end(); it++)
            ret.emplace_back(it->second);
        
        auto sort_crit = [](const bounds& a, const bounds& b) -> bool
        {
            return a.first < b.first;
        };

        std::sort(ret.begin(), ret.end(), sort_crit);

        return ret;
    }

    vec_bounds _getMergedIntervals(const str& s)
    {
        vec_bounds char_ivals = this->_getCharacterBoundariesAsSortedVector(s);
        vec_bounds ret;

        ret.emplace_back(char_ivals[0]);

        for(int i = 1; i < static_cast<int>(char_ivals.size()); i++)
            if(ret.back().second >= char_ivals[i].first)
                ret.back().second = std::max(ret.back().second, char_ivals[i].second);
            else
                ret.emplace_back(char_ivals[i]);
        
        return ret;
    }

    vec_int _getSizeOfIntervals(const vec_bounds& vec)
    {
        vec_int ret(vec.size());

        for(int i = 0; i < static_cast<int>(vec.size()); i++)
            ret[i] = vec[i].second - vec[i].first + 1;
        
        return ret;
    }

public:
    vec_int partitionLabels(str s)
    {
        vec_bounds character_boundaries = this->_getMergedIntervals(s);
        return this->_getSizeOfIntervals(character_boundaries);
    }
};
