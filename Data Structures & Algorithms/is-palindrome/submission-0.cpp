class Solution {
private:
    using str = std::string;

    // Get string with only lowercase alphanumeric letters and numbers.
    str getNormalizedString(const str& s)
    {
        str ret = "";
        
        for(char c : s)
        {
            if(c >= 'A' && c <= 'Z')
                ret += std::tolower(c);

            if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z'))
                ret += c;
        }

        return ret;
    }

    bool checkPalindromeWithTwoPointers(const str s)
    {
        int left = 0;
        int right = static_cast<int>(s.size() - 1);

        while(left < right)
            if(s[left++] != s[right--])
                return false;
        
        return true;
    }

public:
    bool isPalindrome(string s)
    {
        return this->checkPalindromeWithTwoPointers(this->getNormalizedString(s));
    }
};
