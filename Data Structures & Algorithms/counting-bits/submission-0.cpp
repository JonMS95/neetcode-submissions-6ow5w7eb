class Solution {
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> ret;

        for(int i = 0; i <= n; i++)
            ret.emplace_back(__builtin_popcount(i));
        
        return ret;
    }
};
