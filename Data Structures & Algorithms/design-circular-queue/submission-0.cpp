class MyCircularQueue {
    int l_, s_;
    std::vector<int> q_;

public:
    MyCircularQueue(int k): l_(0), s_(0), q_(std::vector<int>(k)) {}
    
    bool enQueue(int value)
    {
        const int q_size = static_cast<int>(this->q_.size());

        if(this->s_ >= q_size)
            return false;
        
        int idx = (this->l_ + this->s_) % q_size;

        this->q_[idx] = value;
        ++this->s_;

        return true;
    }
    
    bool deQueue()
    {
        const int q_size = static_cast<int>(this->q_.size());

        if(!this->s_)
            return false;
        
        this->l_ = (this->l_ + 1) % q_size;
        if(this->s_)
            --this->s_;

        return true;
    }
    
    int Front()
    {
        if(!this->s_)
            return -1;
        
        return this->q_[this->l_];
    }
    
    int Rear()
    {
        if(!this->s_)
            return -1;
        
        int idx = (this->s_ + this->l_ - 1) % static_cast<int>(this->q_.size());

        return this->q_[idx];
    }
    
    bool isEmpty()
    {
        return !this->s_;
    }
    
    bool isFull()
    {
        return (this->s_ == static_cast<int>(this->q_.size()));
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */