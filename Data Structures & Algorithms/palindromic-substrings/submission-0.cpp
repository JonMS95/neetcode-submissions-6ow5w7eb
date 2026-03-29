/*
For the following string: "aaabcca"
We should go for every starting point
*/

class Solution {
private:
    int _countPalindromes(const std::string& s, int left, int right)
    {
        int ret = 0;
        const int s_size = static_cast<int>(s.size());

        while(left >= 0 && right < s_size)
            if(s[left--] != s[right++])
                break;
            else
                ++ret;

        return ret;
    }

public:
    int countSubstrings(std::string s)
    {
        int ret = 0;
        const int s_size = static_cast<int>(s.size());

        for(int i = 0; i < s_size; i++)
        {
            if(i < (s_size - 1))
                ret += this->_countPalindromes(s, i, i + 1);
            
            ret += this->_countPalindromes(s, i, i);
        }

        return ret;
    }
};
