class Solution {
public:
    int maxArea(std::vector<int>& heights)
    {
        int i = 0;
        int j = static_cast<int>(heights.size() - 1);

        // int min_i_right, min_j_left;

        int ret = 0;
        int cur;

        while(i < j)
        {
            if((cur = (j - i) * std::min(heights[i], heights[j])) > ret)
                ret = cur;

            // min_i_right = std::min(heights[i + 1], heights[j]);
            // min_j_left  = std::min(heights[i], heights[j + 1]);

            if(heights[i] < heights[j])
                ++i;
            else
                --j;
        }

        return ret;
    }
};
