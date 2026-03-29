class Solution {
public:
    int findDuplicate(std::vector<int>& nums)
    {
        std::unordered_set<int> seen;

        for(int n : nums)
            if(seen.count(n))
                return n;
            else
                seen.insert(n);
        
        return -1;
    }
};
