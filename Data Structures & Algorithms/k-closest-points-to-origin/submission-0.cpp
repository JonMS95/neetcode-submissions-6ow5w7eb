class Solution {
private:
    using vec_int = std::vector<int>;
    using mat_int = std::vector<vec_int>;
    using pair_pt_dist = std::pair<vec_int, int>;
    using vec_pt_dist = std::vector<pair_pt_dist>;

public:
    mat_int kClosest(mat_int& points, int k)
    {
        vec_pt_dist points_to_distance;

        for(vec_int point : points)
            points_to_distance.push_back({point, (std::pow(point[0], 2) + std::pow(point[1], 2))});
        
        auto sort_crit = [](const pair_pt_dist& a, const pair_pt_dist& b) -> bool
        {
            return (a.second < b.second);
        };

        std:sort(points_to_distance.begin(), points_to_distance.end(), sort_crit);

        mat_int ret;

        for(int i = 0; i < k; i++)
            ret.emplace_back(points_to_distance[i].first);
        
        return ret;
    }
};
