/*
Watch decisions to be taken from string 's' as if it was a tree.

s = "caaat"

From s[0] (== 'c'), there are 4 different choices to be taken ('a', 'a', 'a', 't'). For each of those
possible next characters. Repeat for each of the descending nodes.
*/

class Solution
{
private:
    int _traversal(const std::string& s, const std::string& t, const int s_idx = 0, const int t_idx = 0)
    {
        if(t_idx == static_cast<int>(t.size()))
            return 1;

        int ret = 0;

        for(int i = s_idx; i < s.size(); i++)
            if(s[i] == t[t_idx])
                ret += this->_traversal(s, t, i + 1, t_idx + 1);

        return ret;
    }

public:
    int numDistinct(std::string s, std::string t)
    {
        return this->_traversal(s, t);
    }
};
