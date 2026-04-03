class MyQueue {
private:
    std::stack<int> st_;

    std::stack<int> _getReverseStack(std::stack<int>& st)
    {
        std::stack<int> ret;
        std::stack<int> aux = st;

        while(!aux.empty())
        {
            ret.push(aux.top());
            aux.pop();
        }

        return ret;
    }

public:
    MyQueue() {}
    
    void push(int x)
    {
        this->st_.push(x);
    }
    
    // Turn 1 2 3 into 3 2 1, store top (1) and pop it, then convert 3 2 into 2 3
    int pop()
    {
        std::stack<int> aux = this->_getReverseStack(this->st_);
        
        int ret = aux.top();
        aux.pop();
        
        this->st_ = this->_getReverseStack(aux);

        return ret;
    }
    
    int peek()
    {
        return this->_getReverseStack(this->st_).top();
    }
    
    bool empty()
    {
        return this->st_.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */