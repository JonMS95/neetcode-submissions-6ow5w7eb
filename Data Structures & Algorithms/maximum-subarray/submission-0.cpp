class Solution {
public:
    int maxSubArray(std::vector<int>& nums)
    {
        /*
        Core idea: for each element, calculate the running sum. If it turns out to be negative,
        there's no way it can be the greatest unless the vector itself is full of negative
        numbers.

        Algorithm:
        max = MIN_INT
        For each element (e):
            rs += e
            if rs > max
                max = rs
            if rs < 0
                rs = 0
        */

        int ret = INT_MIN;
        int rs = 0;

        for(int n : nums)
        {
            rs += n;
            
            if(rs > ret)
                ret = rs;
            
            if(rs < 0)
                rs = 0;
        }

        return ret;
    }
};
