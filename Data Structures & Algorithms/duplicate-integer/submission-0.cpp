class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        std::unordered_set<int> known_nums;

        for(int n : nums)
            if(known_nums.count(n))
                return true;
            else
                known_nums.insert(n);
        
        return false;
    }
};