class Solution {
private:
    void _equalizeSizes(std::string& a, std::string& b)
    {
        const int size_diff = static_cast<int>(a.size() - b.size());
    
        if(size_diff != 0)
        {
            if(size_diff > 0)
                b = std::string(size_diff, '0') + b;
            else
                a = std::string(-size_diff, '0') + a;
        }
    }

    int _getOnesCount(const char& a, const char& b, const char& c)
    {
        int count = 0;

        if(a == '1') count++;
        if(b == '1') count++;
        if(c == '1') count++;
        
        return count;
    }

    inline char _getCarry(const char& a, const char& b, const char& c)
    {   
        return this->_getOnesCount(a, b, c) >= 2 ? '1' : '0';
    }

    inline char _getSum(const char& a, const char& b, const char& c)
    {
        return this->_getOnesCount(a, b, c) % 2 == 1 ? '1' : '0';
    }

    void _trimLeadingZeros(std::string& s)
    {
        while(s.size() > 1 && s[0] == '0')
            s.erase(s.begin());
    }

public:
    std::string addBinary(std::string a, std::string b)
    {
        this->_equalizeSizes(a, b);

        const int num_size = static_cast<int>(a.size());

        char carry = '0';
        std::string ret(num_size, '0');

        for(int i = num_size - 1; i >= 0; i--)
        {
            ret[i] = this->_getSum(a[i], b[i], carry);
            carry = this->_getCarry(a[i], b[i], carry);
        }

        if(carry == '1')
            ret.insert(ret.begin(), carry);
        
        this->_trimLeadingZeros(ret);

        return ret;
    }
};