/*
Key idea: use exponentiation rules to make computation faster.

3^6 == 3^(2 + 4) == 3^2 * 3^(2*2)

We can start with x^1 == x. Then, we can keep iterating by simply squaring previous
power. If it's bit it found, then simply multiply current power and add it.

Example: 5^7
7 == 0b111
ret = 1
5^1 = 5. 0th bit is found, then multiply ret by it: ret = ret * 0-th-power = 5
5^2 = previous-power (0-th-power) multiplied by x == 5 * 5. Again, 1st bit is found so
multiply: ret = ret * 1st power = 5 * 25 = 125
5^4: same as before. Current power (5^4) is equal to previous power squared. Then,
5^4 == 2nd power = 625. Again, bt found so: ret = ret * 625 = 78125.

No more set bits found. Therefore, return. Also, return the reciproque (1/ret) if
requested power turns out to be negative.
*/

class Solution
{
private:
    // Returns MSB's position (0-indexed).
    int _getHighestBitsIndex(const int n)
    {
        int ret = 0;

        for(int i = 0; i < sizeof(n) * 8; i++)
            if((1 << i) & n)
                ret = i;
        
        return ret;
    }

public:
    double myPow(double x, int n)
    {
        if(n == 0)
            return 1;
        
        const bool is_negative = n < 0 ? true : false;

        if(is_negative)
            n = -n;
        
        double cur_pow = 0.0;
        double ret = 1.0;

        for(int i = 0; i <= this->_getHighestBitsIndex(n); i++)
        {
            if(cur_pow == 0.0)
                cur_pow = x;
            else
                cur_pow *= cur_pow;
            
            if(n & (1 << i))
                ret *= cur_pow;
        }

        if(is_negative)
            ret = 1 / ret;
        
        return ret;
    }
};
