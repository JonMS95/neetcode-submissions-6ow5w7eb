class Solution {
private:
    int _dp(std::stack<int>& st, const int target)
    {
        if(!st.size())
            if(!target)
                return 1;
            else
                return 0;

        int top = st.top();
        st.pop();

        int ret = _dp(st, target + top) + _dp(st, target - top);
        
        st.push(top);

        return ret;
    }

public:
    int findTargetSumWays(std::vector<int>& nums, int target)
    {
        std::stack<int> st;

        for(int n : nums)
            st.push(n);
        
        return _dp(st, target);
    }
};
