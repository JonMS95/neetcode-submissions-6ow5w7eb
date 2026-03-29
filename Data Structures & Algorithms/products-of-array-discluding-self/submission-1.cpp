class Solution {
private:
    using vec_int = std::vector<int>;

/*
i = 0 -> _ * 2 * 4 * 6 == left[0] * right[0] == 1 * 48
i = 1 -> 7 * _ * 4 * 6 == left[1] * right[1] == 7 * 24
i = 2 -> 7 * 2 * _ * 6 == left[2] * right[2] == 2 * 6
i = 3 -> 7 * 2 * 4 * _ == left[3] * right[3] == 8 * 1
*/

    vec_int getPrefixes(vec_int& nums)
    {        
        int pref = 1;
        vec_int ret;

        for(int i = 0; i < static_cast<int>(nums.size()); i++)
        {
            ret.emplace_back(pref);
            pref *= nums[i];
        }

        return ret;
    }

    vec_int getSuffixes(vec_int& nums)
    {
        int suff = 1;
        vec_int ret(static_cast<int>(nums.size()));

        for(int i = static_cast<int>(nums.size() - 1); i >= 0; i--)
        {
            ret[i] = suff;
            suff *= nums[i];
        }

        return ret;
    }

public:
    vec_int productExceptSelf(vec_int& nums)
    {
        vec_int pref = this->getPrefixes(nums);
        vec_int suff = this->getSuffixes(nums);

        vec_int ret(static_cast<int>(nums.size()));

        for(int i = 0; i < static_cast<int>(nums.size()); i++)
            ret[i] = pref[i] * suff[i];

        return ret;
    }
};
