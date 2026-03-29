class KthLargest {
private:
    // By default, equal to: std::priority_queue<int, std::vector<int>, std::less<int>>
    std::priority_queue<int> max_heap_;
    const int k_val_;

public:
    KthLargest(int k, std::vector<int>& nums): k_val_(k)
    {
        this->max_heap_ = std::priority_queue<int>(nums.begin(), nums.end());
    }
    
    int add(int val)
    {
        std::stack<int> st;
        int ret;

        this->max_heap_.push(val);

        for(int i = 0; i < this->k_val_; i++)
        {
            st.push(this->max_heap_.top());
            this->max_heap_.pop();
        }

        ret = st.top();

        while(!st.empty())
        {
            this->max_heap_.push(st.top());
            st.pop();
        }

        return ret;
    }
};
