class Solution {
private:
    std::queue<int> _enqueueFigures(int x)
    {
        std::queue<int> q;

        while(x > 0)
        {
            q.push(x % 10);
            x /= 10;
        }

        return q;
    }

public:
    int reverse(int x)
    {
        bool is_negative = x < 0 ? true : false;

        if(is_negative)
            x = -x;

        std::queue<int> q = this->_enqueueFigures(x);

        int ret = 0;

        while(!q.empty())
        {
            if(ret > (INT_MAX / 10))
                return 0;
            
            ret = ret * 10 + q.front();

            q.pop();
        }

        if(is_negative)
            ret = -ret;

        return ret;
    }
};
