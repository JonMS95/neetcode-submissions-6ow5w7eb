class Solution {
private:
    std::unordered_map<int, int> _makeHist(const std::vector<int>& nums)
    {
        std::unordered_map<int, int> ret;

        for(int n : nums)
            ++ret[n];
        
        return ret;
    }

    std::vector<int> _getMostFrequentElements(std::unordered_map<int, int>& hist, const int size_min)
    {
        std::vector<int> ret;

        for(std::unordered_map<int, int>::iterator it = hist.begin(); it!= hist.end(); it++)
            if(it->second > size_min)
                ret.emplace_back(it->first);
    
        return ret;
    }

public:
    std::vector<int> majorityElement(std::vector<int>& nums)
    {
        std::unordered_map<int, int> hist = this->_makeHist(nums);

        return this->_getMostFrequentElements(hist, static_cast<int>(nums.size() / 3));
    }
};