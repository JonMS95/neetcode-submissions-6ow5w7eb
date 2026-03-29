class Solution {
private:
    inline int _makeKey(const int a, const int b)
    {
        return ((a << 16) | b);
    }

    bool _dp(   const std::string& a                ,
                const std::string& b                ,
                const std::string& c                ,
                std::unordered_map<int, int>& memo  ,
                const int idx_a = 0                 ,
                const int idx_b = 0                 )
    {
        const int key = this->_makeKey(idx_a, idx_b);

        auto it = memo.find(key);
        if(it != memo.end())
            return it->second;

        const int idx_c = idx_a + idx_b;
        const int a_size = static_cast<int>(a.size());
        const int b_size = static_cast<int>(b.size());
        const bool a_ex = (idx_a == a_size);
        const bool b_ex = (idx_b == b_size);
        bool ret;

        // If both indices have been already exhausted, then the string has already been built.
        if(a_ex && b_ex)
            ret = true;

        // If only a is exhausted, then check b
        else if(a_ex && !b_ex)
            ret = ((b[idx_b] == c[idx_c]) ? this->_dp(a, b, c, memo, idx_a, idx_b + 1) : false);

        // If only b is exhausted, then check a
        else if(!a_ex && b_ex)
            ret = ((a[idx_a] == c[idx_c]) ? this->_dp(a, b, c, memo, idx_a + 1, idx_b) : false);

        else
        {
            bool a_choice = false;
            bool b_choice = false;

            if(a[idx_a] == c[idx_c])
                a_choice = this->_dp(a, b, c, memo, idx_a + 1, idx_b);

            if(b[idx_b] == c[idx_c])
                b_choice = this->_dp(a, b, c, memo, idx_a, idx_b + 1);

            ret = (a_choice || b_choice);
        }

        memo[key] = ret;
        return ret;
    }

public:
    bool isInterleave(std::string s1, std::string s2, std::string s3)
    {
        if(s1.size() + s2.size() != s3.size())
            return false;

        std::unordered_map<int, int> known;

        return this->_dp(s1, s2, s3, known);
    }
};