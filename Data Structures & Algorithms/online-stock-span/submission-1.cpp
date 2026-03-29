/*
For each stock value, we have to first know which was the previous strictly greater value.
The aim is to return the time difference (in days) between current stock value and previous
strictly greater.

If we use a monotonic decreasing stack, we should keep removing every value while stack's
top is smaller or equal than current value.

Also, we must use a day counter so as to keep track of each day. Stack's elements will be
{stock value, date} pairs.
*/

class StockSpanner
{
    int day_;
    std::stack<std::pair<int, int>> svtd_; // Stock value to date

public:
    StockSpanner():day_(0){}
    
    int next(int price)
    {
        while(!this->svtd_.empty() && this->svtd_.top().first <= price)
            this->svtd_.pop();
        
        int ret, prev_date;

        if(this->svtd_.empty())
            prev_date = 0;
        else
            prev_date = this->svtd_.top().second;
        
        ret = this->day_ - prev_date + 1;

        // if(svtd_.empty())
        //     ret = 1;
        // else
        //     ret = this->day_ - svtd_.top().second + 1;
        
        this->day_++;

        this->svtd_.push({price, this->day_});

        return ret;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */