class Solution {
private:
    // Returns true if equal, false otherwise
    bool _compForMinSize(const std::string& a, const std::string& b, const int start = 0)
    {
        for(int i = start; i < std::min(a.size(), b.size()); i++)
            if(a[i] != b[i])
                return false;
        
        return true;
    }

    void _backtrack(const std::string& msg, std::string& tmp, int& cnt)
    {
        if(tmp.size() > msg.size())
            return;
        
        if(tmp.size() == msg.size())
        {
            if(tmp == msg)
                ++cnt;

            return;
        }
        
        std::string aux;
        int st = static_cast<int>(tmp.size());

        for(int i = 1; i <= 26; i++)
        {
            aux = std::to_string(i);

            tmp += aux;

            if(this->_compForMinSize(msg, tmp, st))
                this->_backtrack(msg, tmp, cnt);

            for(int i = 0; i < static_cast<int>(aux.size()); i++)
                tmp.pop_back();
        }
    }

public:
    int numDecodings(std::string s)
    {
        int ret = 0;
        std::string temp;

        this->_backtrack(s, temp, ret);

        return ret;
    }
};
