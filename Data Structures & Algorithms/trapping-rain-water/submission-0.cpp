class Solution {
public:
    int trap(std::vector<int>& height)
    {
        if(height.size() <= 2)
            return 0;

        const int height_size = static_cast<int>(height.size());

        int ret = 0;
        std::vector<std::pair<int, int>> max_l_r(height_size);

        max_l_r[0].first = height[0];
        max_l_r[height_size - 1].second = height[height_size - 1];
    
        for(int i = 1; i < height_size; i++)
        {
            max_l_r[i].first = std::max(max_l_r[i - 1].first, height[i]);
            max_l_r[height_size - i - 1].second = std::max(max_l_r[height_size - i].second, height[height_size - i - 1]);
        }            

        for(int i = 1; i < (height_size - 1); i++)
            ret += (std::min(max_l_r[i].first, max_l_r[i].second) - height[i]);
        
        return ret;
    }
};
