class Solution {
private:
    void _sumTwoPrevious(std::stack<int>& st)
    {
        int b = st.top(); st.pop();
        int a = st.top();
        int c = a + b;
        
        st.push(b);
        st.push(c);
    }

    inline void _invalidatePrevious(std::stack<int>& st)
    {
        st.pop();
    }

    inline void _doublePrevious(std::stack<int>& st)
    {
        st.push(2 * st.top());
    }

    inline void _addNum(std::stack<int>& st, const std::string& num)
    {
        st.push(std::stoi(num));
    }

    int _getSumFromStack(std::stack<int>& st)
    {
        int ret = 0;

        while(!st.empty())
        {
            ret += st.top();
            st.pop();
        }

        return ret;
    }

public:
    int calPoints(std::vector<std::string>& operations)
    {
        std::stack<int> st;

        for(std::string& op : operations)
        {
            if(op == "+")
                this->_sumTwoPrevious(st);
            else if(op == "C")
                this->_invalidatePrevious(st);
            else if(op == "D")
                this->_doublePrevious(st);
            else
                this->_addNum(st, op);
        }

        return this->_getSumFromStack(st);
    }
};