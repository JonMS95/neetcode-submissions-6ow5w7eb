class Solution {
private:
    const int bits_in_byte = 8;
public:
    int hammingWeight(uint32_t n)
    {
        int ret = 0;

        for(int i = 0; i < (sizeof(n) * this->bits_in_byte); i++)
            if((1 << i) & n)
                ++ret;
        
        return ret;
    }
};
