/*
It's gets a bit scary when you come across that "Each function should run in O(1) time".
However, it's easier than what it may seen at first sight. We should use two stacks.
·One of the stacks is mandatory: it will simply contain pushed elements.
·Another stack is what will make our code actually fast. It will store the "minimum
element so far".

Our way to proceed will be the following:
·Push an element into the stack.
·If the pushed element is smaller than current element, then push the current element to
the top of the stack. Otherwise, puh the top again onto the stack.
·When popping, pop from both.
·When getting the top or the minimum, retrieve the top of either numbers stack or the
minimum elements stack.

Example describing how min stack behaves (the way  numbers stack behaves is pretty clear):
push(1): push to min stack since it's empty.
push(2): current element is greater than stock top (minimum element so far), hence, push
current top again to the min stack.
push(0): stack top is greater than current element, so push it to the min stack.
*/

class MinStack
{
private:
    std::stack<int> nums_;
    std::stack<int> mins_;

public:
    MinStack(){}
    
    void push(int val)
    {
        nums_.push(val);

        if(mins_.empty())
        {
            mins_.push(val);
            return;
        }

        if(mins_.top() < val)
        {
            mins_.push(mins_.top());
            return;
        }
        
        mins_.push(val);
    }
    
    void pop()
    {
        nums_.pop();
        mins_.pop();
    }
    
    int top()
    {
        return nums_.top();
    }
    
    int getMin()
    {
        return mins_.top();
    }
};
