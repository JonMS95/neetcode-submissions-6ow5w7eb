/*
Let's start by assuming the vector does not contain zeros.

A vector can have an even or odd number of negative numbers. If even (or zero) then the maximum
product comprehends the whole vector. If odd, instead, we must drop either the "head" or the "tail"
of the vector. "Head" refers to the elements until the first negative numbers (inclusive), "Tail"
refers to the elements from the last negative and onwards.

Example (even negatives):

[1, 4, 2, -5, 1, -3, 9] -> the whole array leads to a positive sum.

Example (odd negatives):

[2, -3, 4, -5, 7, -9, 1] -> Choose between the biggest product between [2, -3, 4, -5, 7] and [4, -5, 7, -9, 1]

Also, if size is 1, there's no choice but to return the unique element in the vector (this way, a unique
negative element can actualy establish a maximum).

Note that if size > 1, then there are three possible outcomes:
{negative, positive}
{negative, negative}
{positive, positive}
{positive, negative}

Either way, we can establish ret as 0 since any choice would update it with a greater number afterwards.
*/

class Solution
{
private:
    std::pair<std::vector<int>, std::vector<int>> _getSuffixAndPrefixProducts(const std::vector<int>& nums)
    {
        std::vector<int> prefix(nums.size());
        std::vector<int> suffix(nums.size());

        // Running product forward / backwards.
        int rpf = 1;
        int rpb = 1;

        const int nums_size = static_cast<int>(nums.size());

        for(int i = 0; i < nums_size; i++)
        {
            rpf *= nums[i];
            rpb *= nums[nums_size - i - 1];

            prefix[i] = rpf;
            suffix[nums_size - i - 1] = rpb;
        }

        return {prefix, suffix};
    }

    // Returns boundary negative values. If none, -1.
    // {-1, -1} for no negatives, {n, -1} for a single negative, {m, n} for two negatives.
    std::vector<int> _getNegNumIdx(const std::vector<int>& nums)
    {
        std::vector<int> ret;

        for(int i = 0; i < static_cast<int>(nums.size()); i++)
            if(nums[i] < 0)
                ret.emplace_back(i);
        
        return ret;
    }

    int _getMaxProduct(const std::vector<int>& nums)
    {
        if(nums.size() == 1)
            return nums[0];

        std::vector<int> neg_idx = this->_getNegNumIdx(nums);

        if(!neg_idx.size() || !(neg_idx.size() % 2))
            return this->_getSuffixAndPrefixProducts(nums).second[0];

        std::pair<std::vector<int>, std::vector<int>> prefix_and_suffix = this->_getSuffixAndPrefixProducts(nums);

        std::vector<int> prefix = prefix_and_suffix.first;
        std::vector<int> suffix = prefix_and_suffix.second;
        
        return std::max(suffix[0] / prefix[neg_idx[0]], suffix[0] / suffix[neg_idx[neg_idx.size() - 1]]);
    }

    std::vector<std::vector<int>> _getNonZeroIncludingVectors(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> ret;
        nums.emplace_back(0);
        std::vector<int> aux;

        for(int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            if(!nums[i])
            {
                if(aux.size())
                    ret.emplace_back(aux);
                
                aux.clear();
            }
            else
            {
                aux.emplace_back(nums[i]);
            }
        }

        nums.pop_back();

        return ret;
    }

public:
    int maxProduct(std::vector<int>& nums)
    {
        if(nums.size() == 1)
            return nums[0];

        std::vector<std::vector<int>> vectors = this->_getNonZeroIncludingVectors(nums);
        
        int ret = 0;
        int cur;

        for(std::vector<int>& vec : vectors)
            if((cur = this->_getMaxProduct(vec)) > ret)
                ret = cur;
        
        return ret;
    }
};
