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
    bool _compForMinSize(const std::string& a, const std::string& b, const int start = 0)
    {
        for(int i = start; i < std::min(a.size(), b.size()); i++)
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
        
        std::string aux;
        int st = static_cast<int>(tmp.size());

        for(char c = 'A'; c <= 'Z'; c++)
        {
            aux = hist[c];

            tmp += aux;

            if(this->_compForMinSize(msg, tmp, st))
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
