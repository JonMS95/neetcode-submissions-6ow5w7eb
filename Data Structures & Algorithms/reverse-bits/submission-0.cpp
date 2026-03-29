class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        // Set a given bit to 1: n |= (1 << i), where i is the position to be set (0 is the LSB's).
        // Example: set 5th bit (0-indexed):
        // n |= (1 << 5) -> n |= n  = n | 00100000

        // Set a given bit to 0: n &= ~(1 << i), where i is the position to be set (0 is the LSB's).
        // Example: clear 5-th bit (0-indexed):
        // n &= ~(1 << 5) -> n = n & ~(00100000) -> n = n & 11011111

        int lsb, msb;

        for(int i = 0; i < 16; i++)
        {
            lsb = n & (1 << i);
            msb = n & (1 << (32 - i - 1));

            if(lsb)
                n |= (1 << (32 - i - 1));
            else
                n &= ~(1 << (32 - i - 1));
            
            if(msb)
                n |= (1 << i);
            else
                n &= ~(1 << i);
        }

        return n;
    }
};
