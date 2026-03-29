class Solution {
private:
    inline bool sum(const bool a, const bool b, const bool c)
    {
        return (a^b^c);
    }

    inline bool car(const bool a, const bool b, const bool c)
    {
        return (a && b) || (a && c) || (b && c);
    }

public:
    int getSum(int a, int b)
    {
        int idx = 0;
        int ret = 0;

        bool x, y, c = false;

        for(int idx = 0; idx < 32; idx++)
        {
            x = (a & (1 << idx)) ? true : false;
            y = (b & (1 << idx)) ? true : false;
            ret |= (this->sum(x, y, c) << idx);
            c = this->car(x, y, c);
        }

        return ret;
    }
};
