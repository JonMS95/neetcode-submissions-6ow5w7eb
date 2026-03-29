class Solution {
private:
    std::unordered_map<int, int> _makeFrequencyMap(std::vector<int>& nums)
    {
        std::unordered_map<int, int> ret;

        for(int n : nums)
            ++ret[n];
        
        return ret;
    }

public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> freq_map = this->_makeFrequencyMap(nums);

        auto custom_comp = [](const std::pair<int, int>& a, const std::pair<int, int>& b) -> bool
        {
            return a.second < b.second;
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(custom_comp)> pq_max(custom_comp);

        for(std::pair<int, int> key_val_pair : freq_map)
            pq_max.push(key_val_pair);
        
        std::vector<int> ret;

        while(k > 0)
        {
            ret.emplace_back(pq_max.top().first);
            pq_max.pop();
            --k;
        }

        return ret;
    }
};
