class MedianFinder {
private:
    using vec_int = std::vector<int>;
    using pq_max = std::priority_queue<int, vec_int, std::less<int>>;
    using pq_min = std::priority_queue<int, vec_int, std::greater<int>>;

    pq_max smaller_elems_;
    pq_min greater_elems_;

public:
    MedianFinder() {}
    
    void addNum(int num)
    {
        this->smaller_elems_.push(num);
        this->greater_elems_.push(this->smaller_elems_.top());
        this->smaller_elems_.pop();

        // Rebalance so as not to let greater element's heap gro uncontrollably.
        if(this->greater_elems_.size() > this->smaller_elems_.size())
        {
            this->smaller_elems_.push(this->greater_elems_.top());
            this->greater_elems_.pop();
        }
    }
    
    double findMedian(void)
    {
        if(this->smaller_elems_.size() > this->greater_elems_.size())
            return static_cast<double>(this->smaller_elems_.top());
        
        return (static_cast<double>(this->smaller_elems_.top() + this->greater_elems_.top()) / 2.0);
    }
};
