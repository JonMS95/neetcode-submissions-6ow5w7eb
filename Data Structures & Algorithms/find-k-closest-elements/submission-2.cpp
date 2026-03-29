class Solution {
private:
    using vec_int = std::vector<int>;
    using val_dst = std::pair<int, int>;
    using vec_val_dst = std::vector<val_dst>;

public:
    vec_int findClosestElements(vec_int& arr, int k, int x)
    {
        const int arr_size = static_cast<int>(arr.size());
        
        vec_val_dst values_and_distances(arr_size);

        for(int i = 0; i < arr_size; i++)
            values_and_distances[i] = {arr[i], std::abs(arr[i] - x)};

        auto sort_crit = [](const val_dst& a, const val_dst& b) -> bool
        {
            if(a.second != b.second)
                return a.second < b.second;   // smaller distance first
            return a.first < b.first;
        };

        std::sort(values_and_distances.begin(), values_and_distances.end(), sort_crit);

        vec_int ret(k);

        for(int i = 0; i < k; i++)
            ret[i] = values_and_distances[i].first;
        
        std::sort(ret.begin(), ret.end());
        
        return ret;
    }
};