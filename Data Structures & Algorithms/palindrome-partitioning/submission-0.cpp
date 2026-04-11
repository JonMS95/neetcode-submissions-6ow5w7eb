/*
Create a recursive function that tells whether a palindrome can be formed from a starting point.
If the starting point is out of bounds, then simply return true. Otherwise, try to form a palindrome
from the starting point. For every palindrome found within i and j, copy it to a vector of strings, 
then call the function recursively. If the function returns false, try with another combination.
*/

class Solution
{
private:
    bool _isPalindrome(const std::string& s, int l, int r)
    {
        while(l < r)
            if(s[l++] != s[r--])
                return false;
        
        return true;
    }

    void _backtrack(const std::string& s                        ,
                    std::vector<std::string>& cur               ,
                    std::vector<std::vector<std::string>>& ret  ,
                    const int idx = 0                           )
    {
        const int s_size = static_cast<int>(s.size());

        if(idx >= s_size)
            ret.emplace_back(cur);

        for(int i = idx; i < s_size; i++)
        {
            if(_isPalindrome(s, idx, i))
            {
                cur.emplace_back(s.substr(idx, i - idx + 1));
                _backtrack(s, cur, ret, i + 1);
                cur.pop_back();
            }
        }
    }

public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::vector<std::string>> ret;
        std::vector<std::string> cur;
        
        _backtrack(s, cur, ret);

        return ret;
    }
};
