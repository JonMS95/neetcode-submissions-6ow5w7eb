class Solution {
private:
    int calculateLongestSequence(int n, std::unordered_set<int>& values)
    {
        int ret = 1;

        while(values.count(n + 1))
        {
            ++ret;
            ++n;
        }

        return ret;
    }

public:
    int longestConsecutive(vector<int>& nums)
    {
        // First, retrieve all elements as a set.
        std::unordered_set<int> my_set;
        
        int ret = 0;
        int cur;

        for(int n : nums)
            my_set.insert(n);
        
        // Now we have it as a set. It's time for us to iterate the vector
        // searching for a potential start (no (n - 1) found). If so, calculate
        // the length of the subsequence using the set.
        for(int n : nums)
            if((cur = this->calculateLongestSequence(n, my_set)) > ret)
                ret = cur;
        
        return ret;
    }
};
