class Solution {
private:
    using str = std::string;
    using vec_str = std::vector<std::string>;
    using mat_str = std::vector<vec_str>;
    using str_2_vec_str_map = std::unordered_map<str, vec_str>;

    str getSortedString(const str& s)
    {
        str ret = s;
        std::sort(ret.begin(), ret.end());
        return ret;
    }

    mat_str getVectorOfGroupedStringsFromHist(str_2_vec_str_map& hist)
    {
        mat_str ret;

        for(str_2_vec_str_map::iterator it = hist.begin(); it != hist.end(); it++)
            ret.emplace_back(it->second);
        
        return ret;
    }

public:
    mat_str groupAnagrams(vec_str& strs)
    {
        str_2_vec_str_map grouped_anagrams;
        str sorted_aux;

        // The footprint of each string will be its sorted version. For instance, "acb" and "bca" will
        // both have the same footprint. Our goal is to classify them using the map above by using those
        // so-called footprints.
        // In order to do so, iterate strs vector. For each string, sort it, and check whether its
        // footprint does already exist within grouped_anagrams's keys. If not, then just create the
        // key (footprint) and the value (a vector with the current string). If the footprint is already
        // found within grouped_anagrams keys, then simply append it to the footprint associated values.

        // Iterate words within strs.
        for(str s : strs)
        {
            // Check whether sorted string is found within histogram's keys.
            sorted_aux = this->getSortedString(s);
            
            if(!grouped_anagrams.count(sorted_aux))
                grouped_anagrams[sorted_aux] = {s};
            else
                grouped_anagrams[sorted_aux].emplace_back(s);
        }

        return this->getVectorOfGroupedStringsFromHist(grouped_anagrams);
    }
};
