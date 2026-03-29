/*
Key idea: use two histograms, start crafting the t-string's one first.
Then, keep widening the window while building s-string's histogram, and
stop if both histograms have the same size at any point.

Afterwards, keep shrinking the window, and keep trimming all the
characters that are not found within t-string histogram's keys. Also,
keep going ahead if what we come across is a key for which the count is
greater than 1. Only if what we find (while shrinking) a character for
which count is equal to 1. In that case, check (and update, if needed),
minimum length substring. After that, keep shrinking until another
character is found (?).

Also, always keep in mind to erase the key when shrinking.
*/

class Solution
{
private:
    std::unordered_map<char, int> _makeHistFromStr(const std::string& s)
    {
        std::unordered_map<char, int> ret;

        for(const char& c : s)
            ++ret[c];

        return ret;
    }

    std::string _getSubstringGivenBoundaries(const std::string& s, const std::pair<int, int>& bounds)
    {
        std::string ret = "";

        for(int i = bounds.first; i <= bounds.second; i++)
            ret += s[i];
        
        return ret;
    }

    bool _checkEquivalentHistograms( std::unordered_map<char, int>& s_hist,  std::unordered_map<char, int>& t_hist)
    {
        if(s_hist.size() != t_hist.size())
            return false;

        for(auto it = t_hist.begin(); it != t_hist.end(); it++)
            if(s_hist[it->first] < it->second)
                return false;

        return true;
    }

public:
    std::string minWindow(std::string s, std::string t)
    {
        if(t.size() > s.size())
            return "";
        
        if(s == t)
            return s;

        std::unordered_map<char, int> t_hist = this->_makeHistFromStr(t);
        std::unordered_map<char, int> s_hist;

        int fast = 0;
        int slow = 0;

        std::pair<int, int> boundaries = {0, -1};

        const int s_size = static_cast<int>(s.size());
        
        int cur_len = INT_MAX;
        int new_len;

        while(fast < s_size)
        {
            // While widening, keep adding to s_hist any element found among t_hist's keys.
            if(t_hist.count(s[fast]))
                ++s_hist[s[fast]];
            
            // Keep shrinking while histogram sizes are equal. 
            while(this->_checkEquivalentHistograms(s_hist, t_hist))
            {
                if(!s_hist.count(s[slow]))
                {
                    ++slow;
                    continue;
                }

                if(s_hist[s[slow]] > 1)
                {
                    --s_hist[s[slow]];
                    ++slow;
                    continue;
                }

                s_hist.erase(s[slow]);

                new_len = fast - slow + 1;

                if(new_len < cur_len)
                {
                    cur_len = new_len;
                    boundaries = {slow, fast};
                }

                ++slow;
            }

            fast++;
        }

        return this->_getSubstringGivenBoundaries(s, boundaries);
    }
};
