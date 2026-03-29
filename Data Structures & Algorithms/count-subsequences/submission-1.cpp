/*
Watch decisions to be taken from string 's' as if it was a tree.

s = "caaat"

From s[0] (== 'c'), there are 4 different choices to be taken ('a', 'a', 'a', 't'). For each of those
possible next characters. Repeat for each of the descending nodes.
*/

class Solution
{
private:
    inline int _getKeyFromIndices(const int s_idx, const int t_idx)
    {
        return ((s_idx << 16) | t_idx);
    }

    int _traversal(const std::string& s, const std::string& t, std::unordered_map<int, int>& known_values, const int s_idx = 0, const int t_idx = 0)
    {
        if(t_idx == static_cast<int>(t.size()))
            return 1;

        int key = this->_getKeyFromIndices(s_idx, t_idx);

        if(known_values.count(key))
            return known_values[key];

        int ret = 0;

        for(int i = s_idx; i < s.size(); i++)
            if(s[i] == t[t_idx])
                ret += this->_traversal(s, t, known_values, i + 1, t_idx + 1);

        known_values[key] = ret;

        return ret;
    }

public:
    int numDistinct(std::string s, std::string t)
    {
        std::unordered_map<int, int> known_values;
        return this->_traversal(s, t, known_values);
    }
};
