class Solution {
private:
    using vec_int = std::vector<int>;
    using u_map_int_int = std::unordered_map<int, int>;
    using u_set_int = std::unordered_set<int>;

    u_map_int_int makeHistFromIntegersVector(vec_int& nums)
    {
        u_map_int_int ret;

        for(int n : nums)
            ++ret[n];
        
        return ret;
    }

    vec_int getVectorWithUniqueValues(vec_int& vec)
    {
        vec_int ret;

        u_set_int known_values;

        for(int n : vec)
        {
            if(!known_values.count(n))
            {
                ret.emplace_back(n);
                known_values.insert(n);
            }
        }

        return ret;
    }

public:
    vec_int topKFrequent(vec_int& nums, int k)
    {
        u_map_int_int hist = this->makeHistFromIntegersVector(nums);

        vec_int unique_values = this->getVectorWithUniqueValues(nums);

        auto sort_crit = [&](const int a, const int b) -> bool
        {
            return hist[a] > hist[b];
        };

        std::sort(unique_values.begin(), unique_values.end(), sort_crit);

        return vec_int(unique_values.begin(), unique_values.begin() + k);
    }
};
