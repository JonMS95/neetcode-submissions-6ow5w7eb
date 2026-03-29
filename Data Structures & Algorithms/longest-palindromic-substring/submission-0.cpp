class Solution
{
private:
    std::pair<int, int> getMaxPalindromeLength(const std::string& s, int l, int r)
    {
        std::pair<int, int> ret = {0, 0};

        while(l >= 0 && r < static_cast<int>(s.size()))
        {
            if(s[l] != s[r])
            {
                break;
            }
            else
            {
                ret.first = l;
                ret.second = r;
                --l;
                ++r;
            }
        }

        return ret;
    }

    std::pair<int, int> updateBoundaries(std::pair<int, int> new_bounds, std::pair<int, int> old_bounds)
    {
        if((new_bounds.second - new_bounds.first) > (old_bounds.second - old_bounds.first))
            return new_bounds;
        else
            return old_bounds;
    }

    std::string getSubstringFromBoundaries(std::pair<int, int>& boundaries, const std::string& s)
    {
        std::string ret = "";

        for(int i = boundaries.first; i <= boundaries.second; i++)
            ret += s[i];
        
        return ret;
    }

public:
    std::string longestPalindrome(std::string s)
    {
        /*
        Two approaches:
            ·Odd-length palindrome: pick any index within the string, then try to extend it in both ways.
            ·Even-length palindrome: do the same as above but with two starting indexes.
        */
        std::pair<int, int> boundaries = {0, 0};

        const int s_size = static_cast<int>(s.size());

        for(int i = 0; i < s_size; i++)
        {
            boundaries = this->updateBoundaries(this->getMaxPalindromeLength(s, i, i), boundaries);

            if(i < (s_size - 1))
                boundaries = this->updateBoundaries(this->getMaxPalindromeLength(s, i, i + 1), boundaries);
        }

        return this->getSubstringFromBoundaries(boundaries, s);
    }
};
