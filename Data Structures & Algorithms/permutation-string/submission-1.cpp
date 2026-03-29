class Solution {
private:
    std::unordered_map<char, int> _getHistFromStr(const std::string& s)
    {
        std::unordered_map<char, int> ret;

        for(char c : s)
            ++ret[c];
        
        return ret;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        std::unordered_map<char, int> fixed_hist = this->_getHistFromStr(s1);
        std::unordered_map<char, int> sliding_hist;

        const int s1_size = static_cast<int>(s1.size());
        const int s2_size = static_cast<int>(s2.size());

        for(int i = 0; i < s1_size; i++)
            ++sliding_hist[s2[i]];
        
        if(sliding_hist == fixed_hist)
            return true;
        
        for(int i = 1; i <= (s2_size - s1_size); i++)
        {
            --sliding_hist[s2[i - 1]];

            if(!sliding_hist[s2[i - 1]])
                sliding_hist.erase(s2[i - 1]);

            ++sliding_hist[s2[i + s1_size - 1]];

            if(sliding_hist == fixed_hist)
                return true;
        }

        return false;
    }
};
