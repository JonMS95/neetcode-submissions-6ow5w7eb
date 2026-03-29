class Solution {
private:
    using str = std::string;
    using vec_str = std::vector<str>;
    using vec_int = std::vector<int>;

public:
/*
Encoding format (ex: 3 strings):
num_of_strings:len_1,len2,len3|string1string2string3
(Once length of each is determined, there's no need to use any
additional token to separate them).
*/
    str encode(vec_str& strs)
    {
        const int num_of_strings = static_cast<int>(strs.size());

        str ret = "";

        ret += std::to_string(num_of_strings);
        ret += ':';

        for(int i = 0; i < num_of_strings; i++)
        {
            ret += std::to_string(static_cast<int>(strs[i].size()));
            ret += ',';
        }

        ret += '|';
        
        for(str s : strs)
            ret += s;

        return ret;
    }

    int getIdxOfChar(const str& s, const char c)
    {
        int idx = 0;

        while(s[idx] != c)
            ++idx;
        
        return (idx + 1);
    }

    int getNumberOfStrings(const str& s)
    {
        int idx = 0;
        int ret = 0;

        while(s[idx] != ':')
        {
            ret *= 10;
            ret += (s[idx++] - '0');
        }

        return ret;
    }

    vec_int getEncodedStringLengths(const str& s)
    {
        vec_int ret;
        int cur = 0;

        // Get idx of first ':'.
        int idx = this->getIdxOfChar(s, ':');

        while(s[idx] != '|')
        {
            if(s[idx] == ',')
            {
                ret.emplace_back(cur);
                cur = 0;
            }
            else
            {
                cur *= 10;
                cur += s[idx] - '0';
            }
            ++idx;
        }

        return ret;
    }

    // num_of_strings:len_1,len2,len3|string1string2string3
    vec_str decode(str s)
    {
        if(s[0] == '0')
            return {};
        
        vec_str ret;
        const int num_of_strings = this->getNumberOfStrings(s);
        vec_int lengths = this->getEncodedStringLengths(s);
        str cur = "";

        int idx = this->getIdxOfChar(s, '|');

        for(int i = 0; i < num_of_strings; i++)
        {
            cur = "";
        
            for(int j = idx; j < idx + lengths[i]; j++)
                cur += s[j];
        
            idx += lengths[i];
        
            ret.emplace_back(cur);
        }

        return ret;
    }
};
