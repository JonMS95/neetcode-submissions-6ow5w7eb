class Solution {
public:
    int maxArea(std::vector<int>& heights)
    {
        int i = 0;
        int j = static_cast<int>(heights.size() - 1);

        int ret = 0;
        int cur;

        while(i < j)
        {
            if((cur = (j - i) * std::min(heights[i], heights[j])) > ret)
                ret = cur;

            // The aim is shrink the window from the side in which height is smaller.
            // We should always aim towards maximizing (or try, at least) the minumum
            // among both heights.
            if(heights[i] < heights[j])
                ++i;
            else
                --j;
        }

        return ret;
    }
};
