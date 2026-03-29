class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        // While current price is higher than current minimum, keep widening the window.
        // Each time the condition above is met, check whether current profit (cur - min)
        // is maximized or not.
        // Else (current value is lower than minimum), set a new minimum and do no more (just
        // go ahead).

        int min = 1000;
        int cur_diff;
        int ret = 0;

        for(int i = 0; i < static_cast<int>(prices.size()); i++)
        {
            if(prices[i] < min)
                min = prices[i];
            else
                if((cur_diff = prices[i] - min) > ret)
                    ret = cur_diff;
        }

        return ret;
    }
};
