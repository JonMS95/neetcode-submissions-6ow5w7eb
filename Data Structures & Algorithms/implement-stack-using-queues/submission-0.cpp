class MyStack
{
private:
    std::queue<int> q_;

public:
    MyStack() {}
    
    void push(int x)
    {
        q_.push(x);
    }
    
    int pop()
    {
        const int q_size = static_cast<int>(this->q_.size());

        for(int i = 0; i < (q_size - 1); i++)
        {
            this->q_.push(this->q_.front());
            this->q_.pop();
        }

        int ret = this->q_.front();
        this->q_.pop();

        return ret;
    }
    
    int top()
    {
        std::queue<int> aux = this->q_;

        while(aux.size() > 1)
            aux.pop();
        
        return aux.front();
    }
    
    bool empty()
    {
        return this->q_.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */