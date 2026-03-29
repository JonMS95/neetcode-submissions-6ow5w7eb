class Solution {
private:
    using umap_ci = std::unordered_map<char, std::string>;

    umap_ci _makeCharToNumHist(void)
    {
        std::unordered_map<char, std::string> ret;
        int counter = 0;

        for(char c = 'A'; c <= 'Z'; c++)
            ret[c] = std::to_string(++counter);
        
        return ret;
    }

    // Returns true if equal, false otherwise
    bool _compForMinSize(const std::string& a, const std::string& b)
    {
        for(int i = 0; i < std::min(a.size(), b.size()); i++)
            if(a[i] != b[i])
                return false;
        
        return true;
    }

    void _backtrack(const std::string& msg, std::string& tmp, umap_ci& hist, int& cnt)
    {
        if(tmp.size() > msg.size())
            return;
        
        if(tmp.size() == msg.size())
        {
            if(tmp == msg)
                ++cnt;

            return;
        }

        if(!this->_compForMinSize(msg, tmp))
            return;
        
        std::string aux;

        for(char c = 'A'; c <= 'Z'; c++)
        {
            aux = hist[c];

            tmp += aux;

            this->_backtrack(msg, tmp, hist, cnt);

            for(int i = 0; i < static_cast<int>(aux.size()); i++)
                tmp.pop_back();
        }
    }

public:
    int numDecodings(std::string s)
    {
        umap_ci char_to_num = this->_makeCharToNumHist();
        int ret = 0;
        std::string temp;

        this->_backtrack(s, temp, char_to_num, ret);

        return ret;
    }
};
