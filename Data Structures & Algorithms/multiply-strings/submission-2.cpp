class Solution {
private:
    inline int _getIntFromChar(const char& c)
    {
        return static_cast<int>(c - '0');
    }

    inline char _getCharFromInt(const int& n)
    {
        return static_cast<char>('0' + n);
    }

    std::string _multStringByChar(const std::string& s, const char c, const int padding = 0)
    {
        int a;
        int b = this->_getIntFromChar(c);
        int carry = 0;

        int cur;

        std::string ret(padding, '0');

        for(int i = static_cast<int>(s.size() - 1); i >= 0; i--)
        {
            a = this->_getIntFromChar(s[i]);

            cur = a * b + carry;
            carry = cur / 10;
            cur %= 10;

            ret.insert(ret.begin(), this->_getCharFromInt(cur));
        }

        if(carry)
            ret.insert(ret.begin(), this->_getCharFromInt(carry));

        return ret;
    }

    std::string _addTwoStrings(std::string& a, std::string& b)
    {
        const int size_diff = static_cast<int>((a.size() - b.size()));

        if(size_diff != 0)
        {
            std::string padding(std::abs(size_diff), '0');

            if(a.size() > b.size())
                b = padding + b;
            else
                a = padding + a;
        }

        std::string ret(a.size(), '0'); // fill with '0's

        int x, y, cur;
        int carry = 0;

        for(int i = static_cast<int>(a.size() - 1); i >= 0; i--)
        {
            x = this->_getIntFromChar(a[i]);
            y = this->_getIntFromChar(b[i]);
            
            cur = x + y + carry;
            carry = cur / 10;
            cur %= 10;

            ret[i] = this->_getCharFromInt(cur);
        }

        if(carry)
            ret = this->_getCharFromInt(carry) + ret;
        
        return ret;
    }

    void _trimLeadingZeros(std::string& s)
    {
        const int s_size = static_cast<int>(s.size());

        while(s.size() > 1 && s[0] == '0')
            s.erase(s.begin());
    }

public:
    string multiply(string num1, string num2)
    {
        std::string ret = "0";

        const int num2_size = static_cast<int>(num2.size());

        for(int i = 0; i < num2_size; i++)
        {
            std::string mult = this->_multStringByChar(num1, num2[num2_size - i - 1], i);
            ret = this->_addTwoStrings(ret, mult);
        }

        this->_trimLeadingZeros(ret);

        return ret;
    }
};
