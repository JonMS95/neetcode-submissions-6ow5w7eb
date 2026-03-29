class Solution {
public:
    int scoreOfString(std::string s)
    {
        int ret = 0;

        for(int i = 0; i < static_cast<int>(s.size() - 1); i++)
            ret += (std::max(s[i], s[i + 1]) - std::min(s[i], s[i + 1]));
        
        return ret;
    }
};