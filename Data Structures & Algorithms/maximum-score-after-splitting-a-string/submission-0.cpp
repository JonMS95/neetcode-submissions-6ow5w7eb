class Solution {
private:
    std::vector<int> _getLeftZeros(const std::string& s)
    {
        int zero_counter = 0;
        std::vector<int> ret(s.size());

        for(int i = 0; i < static_cast<int>(s.size()); i++)
        {
            if(s[i] == '0')
                zero_counter++;
            
            ret[i] = zero_counter;
        }

        return ret;
    }

    std::vector<int> _getRightOnes(const std::string& s)
    {
        int one_counter = 0;
        std::vector<int> ret(s.size());

        for(int i = static_cast<int>(s.size() - 1); i >= 0; i--)
        {
            if(s[i] == '1')
                one_counter++;
            
            ret[i] = one_counter;
        }

        return ret;
    }

public:
    int maxScore(std::string s)
    {
        std::vector<int> left_zeros = this->_getLeftZeros(s);
        std::vector<int> right_ones = this->_getRightOnes(s);

        int ret = 0;
        int cur;

        for(int i = 0; i < static_cast<int>(s.size() - 1); i++)
            if((cur = left_zeros[i] + right_ones[i + 1]) > ret)
                ret = cur;
        
        return ret;
    }
};