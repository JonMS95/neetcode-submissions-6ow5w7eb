class Solution {
private:
    using str = std::string;
    using vec_str = std::vector<str>;

    int _getShortestStringLength(const vec_str& strs)
    {
        int ret = static_cast<int>(strs[0].size());
        int cur;

        for(int i = 1; i < static_cast<int>(strs.size()); i++)
            if((cur = static_cast<int>(strs[i].size())) < ret)
                ret = cur;
        
        return ret;
    }

public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        const int min_len = this->_getShortestStringLength(strs);
        std::string ret = "";
        char cur;

        for(int i = 0; i < min_len; i++)
        {
            cur = strs[0][i];

            for(int j = 1; j < static_cast<int>(strs.size()); j++)
            {
                if(strs[j][i] != cur)
                    return ret;
            }

            ret += cur;
        }

        return ret;
    }
};