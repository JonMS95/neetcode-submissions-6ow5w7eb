class Solution {
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;
    using pair_pt_dist = std::pair<vec_int, int>;
    using vec_pt_dist = std::vector<pair_pt_dist>;

    // Get squared distance from point.
    inline int _getSqDistFromPt(const vec_int& pt_coords)
    {
        return std::pow(pt_coords[0], 2) + std::pow(pt_coords[1], 2);
    }

public:
    mat_int kClosest(mat_int& points, int k)
    {
        vec_pt_dist points_to_distances;

        for(vec_int pt : points)
            points_to_distances.push_back({pt, this->_getSqDistFromPt(pt)});

        auto heap_crit = [](const pair_pt_dist& a, const pair_pt_dist& b) -> bool
        {
            return (a.second > b.second);
        };

        std::priority_queue<pair_pt_dist, vec_pt_dist, decltype(heap_crit)> min_dist_heap(points_to_distances.begin(), points_to_distances.end(), heap_crit);

        mat_int ret(k);

        for(int i = 0; i < k; i++)
        {
            ret[i] = min_dist_heap.top().first;
            min_dist_heap.pop();
        }

        return ret;
    }
};
