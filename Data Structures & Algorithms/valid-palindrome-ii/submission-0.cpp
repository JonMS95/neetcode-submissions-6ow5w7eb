class Solution {
private:
    bool _validPalindrome(  const std::string& s            ,
                            const int left                  ,
                            const int right                 ,
                            const bool used_joker = false   )
    {
        if(left > right)
            return true;
            // throw std::runtime_error("Left index should never be greater than right one");
        
        if(s[left] == s[right])
        {
            return this->_validPalindrome(s, left + 1, right - 1, used_joker);
        }
        else
        {
            if(used_joker)
                return false;
            
            return this->_validPalindrome(s, left + 1, right, true) || this->_validPalindrome(s, left, right - 1, true);
        }
    }

public:
    bool validPalindrome(std::string s)
    {
        return this->_validPalindrome(s, 0, static_cast<int>(s.size() - 1));
    }
};