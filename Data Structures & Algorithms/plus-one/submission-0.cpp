class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int carry = 1;
        int sum = 0;

        for(int i = static_cast<int>(digits.size() - 1); i >= 0; i--)
        {
            sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        if(carry)
            digits.insert(digits.begin(), carry);
        
        return digits;
    }
};
